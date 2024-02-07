#include <iostream>
using namespace std;

struct Register{
    int courseId;
    string courseName;
};

struct Student : Register {
    int studentId;
    string firstName;
    string lastName;
    int cellNo;
    string email;
};

void display(Student stud[5]){
    for(int i = 0; i< 2; i++){
        cout << "Details of " << i+1 << " student" << endl;
        cout << stud[i].courseId << endl;
        cout << stud[i].firstName << endl;
        cout << stud[i].lastName << endl;
        cout << stud[i].cellNo << endl;
        cout << stud[i].email  << endl << endl;
    }
}
void takeInput(Student stud[5]){
    for(int i = 0; i< 2; i++){
        cout << "Enter details of " << i+1 << " student";
        cout << "\nEnter student id" << endl;
        cin >> stud[i].courseId ;
        cout << "\nEnter first name" << endl;
        cin >> stud[i].firstName;
        cout << "\nEnter last name " << endl;
        cin >> stud[i].lastName;
        cout << "\nEnter cell No" << endl;
        cin >> stud[i].cellNo;
        cout << "\nEnter email" << endl;
        cin >> stud[i].email ;
        cout << endl << endl;
    }
}

int main(){
    Student stud[5];
    takeInput(stud);
    display(stud);
}
