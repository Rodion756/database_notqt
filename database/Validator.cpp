#define _CRT_SECURE_NO_WARNINGS

#include "Validator.h"
#include <regex>
#include <ctime>
#include <cstdio>

std::string Validator::trim(const std::string& s) {
    auto start = s.find_first_not_of(" \t");
    auto end = s.find_last_not_of(" \t");
    return (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

bool Validator::name(const std::string& value) {
    static const std::regex r(
        R"(^[A-Za-zÀ-ßà-ÿ¨¸][A-Za-zÀ-ßà-ÿ¨¸0-9 -]*[A-Za-zÀ-ßà-ÿ¨¸0-9]$)"
    );
    return std::regex_match(value, r);
}

bool Validator::email(const std::string& value) {
    static const std::regex r(
        R"(^[A-Za-z0-9]+@[A-Za-z0-9]+\.[A-Za-z]{2,}$)"
    );
    return std::regex_match(value, r);
}

bool Validator::phone(const std::string& value) {
    static const std::regex r(
        R"(^(\+7|8)\(?\d{3}\)?\d{3}(-?\d{2}){2}$)"
    );
    return std::regex_match(value, r);
}

bool Validator::birthDate(const std::string& value) {
    static const std::regex r(R"(^\d{4}-\d{2}-\d{2}$)");
    if (!std::regex_match(value, r))
        return false;

    int y, m, d;
    sscanf(value.c_str(), "%d-%d-%d", &y, &m, &d);

    if (m < 1 || m > 12 || d < 1) return false;

    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    bool leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    if (leap) daysInMonth[1] = 29;

    if (d > daysInMonth[m - 1]) return false;

    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    if (y > now->tm_year + 1900) return false;

    return true;
}
