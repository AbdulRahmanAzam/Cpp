// Abdul Rahman Azam 23k-0061
// 5/ 3/ 2024
#include <iostream>
using namespace std;

class Square{
    private:
    float sideLength;
    float area;
    public:
    static float allareas;

    public:
    Square(float sideLength = 1){
        this->sideLength = sideLength;
        this->area = sideLength * sideLength;
        calculatearea(area);
    }

    static void calculatearea(float area){
        allareas += area;
    }

    //setters
    void setsideLength(float sideLength){
        this->sideLength = sideLength;
        allarea -= area;
        this-> area = sideLength * sideLength;
        allareas += area;
    }
    void setarea(float area){
        this->area = area;
    }
    
    //getters
    float getsideLength(){
        return this->sideLength;
    }
    float getarea(){
        return this->area;
    }
};
float Square::allareas = 0;

int main(){
    Square sq1(10.1);

    cout << "sq1, -> area = " << sq1.getarea() << " allarea = " << Square::allareas << endl;
    
    Square sq2(20);
    cout << "sq2, -> area = " << sq2.getarea() << " allarea = " << Square::allareas << endl;
    
    Square sq3(5.5);
    cout << "sq3, -> area = " << sq3.getarea() << " allarea = " << Square::allareas << endl;

}


