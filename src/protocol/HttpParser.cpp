#include "HttpParser.h"
#include "ParserUtils.h"
#include "nlohmann/json_fwd.hpp"

#include <fmt/base.h>
#include <nlohmann/json.hpp>
#include <sstream>
#include <string>

void Request::setMethod(Method method)
{
    this->method = method;
};

void Request::setPath(std::string& path)
{
    this->path = path;
};

void Request::setVersion(HttpVersion version)
{
    this->version = version;
};

void Request::addHeader(std::string& key, std::string& value)
{
    this->headers.insert({key, value});
};

Request ParseHttp::parse(std::string buffer)
{
    std::string line;
    std::istringstream rawDataStream(buffer);
    std::getline(rawDataStream, line, '\n');
    if (line.back() == '\r')
        line.pop_back();

    std::string method, path, version;

    std::istringstream startLineStream{line};
    startLineStream >> method >> path >> version;

    request.setMethod(ParseUtils::stringToMethod(method));
    request.setPath(path);
    request.setVersion(ParseUtils::stringToHttpVersion(version));

    while (true)
    {
        std::getline(rawDataStream, line);

        if (line.back() == '\r')
            line.pop_back();
        if (line.empty())
            break;

        ssize_t colonPos = line.find(':');
        if (colonPos == std::string::npos)
        {
            break;
        }
        std::string headerName = line.substr(0, colonPos);
        std::string headerValue =
            line.substr(colonPos + 2, line.size()); // start after ": " (colon + space)

        request.addHeader(headerName, headerValue);
    }

    line.clear();

    std::string body;
    while (true)
    {
        if (line.back() == '\r')
            line.pop_back();
        if (line.empty())
            break;

        std::getline(rawDataStream, line);
        body += line;
    }

    nlohmann::json jsonBody = nlohmann::json::parse(body);

    return request;
}
