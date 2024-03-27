#include <iostream>
using namespace std;

class Enemy;
class Weapon;
class Character;

class Player{
    public:
    int playerID;
    string playerName;
    int health;

    Player(int playerID, string playerName) : playerID(playerID), playerName(playerName), health(100) {}

};

class Weapon{
    public:
    string WeaponsList[100];

    Weapon(){
        WeaponsList[0]= "KAR-98";
        WeaponsList[1]= "shotgun";
        WeaponsList[2]= "32 bore";
        WeaponsList[3]= "burster";
        WeaponsList[4]= "sniper";
    }

    void use(){
        cout << "select the weapon from the below listed weapons" << endl;
        int i;
        for(i=0; WeaponsList[i] != "" ; i++){
            cout << i + 1 << " "<< WeaponsList[i] << endl;
        }
        // for(string ch : WeaponsList){
            
        // }
        cout << "Enter the number of the weapon you want to select" << endl;
        cin >> i;
        cout << "You got " << WeaponsList[i-1] << " successfully" << endl;

    }
};

class Character : public Player, virtual public Weapon{
    public:
    int level;
    string experience;
    int points;

    Character(int playerID, string playerName) : Player(playerID, playerName), level(0), experience("Beginner"), points(0){};
    
    void LevelUp(){
        if(points % 10 == 0){
            if(experience == "Beginner"){
                experience = "Intermediate";
                cout << "your Level is upgraded to Intermediate" << endl;
            }else if(experience == "Intermediate"){
                experience = "Advanced";
                cout << "your Level is upgraded to Advanced" << endl;
            }else if(experience == "Advanced"){
                experience = "Expert";
                cout << "your Level is upgraded to Expert" << endl;
            }else 
                cout << "You are already Expert" << endl; 
            
        }else{
            cout << "Level cannot be upgraded at this point" << endl; 
        }
        cout << endl;
    }

    void playGame(Enemy &enemy);

    void healthdec(int damage){
        this->health -= damage;
        cout << "The health of the Character is " << health << endl;
    }
};


class Enemy : public Player, virtual public Weapon{
    public:
    int damage;

    Enemy(int damage) : Player(0, "enemy") {
        if(damage > 0 && damage <= 10){
            this->damage = damage;
        }else {
            cout << "damage is set to 1 because it parameter exceeds the limit" << endl;
            this->damage = 1;
        }
    }
    void healthdec(int damage){
        this->health -= damage;
        cout << "The health of enemy is = " << health << endl;
    }

    void attack(Character &player);
    
};

void Character::playGame(Enemy &enemy){
    cout << "Now its user turn" << endl;

    Weapon::use();
    cout << "The character attacks enemy with the damage of " << 5 << endl;

    enemy.healthdec(5);

    this->points += 10;
    LevelUp();
}

void Enemy::attack(Character &player){
    cout << "Now its enemy turn" << endl;
    Weapon::use();
    cout << "The Enemy attacks Player with the damage of " << damage << endl;
    player.healthdec(damage);
}

int main(){
    Character user(0061, "Abdul Rahman Azam");
    Enemy enemy(10);

    user.playGame(enemy);
    enemy.attack(user);
    
   user.playGame(enemy);
    enemy.attack(user);
    
    user.playGame(enemy);
    enemy.attack(user);

    user.playGame(enemy);
    enemy.attack(user);

}
