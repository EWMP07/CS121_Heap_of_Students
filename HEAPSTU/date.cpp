#include <iostream>
#include <sstream>
#include "date.h"

Date::Date() {
    month = 0;
    day = 0;
    year = 0;
}

void Date::init(std::string dateString) {
    std::stringstream ss(dateString);
    std::string temp;

    // get month
    getline(ss, temp, '/');
    month = std::stoi(temp);

    // get day
    getline(ss, temp, '/');
    day = std::stoi(temp);

    // get year
    getline(ss, temp);
    year = std::stoi(temp);
}

void Date::printDate() const {
    std::string months[] = {
        "", "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    std::cout << months[month] << " "
              << day << ", "
              << year << std::endl;
}