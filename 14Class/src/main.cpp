#include <iostream>

#include "Student.hpp"


int main() {

    int age, standard;
    std::string first_name, last_name;

    std::cin >> age >> first_name >> last_name >> standard;

    Student std;

    std.set_age(age);
    std.set_first_name(first_name);
    std.set_last_name(last_name);
    std.set_standard(standard);

    std::cout
        << std.get_age() << std::endl
        << std.get_last_name() << ", " << std.get_first_name() << std::endl
        << std.get_standard() << std::endl << std::endl
        << std.to_string();

    return 0;
}
