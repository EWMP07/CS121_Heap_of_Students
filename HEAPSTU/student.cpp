#include "student.h"
#include <sstream>
#include <iostream>

Student::Student(std::string line){

    std::stringstream ss(line);

    std::string street;
    std::string city;
    std::string state;
    std::string zip;
    std::string birth;
    std::string gradDate;
    std::string temp;

    getline(ss, lastName, ',');
    getline(ss, firstName, ',');

    getline(ss, street, ',');
    getline(ss, city, ',');
    getline(ss, state, ',');
    getline(ss, zip, ',');

    getline(ss, birth, ',');
    getline(ss, gradDate, ',');

    getline(ss, temp, ',');
    creditHours = stoi(temp);

    address = new Address();
    address->init(street, city, state, zip);

    dob = new Date();
    dob->init(birth);

    grad = new Date();
    grad->init(gradDate);
}

Student::~Student(){

    delete address;
    delete dob;
    delete grad;
}

std::string Student::getFirstName(){
    return firstName;
}

std::string Student::getLastName(){
    return lastName;
}

void Student::printStudent(){

    std::cout << firstName << " " << lastName << std::endl;

    address->printAddress();

    std::cout << "DOB: ";
    dob->printDate();

    std::cout << "Grad: ";
    grad->printDate();

    std::cout << "Credits: " << creditHours << std::endl;
}