/*
 * Student.hpp
 *
 *  Created on: 28 Jul 2022
 *      Author: david
 */

#ifndef SRC_STUDENT_HPP_
#define SRC_STUDENT_HPP_

#include <string>

class Student {
    int age;
    std::string first_name;
    std::string last_name;
    int standard;

public:

    int get_age();
    void set_age(int);

    std::string get_first_name();
    void set_first_name(std::string);

    std::string get_last_name();
    void set_last_name(std::string);

    int get_standard();
    void set_standard(int);

    std::string to_string();
};


#endif /* SRC_STUDENT_HPP_ */
