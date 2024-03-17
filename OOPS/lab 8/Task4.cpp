#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Person{
    public:
    string name;
    int age;
    
    Person(string name, int age) : name(name), age(age) {}
    
    void display(){
        cout << "name = " << name
        << "\nage = " << age << endl;
    }
};

class Student : virtual public Person{
    public:
    int studentID;
    int gradeLevel;
    
    Student(string name, int age, int studentID, int gradeLevel) : Person(name, age), studentID(studentID), gradeLevel(gradeLevel) {}
    
    void display(){
        cout << "studentID " << studentID
        << "\ngrade Level = " << gradeLevel << endl;
    }
};

class Teacher : virtual public Person{
    public:
    string subject;
    int room_number;
    
    Teacher(string name, int age, string subject, int room_number) : Person(name, age), subject(subject), room_number(room_number) {}
    
    void display(){
        cout << "subject = " << subject
        << "\nroom_number = " << room_number << endl;
    }
};

class GraduateStudent : public Teacher, public Student{
    public:
    GraduateStudent(string name, int age, int studentID, int gradeLevel, string subject, int room_number) : Person(name, age), Student(name, age, studentID, gradeLevel), Teacher(name, age, subject, room_number) {}
    
    void display(){
        Person::display();
        Student::display();
        Teacher::display();
    }
};

int main(){
    GraduateStudent g1("Abdul Rahman Azam", 19, 0061, 4, "OOP", 34);
    g1.display();
}
