// Abdul Rahman Azam 23k-0061
// 5/ 3/ 2024

#include <iostream>
#include <cstring>
using namespace std;

class engine{
    // private:
    public:
    char *ename;
    
    public:
    engine(const char *name){
        ename = new char[strlen(name) + 1];
        strcpy(ename, name);
    }
    
    ~engine(){
        cout << "Engine destructor is called" << endl;
    }
    
};
class wheels{
    // private:
    public:
    char *wname;
    
    public:
    wheels(const char *name){
        wname = new char[strlen(name) + 1];
        strcpy(wname, name);
    }
    ~wheels(){
        cout << "Wheels destructor is called" << endl;
    }
    
};
class headlights{
    // private:
    public:
    char *hname;
    
    public:
    headlights(const char* name){
        hname = new char[strlen(name) + 1];
        strcpy(hname, name);
    }
    ~headlights(){
        cout << "Headlights destructor is called" << endl;
    }
};

class steering{
    // private:
    public:
    char *sname;
    
    public:
    steering(const char* name){
        sname = new char[strlen(name) + 1];
        strcpy(sname, name);
    }
    ~steering(){
        cout << "Steering destructor is called" << endl;
    }
};
class car{
    private:
    char *carname;
    engine *eng;
    wheels *wheel;
    headlights *light;
    steering *steer;
    
    public:
    car(const char* name, engine* eng, wheels* wheel, headlights* light, steering* steer){
        carname = new char[strlen(name) + 1];
        strcpy(carname, name);
        
        this->eng = eng;
        this->wheel = wheel;
        this->light = light;
        this->steer = steer;
    }
    
    void display(){
        cout << "Engine = " << this->eng->ename 
        << "\nWheel = " << this->wheel->wname
        << "\nHeadLight = " << this->light->hname
        << "\nSteering = " << this->steer->sname << endl << endl;
    }
    
};

int main(){
    engine e1("2400cc");
    wheels w1("5strips");
    headlights h1("150Watt");
    steering s1("black shadoww");
    car car1("Mercedes", &e1, &w1, &h1, &s1); 
    
    car1.display();
}
