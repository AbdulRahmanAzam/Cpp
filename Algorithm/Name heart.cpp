// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;


int main() {
    int n = 6;
    string s = "*****"; // any five alphabet name
    
    bool flag = false;
    for(int i =1; i <= 10 ; i++){
        for(int j =1;j <= n+3 ; j++){
            
            if(i == n / 2 + 1 && j > 2 && j < s.size() + 3){
                cout << " " <<  s[j - 3] << " ";
                
            }else if(i <= 2){
                if((j > n/2-i && j < n/2 +i) || (j > n-i+1 && j < n+i+1)){
                    cout << " * ";
                }else{
                    cout << "   ";
                }    
                
            }else if(i >= n/2 && i < n){
                cout << " * ";
                
            }else {
                int a = i-n+1;
                if(j <= a|| j > (n+n/2)-a){
                    cout << "   ";
                }else {
                    cout << " * ";
                }
            }
        }
        cout << endl;  
    }
        
    
}



//11 * 111 *
//1 * * 1 * *
// * * * * * *
// * * * * * *
// * * * * * *
//1 * * * * *
//11 * * * *
//111 * * *
//1111 * *
//11111 *
  
