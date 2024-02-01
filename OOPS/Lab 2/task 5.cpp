#include <iostream>
using namespace std;

struct product {
    int id;
    string name;
    int price;
    int quantity;
};

void addproduct(){

}

void display(product prod[]){
    
}

void update(){

}

int main(){
    const int n = 100, ans;
    product prod[100];

    bool cont = true;

    while(cont){
        cout << "to add product enter 1" << endl;
        cout << "to display product information enter 2" << endl;
        cout << "to update product information enter 3" << endl;
        cin >> ans;
        switch (ans)
        {
        case 1:
            addproduct();
            break;
        case 2:
            display();
            break;
        case 3:
            update();
            break;
        default:
            break;
        }
    }
}
