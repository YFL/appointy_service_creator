#include <util.h>

#include <sstream>

#include <appointy_exception.h>

auto split(const std::string &str, char delim) -> std::vector<std::string>
{
    std::stringstream ss {str};
    std::string token;
    std::vector<std::string> substrs;
    while(std::getline(ss, token, delim))
    {
        substrs.push_back(token);
    }

    return substrs;
}

auto string_to_time(const std::string &str) -> appointy::Time
{
    auto parts = split(str, ':');
    if(parts.size() != 3)
    {
        throw appointy::Exception {"The string provided is of wrong format"};
    }

    return appointy::Time
    {
        std::stoi(parts[0]),
        std::stoi(parts[1]),
        std::stoi(parts[2])
    };
}

auto string_to_price(const std::string &str) -> appointy::Price
{
    auto parts = split(str, '.');
    if(parts.size() != 3)
    {
        parts = split(str, ',');
        if(parts.size() != 3)
        {
            throw appointy::Exception {"The string provided is of wrong format"};
        }
    }

    return appointy::Price
    {
        std::stoi(parts[0]),
        std::stoi(parts[1])
    };
}
