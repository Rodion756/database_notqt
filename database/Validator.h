#include <string>

namespace Validator {
    bool name(const std::string& value);
    bool email(const std::string& value);
    bool phone(const std::string& value);
    bool birthDate(const std::string& value);
    std::string trim(const std::string& s);
}
