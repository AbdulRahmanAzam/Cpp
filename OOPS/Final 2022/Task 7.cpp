// file is not opening
// i dont know what is the error, why F* Filing is not opening

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Laptops{
    int id;
    float price;
    int hdd;
    int ram;

    friend ostream& operator<<(ostream& os, const Laptops& laptop){
        os.write(reinterpret_cast<const char*>(&laptop), sizeof(Laptops));
        return os;
    }
    friend istream& operator>>(istream& is, Laptops& laptop){
        is.read(reinterpret_cast<char*>(&laptop), sizeof(Laptops));
        return is;
    }
};

class HP : public Laptops{
    int portsCount;
};

class Asus : public Laptops{
    float screenSize;
};

class Dell : public Laptops{
    int graphicsCardSize;
};

int main(){
    Laptops* l;

    HP hp;
    Asus asus;
    Dell dell;

    ofstream file;
    file.open("datafile.bin");
    if(!file){
        cout << "file error " << endl;
    }

    ifstream dataFile;
    dataFile.open("data.bin");
    if(!dataFile){
        cout << "Data file error " << endl;
    }

    while(dataFile >> hp >> asus >> dell){

        file << hp << asus << dell;
    }

    file.close();
    dataFile.close();
}
