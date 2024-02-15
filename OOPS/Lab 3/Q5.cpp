// Abdul Rahman Azam
// 23k-0061
// date: 9/feb/2024
#include <iostream>
#include <string>
using namespace std;

class stationary_shop {
    private:
    static const int n = 100;
    string items[n];
    int price[n] = {0};

    public:
    
    void addItem(string temp, int rs){
        static int a = 0;
        items[a] = temp;
        price[a] = rs;
        a++;
    }
    void retrieveItem(string temp){
        for(int i=0; i< n;i++){
            if(items[i] == temp){
                items[i] = "";
                price[i] = 0;
            }
        }
    }
    void modifyprice(string temp, int rs){
        int i=0;
        for(; i < n;i++){
            if(items[i] == temp){
                price[i] = rs;
                break;
            }
        }
        cout << "price of '" << items[i] << "' is updates succesfully" << endl << endl;
    }
    
    void display(){
        for(int i = 0; i< n; i++){
            if(price[i] != 0){
                cout << "Item = " << items[i] << "  price = " << price[i] << endl;
            }
        }
        cout << endl;
    }
    void generatereciept(){
        
    }
    
};

int main(){
    stationary_shop s1;
    int n = 0;
    cout << "\nMenu:\n"
        << "1. Add Item\n"
        << "2. Retrieve Item List\n"
        << "3. Modify Item Price\n"
        << "4. Display Items with Prices\n"
        << "5. Generate Receipt\n"
        << "Enter your choice: ";
        cin >> n;
        
    while(n != 6){
        string temp;
        int price;

        switch(n){
        case 1:
        cout << "Enter name of the item " << endl;
        cin >> temp;
        cout << "Enter price of the item " << endl;
        cin >> price;  
        s1.addItem(temp, price);
        break;

        case 2:
        cout << "Enter name of the item you want to remove " << endl;
        cin >> temp;
        s1.retrieveItem(temp);
        break;

        case 3:
        cout << "Enter the name of the item you want to modify prices of " << endl;
        cin >> temp;
        cout << "Enter the price you want to update " << endl;
        cin >> price;
        s1.modifyprice(temp, price);
        break;

        case 4: 
        s1.display();
        break;

        case 5:
            int i = 0;
            string done = "done";
            string temp[100];
            int quantity[100];
            do{
                cout << "Choose the item by writing its name or (done) to finish)" << endl;
                cin >> temp[i];
                cout << "Enter its quantity " << endl;
                cin >> quantity[i];
                i++;
                
            }while(temp[i - 1] != done);
            break;
        };

        cout << "\nMenu:\n"
            << "1. Add Item\n"
            << "2. Retrieve Item List\n"
            << "3. Modify Item Price\n"
            << "4. Display Items with Prices\n"
            << "5. Generate Receipt\n"
            << "Enter your choice: ";
            cin >> n;
    }
}
