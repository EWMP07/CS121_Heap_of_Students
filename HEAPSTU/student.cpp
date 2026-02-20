#include <iostream>
#include <sstream>
#include <vector>
#include "student.h"

Student::Student() {
    firstName = "";
    lastName = "";
    creditHours = 0;
}

void Student::init(std::string csvLine) {
    std::stringstream ss(csvLine);
    std::string temp;
    std::vector<std::string> fields;

    // Split CSV by commas
    while (getline(ss, temp, ',')) {
        fields.push_back(temp);
    }

    // Assign fields
    firstName = fields[0];
    lastName  = fields[1];

    std::string street = fields[2];
    std::string city   = fields[3];
    std::string state  = fields[4];
    std::string zip    = fields[5];

    std::string birth  = fields[6];
    std::string grad   = fields[7];

    creditHours = std::stoi(fields[8]);

    // Initialize composed objects
    address.init(street, city, state, zip);
    birthDate.init(birth);
    gradDate.init(grad);
}

void Student::printStudent() const {
    std::cout << firstName << " " << lastName << std::endl;
    address.printAddress();
    std::cout << "DOB: ";
    birthDate.printDate();
    std::cout << "Grad: ";
    gradDate.printDate();
    std::cout << "Credits: " << creditHours << std::endl;
    std::cout << "____________________________________" << std::endl;
}

std::string Student::getLastFirst() const {
    return lastName + ", " + firstName;
}