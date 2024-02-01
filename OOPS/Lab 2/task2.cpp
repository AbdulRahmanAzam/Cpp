#include <iostream>
using namespace std;

struct book{
  string title;
  string author;
  int year;
  string genre;
  
};

void findd(book books[5], int n){
    cout << "Enter author or title of the book" << endl;
    string ans;
    cin >> ans;

    for(int i = 0; i < n; i++){
        if(books[i].author ==  ans || books[i].title == ans){
            cout << books[i].title << endl;
            cout << books[i].author << endl; 
            cout << books[i].year << endl; 
            cout << books[i].genre  << endl; 
            break;
        }
    }

}

int main(){
  book books[5];
  int n = 0;
  cout << "How many books you want to enter " << endl;
  cin >> n;
  
  int t = 1, yes = 0;
  while(t){
    for(int i = 0; i < n; i++){
        cout << "Enter details of book no: " << i + 1 << endl;
        cout << "Enter title of the book" << endl;
        cin >> books[i].title ;
        cout << "Enter author of the book" << endl;
        cin >> books[i].author;
        cout << "Enter year of publication of the book" << endl;
        cin >> books[i].year;
        cout << "Enter genre of the book" << endl;
        cin >> books[i].genre; 
    }
    cout << "To input more books then enter 1 otherwise enter 0" << endl << endl;

  }

    cout << "To find a book then enter 1" << endl;
    cin >> yes;
  if(yes){
    findd(books, n);
  }
}
