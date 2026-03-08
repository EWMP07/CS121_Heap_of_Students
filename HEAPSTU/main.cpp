#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "student.h"

using namespace std;

void loadStudents(vector<Student*>& students);
void printStudents(vector<Student*>& students);
void showStudentNames(vector<Student*>& students);
void findStudent(vector<Student*>& students);
void delStudents(vector<Student*>& students);
string menu();

int main(){

    vector<Student*> students;

    loadStudents(students);

    string choice;

    do{

        choice = menu();

        if(choice == "1"){
            showStudentNames(students);
        }
        else if(choice == "2"){
            printStudents(students);
        }
        else if(choice == "3"){
            findStudent(students);
        }

    }while(choice != "0");

    delStudents(students);

    return 0;
}

void loadStudents(vector<Student*>& students){

    ifstream file("students.csv");

    string line;

    while(getline(file, line)){

        Student* s = new Student(line);

        students.push_back(s);
    }

    file.close();
}

void printStudents(vector<Student*>& students){

    for(int i = 0; i < students.size(); i++){

        students[i]->printStudent();

        cout << "____________________________________" << endl;
    }
}

void showStudentNames(vector<Student*>& students){

    for(int i = 0; i < students.size(); i++){

        cout << students[i]->getLastName()
             << ", "
             << students[i]->getFirstName()
             << endl;
    }
}

void findStudent(vector<Student*>& students){

    string name;

    cout << "last name of student: ";
    cin >> name;

    for(int i = 0; i < students.size(); i++){

        if(students[i]->getLastName().find(name) != string::npos){

            students[i]->printStudent();

            cout << "____________________________________" << endl;
        }
    }
}

void delStudents(vector<Student*>& students){

    for(int i = 0; i < students.size(); i++){

        delete students[i];
    }
}

string menu(){

    string choice;

    cout << endl;
    cout << "0) quit" << endl;
    cout << "1) print all student names" << endl;
    cout << "2) print all student data" << endl;
    cout << "3) find a student" << endl;
    cout << endl;

    cout << "please choose 0-3: ";

    cin >> choice;

    return choice;
}