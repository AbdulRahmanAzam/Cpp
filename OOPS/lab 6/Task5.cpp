#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Course{
    public:
    string course_code;
    string name;
    int credit_hour;

};

class Student{
    public:
    string ID;
    string name;

    vector<Course> courses;

    Student(string ID, string name) : ID(ID), name(name){}

    void enroll(Course course){
        courses.push_back(course);
        cout << course.name << " is enrolled successfully" << endl; 
    }

    void drop(Course course){
        for(int i=0; i< courses.size(); i++){
            if(courses[i].name == course.name){
                courses.erase(courses.begin() + i);
                cout << course.name << " is dropped successfully" << endl;
                break;
            }
        }
    }

    int getTotalCreditHours(){
        int total = 0;

        for(Course x : courses){
            total += x.credit_hour;
        }
        return total;
    }

    void printEnrolledCourses(){
        for(int i=0; i< courses.size(); i++){
            cout << "Course code = " << courses[i].course_code 
            << "\nname = " << courses[i].name 
            << "\ncredit hours = " << courses[i].credit_hour << endl << endl;
        }
    }
};



int main(){
    Course c1,c2,c3;
    c1.name = "OOP";
    c1.credit_hour = 4;
    c1.course_code = "CS-1002";

    c2.name = "CAL";
    c2.course_code = "MT-4002";
    c2.credit_hour = 3;

    Student s1("123", "Abdul Rahman Azam");
    s1.enroll(c1);
    s1.enroll(c2);

    cout << "Total credit hours is = " << s1.getTotalCreditHours() << endl;
    s1.printEnrolledCourses();

    s1.drop(c2);

}
