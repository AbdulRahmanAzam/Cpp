// AGGREGATION
#include <iostream>
#include <cstring>
using namespace std;

class Employee{
    private:
    char* ename;
    
    public:
    // constructor
    Employee(const char* name){
        cout << "Employee made of name = " << name << endl;
        ename = new char[strlen(name)+1];
        strcpy(ename, name);
    }
    // destructor
    ~Employee(){
        cout << "Employee Object destroyed" << endl;
    }
    
    char* display(){
        return ename;
    }
};

class Company{
    private:
    char* cname;
    Employee* emp;
    
    public:
    // constructor
    Company(const char* compName, Employee* emp){
        cname = new char[strlen(compName)+1];
        strcpy(cname, compName);
        
        this->emp = emp;
    }
    // destructor
    ~Company(){
        cout << "Company object is destroyed" << endl;
    }
};

int main()
{
    {
        cout << "Here an Employee works" << endl;
        Employee emp("ABC");
        
        {
            Company comp("XYZ", &emp);
        }
        
        cout << "At this point Company gets deleted but Employee = " << emp.display() << " remains" << endl;
    }
}
