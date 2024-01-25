#include <iostream>
using namespace std;

int main(){
    int total = 0;
    int col = 0;
    cout << "Enter no of students" << endl;
    cin >> col;
    int arr[col][3]; 
    
    
    for(int i = 0 ; i< col; i++){
        cout << "\nEnter marks of the students" << endl;
            cout << "math " << endl;
            cin >> arr[i][0];
            cout <<  "english " << endl;
            cin >> arr[i][1]; 
            cout << "science " << endl;
            cin >> arr[i][2];
    }
    
    for(int i = 0; i < col; i++){
        total = 0;
        
        for(int j = 0; j< 3; j++){
            total += arr[i][j];
        }
        cout << "marks " << total << endl;
        int avg = total / 3;
        cout << "total avg " << avg << endl;
        
        if(avg >= 90){
            cout << "Grade A \n\n" ;
        }else if(avg >= 80 && total <= 89){
            cout << "Grade B \n\n" ;
        }else if(avg >= 70 && total <= 79){
            cout << "Grade C \n\n" ;
        }else if(avg >= 60 && total <= 69){
            cout << "Grade D \n\n" ;
        }else if(avg < 60){
            cout << "Grade F \n\n" ;
        }
    }
    
    
}
