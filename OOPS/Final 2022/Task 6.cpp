#include <iostream>
#include <string>
using namespace std;

class File{
    int size;
    string location;
    int date;
    int modified_date;

    public:

    virtual void open() = 0;
    virtual void print(){}

    friend bool isDuplicate(File* file_object_1, File* file_object_2);
};

class PDF : public File{
    public:
    void open(){
        cout << "PDF Open" << endl;
    }
    void print(){
        cout << "PDF" << endl;
    }
};

class ASCII : public File{
    public:
    void open(){
        cout << "ASCII Open" << endl;
    }
    void print(){
        cout << "ASCII" << endl;
    }
};

class PS : public File{
    public:
    void open(){
        cout << "PS Open" << endl;
    }
    void print(){
        cout << "PS" << endl;
    }  
};

bool isDuplicate(File* file_object_1, File* file_object_2){
    if(file_object_1->size == file_object_2->size && file_object_1->location == file_object_2->location){
        return true;
    }
    return false;
}

int main(){
    File* f1 = new PDF;
    File* f2 = new ASCII;
    File* f3 = new PS;

    PDF pdf;
    ASCII ascii;
    PS ps;

    f1->print();
    f2->print();
    f3->print();

    cout << "Are these files duplicate ? " <<  (isDuplicate(f1, f2) ? "true" : "false");

    delete f1;
    delete f2;
    delete f3;
}
