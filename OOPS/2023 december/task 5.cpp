
#include <iostream>
#include <string>
using namespace std;

class Publication{
    string title;
    float price;

    public:
    Publication(string title, float price) : title(title), price(price) {}
    Publication(){}

    virtual string getdata(){
        return this->title;
    }

    void putdata(){
        cout << "Title: " << this->title
        << "\nPrice: " << this->price << endl;
    }
};

class Book : public Publication{
    int page_count;
    
    public:
    Book(string title, float price, int page_count)  : Publication(title, price), page_count(page_count){}
    string getdata() override{
        return Publication::getdata();
        // return this->page_count;
    }
    void putdata(){
        Publication::putdata();
        cout << "Page Count: " << this->page_count << endl;
    }
};

class Tape : public Publication{
    float playTime;

    public:
    Tape(string title, float price, int playTime) : Publication(title, price), playTime(playTime) {}
    string getdata() override {
        return Publication::getdata();
        // return this->playTime;
    }
    void putdata(){
        Publication::putdata();
        cout << "Play Time: " << this->playTime << endl;
    }

};


int main(){
    Publication* publications = new Publication[5];

    for(int i=0; i < 2; i++){
        string input;
        cout << "Enter the type of publication: book or tape" << endl;
        cin >> input;

        if(input == "book" || input == "Book"){
            string title;
            float price;
            int page_count;

            cout << "Enter title of the book" << endl;
            cin >> title;

            cout << "Enter the price of the book" << endl;
            cin >> price;
 
            cout << "Enter the page count of the book" << endl;
            cin >> page_count;

            Book book(title,price, page_count);
            publications[i] = book;
        }else if(input == "tape" || input == "Tape"){
            string title;
            float price;
            int playTime;

            cout << "Enter title of the Tape" << endl;
            cin >> title;

            cout << "Enter the price of the Tape" << endl;
            cin >> price;

            cout << "Enter the playTime of the Tape" << endl;
            cin >> playTime;

            publications[i] = Tape(title, price, playTime);
        }
    }

    for(int i = 0;i < 2; i++){
        publications[i].putdata();
    }

    delete[] publications;
    publications = nullptr;
}
