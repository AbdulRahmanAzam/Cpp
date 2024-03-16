#include <iostream>
#include <vector>
#include <string>
using namespace std;

inline int batavg(int runs, int dismissed){
    return static_cast<double>(runs) / dismissed;
};

inline int strike(int runs, int balls_faced){
    return static_cast<double>(runs) / balls_faced * 100;
};

int main(){
    int runs = 4, balls = 5, dismissed = 2;

    cout << "Batting avg is  = " << batavg(runs, dismissed) << endl;

    cout << "strike rate is = " << strike(runs, balls) << endl;

}
