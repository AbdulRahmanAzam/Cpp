#include <iostream>
using namespace std;

class Robot {
    private:
    int x;
    int y;
    
    public:
    // default constructor
    Robot(){
        x = 0;
        y = 0;
    }
    // parametrized constructor
    Robot(int x, int y){
        this->x = x;
        this->y = y;
    }
    
    // copy constructor
    Robot(const Robot &other){
        this->x = other.y;
        this->y = other.x;
    }
    
    // setters
    void setx(int x){
        this->x = x;
    }
    void sety(int y){
        this->y = y;
    }
    
    //getters
    int getx() const{
        return this->x;
    }
    int gety() const{
        return this->y;
    }
    
    // functions
    void moveLeft(int d){
        cout << "It moves left successfully" << endl;
        x -= d;
    }
    void moveRight(int d){
        cout << "It moves right successfully" << endl;
        x += d;
    }
    
    void moveForward(int d){
        cout << "It moves forward successfully" << endl;
        y += d;
    }
    void moveReverse(int d){
        cout << "It moves reverse successfully" << endl;
        y -= d;
    }
    
    void movebyRead(string act, int d){
        for(int i=0; i< act.size(); i++){
            switch(act[i]){
                case 'B':
                moveReverse(d);
                break;
                case 'F':
                moveForward(d);
                break;
                case 'L':
                moveLeft(d);
                break;
                case 'R':
                moveRight(d);
                break;
                default:
                cout << "Invalid input" << endl;
                return;
            }
        }
    }
};

int main(){
    Robot R1;
    
}
