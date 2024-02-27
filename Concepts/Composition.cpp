// Composition
#include <iostream>
#include <cstring>
using namespace std;

class birthday{
    private:
    int day,
    month,
    year;
    
    public:
    // cosntructor
    birthday(int day = 0, int month = 0, int year = 0) : day(day), month(month), year(year) {
        cout << "birthdy constructor " << endl;
    }
    
    ~birthday(){
        cout << "birthday destrctor" << endl;
    }
    void setdate(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }
    
    void display(){
        cout << day << " / " << month << " / " << year << endl;
    }
};

class person{
    private:
    char* name;
    birthday obj;
    
    public:
    person(const char* name, int day = 0, int month = 0, int year = 0){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        obj.setdate(day,month,year);
        cout << "person constructor" << endl;
    }
    ~person(){
        cout << "person destroctir" << endl;
    }
    
    void display(){
        cout << "Name: " << name << endl;
        cout << "birthday: ";
        obj.display();
        cout << endl;
    }
};

int main(){
    person obj("Abdul Rahman Azam", 1, 12, 2004);
    obj.display();
    return 0;
}
