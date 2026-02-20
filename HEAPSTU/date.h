#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date();  // null constructor

    void init(std::string dateString);
    void printDate() const;
};

#endif