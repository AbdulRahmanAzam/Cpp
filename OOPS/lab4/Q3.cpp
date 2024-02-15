#include <iostream>
using namespace std;

class WeekDays {
    private:
    string Days[7];
    int CurrentDay;


    public:
    //default constructor
    WeekDays(void){
        Days[0] = "Sunday";
        Days[1] = "Monday";
        Days[2] = "Tuesday";
        Days[3] = "Wednesday";
        Days[4] = "Thursday";
        Days[5] = "Friday";
        Days[6] = "Saturday";
    }
    // parametrised constructor
    WeekDays(int CurrentDay){
        if(CurrentDay > 6)
            CurrentDay %= 6;

        Days[0] = "Sunday";
        Days[1] = "Monday";
        Days[2] = "Tuesday";
        Days[3] = "Wednesday";
        Days[4] = "Thursday";
        Days[5] = "Friday";
        Days[6] = "Saturday";
    }

    //methods
    string getCurrentDay(){
        return Days[CurrentDay];
    }
    string getNextDay(){
        return Days[CurrentDay + 1];
    }
    string getPreviousDay(){
        return Days[CurrentDay - 1];
    }
    string getNthDayFromToday(int nth){
        int totalday = CurrentDay + nth;
        if(totalday > 6)
            totalday %= 6;

        return Days[totalday];
    }

};

int main(){
    WeekDays();
}
