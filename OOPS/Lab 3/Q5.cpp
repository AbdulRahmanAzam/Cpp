// Abdul Rahman Azam
// 23k-0061
// date: 9/feb/2024
#include <iostream>
using namespace std;

class stationary_shop {
    private:
    static const int n = 100;
    string items[n][1];
    int price[n] = {0};
    static const int f = 100;
    public:
    
    void addItem(string temp, int rs){
        static int a = 0;
        items[a][0] = temp;
        price[a] = rs;
        a++;
    }
    void removeItem(string temp){
        for(int i=0; i< f;i++){
            if(items[i][0] == temp){
                items[i][0] = "";
                price[i] = 0;
            }
        }
    }
    void modifyprice(string temp, int rs){
        int i=0;
        for(; i < f;i++){
            if(items[i][0] == temp){
                price[i] = rs;
                break;
            }
        }
        cout << "price of '" << items[i][0] << "' is updates succesfully" << endl << endl;
    }
    
    void display(){
        for(int i = 0; i< f; i++){
            if(price[i] != 0){
                cout << "Item = " << items[i][0] << "  price = " << price[i] << endl;
            }
        }
        cout << endl;
    }
    
};

int main(){
    stationary_shop item;
    stationary_shop ano;
    
    ano.addItem("check_check",20);
    ano.addItem("check",11);
    
    item.addItem("piyala", 100);
    item.addItem("chai", 200);
    item.addItem("4 CGPA",100);
    
    item.removeItem("chai");
    
    
    
    item.display();
    cout << endl;
    ano.display();
    
    item.modifyprice("piyala", 2000);
    item.display();
}
