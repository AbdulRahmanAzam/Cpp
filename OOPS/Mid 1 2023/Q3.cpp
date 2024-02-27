// it may have some thing which is not perfect like not tracking the budget

#include <iostream>
#include <string>
using namespace std;

class staff{
    private:
    int staffID;
    int salary;
    string employeeType;
    
    public:
    staff(int id, int salary, string employeeType) : staffID(id), salary(salary), employeeType(employeeType){}
    
    static float total_salaries;
    
    double TrackProject(double currentCost){
        cout << "tracking the project" << endl;
        if(currentCost > 200000){
            cout << "warning: that cost is exceeding budget" << endl;
        }
        return currentCost;
    }
    double Animate(double currentCost){
        cout << "Animating the project" << endl;
        return currentCost + 10000; 
    }
    
};

class movie_projects{
    private:
    int movieID;
    string title;
    int currentCost;
    staff lead;
    staff chiefAnimator;
    
    public:
    movie_projects(int id, string title, int cost) : movieID(id), title(title), currentCost(cost), lead(0, 100000, "Lead"), chiefAnimator(1,50000,"ChiefAnimator"){}
    
    static float totalBudgetOfAll;
    
    void production(){
        currentCost = lead.TrackProject(currentCost);
        currentCost = chiefAnimator.Animate(currentCost);
        cout << "Task is in production" << endl;   
    }
    
};

float movie_projects::totalBudgetOfAll = 200000;

float staff::total_salaries = 0;

int main(){
     movie_projects m1(0, "netflix1", 100000)  ; 
     m1.production();
     m1.production();
     m1.production();
}
