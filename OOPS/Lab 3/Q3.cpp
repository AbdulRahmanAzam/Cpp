// Abdul Rahman Azam
// 23k-0061
// date: 9/feb/2024

#include <iostream>
#include <string>
using namespace std;

class Calender{
    private:
    static const int totalmonth = 12;
    static const int days = 31;
    string arr[totalmonth][days][1];
    int currentYear;
    
    public:
    // constructor
    Calender(int year) : currentYear(year){
        // for(int i=0; i< 12; i++){
        //     for(int j=0; j < 31; j++){
        //         arr[i][j][0] = "";
        //     }
        // }
    }
    
    void addTask(string task, int month, int day){
        if(month >= 1 && month <= 12 && day >= 1 && day <=31){
            arr[month-1][day-1][0] = task;
            cout << "task added successfull" << endl;
        }else{
            cout << "invlid input" << endl;
        }
    }
    
    void removeTask(int month, int day){
        if(month >= 1 && month <= 12 && day >= 1 && day <=31){
            arr[month-1][day-1][0] = "";
            cout << "Task deleted succesfully" << endl;
        }else{
            cout << "invalid input" << endl;
        }
    }
    
    void display(){
        cout << "\nTasks are \n" ;
        for(int i=0; i< 12; i++){
            for(int j=0; j< 31;j++){
                string task = arr[i][j][0];
                if(!task.empty()){
                    cout << task << endl;
                }
            }
        }
    }
};

int main(){
    Calender my2024(2024);
    
    my2024.addTask("working on 9-feb-2024 ?", 2, 4);
    my2024.addTask("Today i will complete stack (INSHA ALLAH)",4,31);
    my2024.addTask("to delete",1,2);
    my2024.removeTask(1,2);
    my2024.addTask("working awesome",5,4);
    
    my2024.display();
    
}
