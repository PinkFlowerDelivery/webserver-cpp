#pragma once

#include <string>
#include <unordered_map>
#include <vector>
class HttpRequest
{
    std::vector<char>                            startLine;
    std::unordered_map<std::string, std::string> headers;
    std::vector<char>                            body;

  public:
    HttpRequest();
};

class ParseHttp
{
  public:
    HttpRequest parse(std::vector<char> buffer);
};
