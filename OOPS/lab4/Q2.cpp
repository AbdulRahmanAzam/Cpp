#include <iostream>
using namespace std;

class Book {
    private:
    string name;
    string author;
    int ISBN_number;
    int total_page_count;
    int number_of_pages = 0;

    public:
    // constructor
    Book(void){
        total_page_count = 1000;
        number_of_pages = 0;
    }
    Book(string name, string author, int ISBN_number, int total_page_count) :
    name(name),
    author(author), 
    ISBN_number(ISBN_number), 
    total_page_count(total_page_count){}

    // setter
    void setname(string name){
        this->name = name;
    }
    void setauthor(string author){
        this->author = author;
    }
    void setisbn(int ISBN_number){
        this->ISBN_number = ISBN_number;
    }
    void settotal_pages_count(int total_pages_count){
        this->total_page_count = total_page_count;
    }
    void setnumber_of_pages(int number_of_pages){
        this->number_of_pages = number_of_pages;
    }

    //getter
    string getname(){
        return this->name;
    }
    string getauthor(){
        return this->author;
    }
    int getisbn(){
        return this->ISBN_number;
    }
    int gettotal_page_count(){
        return total_page_count;
    }
    int getnumber_of_pages(){
        return number_of_pages;
    }


    //method
    void pages_read(int add_pages){
        number_of_pages += add_pages;

        if(total_page_count <= number_of_pages){
            cout << "You have finished the book" << endl;
        }else{
            cout << "Total pages count " << number_of_pages << endl;
        }
    }

    void showBookInfo(){
        cout << "name of book " << name << endl;
        cout << "name of author " << author << endl;
        cout << "ISBN number " << ISBN_number << endl;
        cout << "total page count of the book " << total_page_count << endl;
    }  

};


int main(){
    Book b1("HOW TO CPP", "Abdul Rahman Azam", 123, 800);

    b1.pages_read(500);
    b1.setauthor("Muhammad Azam");
    b1.setname("Data Structure");
    

    cout << b1.getauthor() << endl;

    b1.showBookInfo();
}
