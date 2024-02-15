#include <iostream>
using namespace std;

class Book {
    private:
    string name;
    string author;
    int ISBN_number;
    int total_page_count;

    public:
    int number_of_pages;

    // cosntructor
    Book(void){}
    Book(string name, string author, int ISBN_number, int total_page_count) : name(name), author(author), ISBN_number(ISBN_number), total_page_count(total_page_count){}

    //method
    void pages_read(int add_pages){
        number_of_pages += add_pages;
        
        if(total_page_count <= number_of_pages){
            cout << "You have finished the book" << endl;
        }else{
            cout << "Total pages count " << number_of_pages << endl;
        }
    }
};


int main(){
    Book b1("HOW TO CPP", "Abdul Rahman Azam", 123, 800);

    b1.pages_read(500);
}
