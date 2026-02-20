#include <iostream>
#include "date.h"
#include "address.h"
#include "student.h"

int main(){
  std::cout << "Hello!" << std::endl;

  Address a;
  a.init("123 W Main St", "Muncie", "IN", "47303");
  a.printAddress();

  Date d;
  d.init("01/27/1997");
  d.printDate();

  std::string studentString =
  "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";

  Student* student = new Student();
  student->init(studentString);
  student->printStudent();

  std::cout << std::endl;
  std::cout << student->getLastFirst();

  delete student;

  return 0;
}