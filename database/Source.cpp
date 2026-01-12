#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"
#include "Storage.h"
#include "Validator.h"

int main() {
    std::vector<Contact> contacts = Storage::load("contacts.txt");

    Contact c;
    std::cout << "Имя: ";
    std::getline(std::cin, c.firstName);
    c.firstName = Validator::trim(c.firstName);

    if (!Validator::name(c.firstName)) {
        std::cout << "Некорректное имя\n";
        return 1;
    }

    std::cout << "Фамилия: ";
    std::getline(std::cin, c.lastName);
    c.lastName = Validator::trim(c.lastName);

    std::cout << "Email: ";
    std::getline(std::cin, c.email);
    c.email = Validator::trim(c.email);

    if (!Validator::email(c.email)) {
        std::cout << "Некорректный email\n";
        return 1;
    }

    std::string phone;
    std::cout << "Телефон: ";
    std::getline(std::cin, phone);

    if (!Validator::phone(phone)) {
        std::cout << "Некорректный телефон\n";
        return 1;
    }

    c.phones.push_back(phone);

    contacts.push_back(c);
    Storage::save("contacts.txt", contacts);

    std::cout << "Контакт сохранён\n";
    return 0;
}
