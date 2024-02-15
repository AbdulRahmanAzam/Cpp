#include <iostream>
using namespace std;

class WeekDays {
    private:
    string Days[7];
    int CurrentDay;

    void initializeDays(){
        Days[0] = "Sunday";
        Days[1] = "Monday";
        Days[2] = "Tuesday";
        Days[3] = "Wednesday";
        Days[4] = "Thursday";
        Days[5] = "Friday";
        Days[6] = "Saturday";
    }
    public:
    //default constructor
    WeekDays(void){
        CurrentDay = 0;
        initializeDays();
    }
    // parametrised constructor
    WeekDays(int CurrentDay){
        if(CurrentDay > 6)
            CurrentDay %= 7;
            
        this->CurrentDay = CurrentDay;
        initializeDays();
    }

    //methods
    
    
    string getCurrentDay(){
        return Days[CurrentDay];
    }
    string getNextDay(){
        if(CurrentDay + 1 > 6)
            return Days[0];
        return Days[CurrentDay + 1];
    }
    string getPreviousDay(){
        if(CurrentDay - 1 < 0)
            return Days[6];
            
        return Days[CurrentDay - 1];
    }
    string getNthDayFromToday(int nth){
        int totalday = CurrentDay + nth;
        if(totalday > 6)
            totalday %= 7;

        return Days[totalday];
    }

};

int main(){
    int n=0;
    WeekDays W(7);
    
    cout << "current day " << W.getCurrentDay() << endl;
    cout << "next day " << W.getNextDay() << endl;
    cout << "previous day " << W.getPreviousDay() << endl;
    
    cout << "Enter nth number to get nth day from current day " << endl;
    cin >> n;
    cout << "Nth day from today is " << W.getNthDayFromToday(n);
    
}
