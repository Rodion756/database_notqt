#include "Contact.h"
#include <vector>
#include <string>

class Storage {
public:
    static std::vector<Contact> load(const std::string& file);
    static void save(const std::string& file, const std::vector<Contact>& contacts);
};
