#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>

#include <appointy_time.h>
#include <price.h>

auto split(const std::string &str, char delim = '\n') -> std::vector<std::string>;
auto string_to_time(const std::string &str) -> appointy::Time;
auto string_to_price(const std::string &str) -> appointy::Price;

#endif // UTIL_H
