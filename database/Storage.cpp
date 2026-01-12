#include "Storage.h"
#include <fstream>

std::vector<Contact> Storage::load(const std::string& file) {
    std::vector<Contact> result;
    std::ifstream in(file);
    std::string line;
    while (std::getline(in, line)) {
        if (!line.empty())
            result.push_back(Contact::deserialize(line));
    }
    return result;
}

void Storage::save(const std::string& file, const std::vector<Contact>& contacts) {
    std::ofstream out(file);
    for (const auto& c : contacts) {
        out << c.serialize() << "\n";
    }
}
