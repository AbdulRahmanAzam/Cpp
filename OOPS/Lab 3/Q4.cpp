// Abdul Rahman Azam
// 23k-0061
// date: 9/feb/2024
#include <iostream>
using namespace std;

class Smartphone {
    private:
    string brand;
    int model;
    int resolution;
    int ram;
    int rom;
    int storage;
    
    public:
    //setter
    void setbrand(string brand){this->brand = brand;}
    void setmodel(int model){this->model = model;}
    void setresolution(int resolution){this->resolution = resolution;}
    void setram(int ram){this->ram = ram;}
    void setrom(int rom){ this->rom = rom;}
    void setstorage(int storage){this->storage = storage;}
    
    //getter
    string getbrand(){return this->brand;}
    int getmodel(){return this->model;}
    int getresolution(){return this->resolution;}
    int getram(){return this->ram;}
    int getrom(){return this->rom;}
    int getstorage(){return this->storage;}
    
    //methods
    void call(){
        cout << "Phone call happening" << endl;
    }
    void sendmessage(){
        cout << "sending message" << endl;
    }
    void wifi(){
        cout << "connecting to wifi " << endl;
    }
    void internet(){
        cout << "Browsing to internet" << endl;
    }
};

int main(){
    Smartphone mob1;
    Smartphone mob2;
    
    mob1.setbrand("nokia");
    mob2.setbrand("samsung");
    
    mob1.setmodel(2012);
    mob1.setresolution(2000);
    mob1.setrom(16);
    mob1.setram(16);
    mob1.setstorage(500);
    
    mob2.setmodel(2008);
    mob2.setresolution(4000);
    mob2.setrom(16);
    mob2.setram(32);
    mob2.setstorage(1000);
    
    
    cout << "brand name = " << mob1.getbrand() << endl;
    cout << "Model = " << mob1.getmodel() << endl;
    cout << "Display Resolution = " <<  mob1.getresolution() << endl;
    cout << "ROM = " << mob1.getrom() << endl;
    cout << "RAM = " << mob1.getram() << endl;
    cout << "Storage = " << mob1.getstorage() << endl;
    
    cout << "\nbrand name = " << mob2.getbrand() << endl;
    cout << "Model = " << mob2.getmodel() << endl;
    cout << "Display Resolution = " <<  mob2.getresolution() << endl;
    cout << "ROM = " << mob2.getrom() << endl;
    cout << "RAM = " << mob2.getram() << endl;
    cout << "Storage = " << mob2.getstorage() << endl;
}
