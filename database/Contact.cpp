#include "Contact.h"
#include <sstream>

std::string Contact::serialize() const {
    std::ostringstream oss;
    oss << firstName << '|'
        << lastName << '|'
        << middleName << '|'
        << address << '|'
        << birthDate << '|'
        << email << '|';

    for (size_t i = 0; i < phones.size(); ++i) {
        oss << phones[i];
        if (i + 1 < phones.size())
            oss << ",";
    }
    return oss.str();
}

Contact Contact::deserialize(const std::string& line) {
    Contact c;
    std::stringstream ss(line);
    std::getline(ss, c.firstName, '|');
    std::getline(ss, c.lastName, '|');
    std::getline(ss, c.middleName, '|');
    std::getline(ss, c.address, '|');
    std::getline(ss, c.birthDate, '|');
    std::getline(ss, c.email, '|');

    std::string phoneBlock;
    std::getline(ss, phoneBlock);

    std::stringstream ps(phoneBlock);
    std::string phone;
    while (std::getline(ps, phone, ',')) {
        c.phones.push_back(phone);
    }
    return c;
}
