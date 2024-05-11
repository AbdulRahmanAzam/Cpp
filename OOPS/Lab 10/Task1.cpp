
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Logo{
    string logo;

    friend class Platform;
    public:
    Logo(string logo) : logo(logo) {}

    void setLogo(string logo){
        this->logo = logo;
    }
    void display(){
        cout << "Original Logo" << endl;
    }
};
class Platform{
    string name;
    Logo logo;

    public:
    Platform(string name, Logo logo) : name(name), logo(logo) {}

    void changeLogo(Logo newlogo){
        this->logo = newlogo.logo;
    }
    void display(){
        cout << "Platform name: " << name << endl;
        logo.display();
    }
};
class Server{
    string location;

public:
    Server(string location) : location(location) {}

    void display() {
        cout << "Server location: " << location << endl;
    }
};


int main(){
    Logo original_logo("Blue Bird");
    Platform twitter("Twitter", original_logo);

    original_logo.display();
    twitter.display();

    original_logo.setLogo("Doge Coin");
    twitter.changeLogo(original_logo);

    cout << endl;
    original_logo.display();
    twitter.display();
}
