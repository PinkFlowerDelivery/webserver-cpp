#pragma once

#include "HttpParser.h"
#include <string>

namespace ParseUtils
{
Method stringToMethod(std::string& stringMethod);
HttpVersion stringToHttpVersion(std::string& stringType);
} // namespace ParseUtils
