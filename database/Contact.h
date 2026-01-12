#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <vector>

class Contact {
public:
    std::string firstName;
    std::string lastName;
    std::string middleName;
    std::string address;
    std::string birthDate;
    std::string email;
    std::vector<std::string> phones;

    Contact() = default;
    std::string serialize() const;
    static Contact deserialize(const std::string& line);
};

#endif
