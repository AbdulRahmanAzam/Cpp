#include <iostream>
using namespace std;

class menu_items{
    private:
    string food_name;
    int food_price;
    
    public:
    menu_items(string food_name, int food_price){
        this->food_name = food_name;
        this->food_price = food_price;
    }
    
};
class payment{
    private:
    int amount;
    public:
    payment(int amount){
        this->amount = amount;
    }
};
class order{
    // private:
    public:
    menus* mmenu;
    payment* pay(0);
    
    order(menus* mmenu, payment* pay){
        for(int i=0; i< mmenu.size())
    }
};

class menu{
    private:
    vector<menu_items> menus;
    
    public:
    menus(){
        
    }
    void additem(string name, int price){
        menu_items item(food_name, food_price);
        menus.push_back(item);   
    }
    void removeitem(string name){
        for(int i=0; i<menu_items.size(); i++){
            if(menu_items[i].food_name == name){
                menus.menu_items[i].food_name = "";
                menus.menu_items[i].food_price = 0;
                break;
            }
        }
    }
    void display(){
        for(menus.menu_items item:menu){
            if(item.price == 0) continue;
            cout << "item = " << item.food_name << " price = " << item.food_price << endl;
        }
    }
};

int main(){
    
}
