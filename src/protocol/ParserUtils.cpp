#include "ParserUtils.h"
#include "HttpParser.h"
#include <string>

Method ParseUtils::stringToMethod(std::string& stringMethod)
{
    if (stringMethod == "GET")
    {
        return Method::GET;
    }
    else if (stringMethod == "HEAD")
    {
        return Method::HEAD;
    }
    else if (stringMethod == "POST")
    {
        return Method::POST;
    }
    else if (stringMethod == "PUT")
    {
        return Method::PUT;
    }
    else if (stringMethod == "DELETE")
    {
        return Method::DELETE;
    }
    else if (stringMethod == "CONNECT")
    {
        return Method::CONNECT;
    }
    else if (stringMethod == "OPTIONS")
    {
        return Method::OPTIONS;
    }
    else if (stringMethod == "TRACE")
    {
        return Method::TRACE;
    }
    else if (stringMethod == "PATCH")
    {
        return Method::PATCH;
    }

    return Method::UNDEFINED;
};

HttpVersion ParseUtils::stringToHttpVersion(std::string& stringVersion)
{
    if (stringVersion == "HTTP/0.9")
    {
        return HttpVersion::V0_9;
    }
    else if (stringVersion == "HTTP/1.0")
    {
        return HttpVersion::V1_0;
    }
    else if (stringVersion == "HTTP/1.1")
    {
        return HttpVersion::V1_1;
    }
    else if (stringVersion == "HTTP/2")
    {
        return HttpVersion::V2;
    }
    else if (stringVersion == "HTTP/3")
    {
        return HttpVersion::V3;
    }
    else
    {
        return HttpVersion::UNDEFINED;
    }
}
