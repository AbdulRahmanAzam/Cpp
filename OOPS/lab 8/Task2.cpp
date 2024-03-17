// inheritance hierarchy

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Character{
    public:
    int health;
    int damage;
    
    Character(int health, int damage) : health(health), damage(damage) {}
    
    void display(){
        cout << "Health = " << health
        << "\nDamage = " << damage << endl;
    };
};

class Enemy : public Character{
    public:
    Enemy(int health, int  damage) : Character(health, damage) {}
    
    void display(){
        cout << "Health = " << health
        << "\nDamage = " << damage << endl; 
    }
};

class Player : public Character{
    public:
    Player(int health, int  damage) : Character(health, damage) {}
    
    void display(){
        cout << "Health = " << health
        << "\nDamage = " << damage << endl; 
    }
};

class Wizard : public Player{
    public:
    int magic_power;
    string spells;
    
    Wizard(int health, int  damage, int magic_power, string spells) : Player(health, damage), magic_power(magic_power), spells(spells) {}
    
    void display(){
        Character::display();
        cout << "Magic_powers = " << magic_power
        << "\nspells = " << spells << endl;
    }
};

int main(){
    Wizard w(200, 50, 3, "heal");
    w.display();
}
