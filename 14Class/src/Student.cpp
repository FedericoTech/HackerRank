#include <sstream>

#include "Student.hpp"


int Student::get_age(){
    return age;
}

void Student::set_age(int age){
    this->age = age;
}

std::string Student::get_first_name(){
    return first_name;
}

void Student::set_first_name(std::string first_name){
    this->first_name = first_name;
}

std::string Student::get_last_name(){
    return last_name;
}

void Student::set_last_name(std::string last_name){
    this->last_name = last_name;
}

int Student::get_standard(){
    return standard;
}

void Student::set_standard(int standard){
    this->standard = standard;
}

std::string Student::to_string(){
	std::stringstream ss;

    ss
		<< age
		<< ',' << first_name
		<< ',' << last_name
		<< ',' << standard
		<< std::endl;

    return ss.str();
}

