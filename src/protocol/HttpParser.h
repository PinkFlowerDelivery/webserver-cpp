#pragma once

#include <cmath>
#include <string>
#include <unordered_map>

enum class Method
{
    GET,
    HEAD,
    POST,
    PUT,
    DELETE,
    CONNECT,
    OPTIONS,
    TRACE,
    PATCH,
    UNDEFINED
};

enum class HttpVersion
{
    V0_9,
    V1_0,
    V1_1,
    V2,
    V3,
    UNDEFINED,
};

class Request
{
    Method method;
    std::string path;
    HttpVersion version;
    std::unordered_map<std::string, std::string> headers;
    std::string body;

  public:
    void setMethod(Method method);
    void setPath(std::string& path);
    void setVersion(HttpVersion version);
    void addHeader(std::string& key, std::string& value);
};

class ParseHttp
{
    Request request;

  public:
    Request parse(std::string buffer);
};
