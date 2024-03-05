// Abdul Rahman Azam 23k-0061
// 5/ 3/ 2024

#include <iostream>
using namespace std;

class ValidateString{
     public:
        string str;
        
   
    ValidateString(string str){
        this->str = str;
    }
    
   // we use const to get the exact value, as there might be chances that the value of function may changed during sending bool 
    const bool func(string str){
        for(int ch : str){
            if(((ch < 'a' && ch > 'Z') || (ch < 'A' || ch > 'z')) && ch != 32){
                return false;
            }
        }
        return true;
    }
};

int main(){
    ValidateString vs1("Abdul Rahman Azam"), vs2("Pasha1");
    
    cout << "Is vs1 is string " << (vs1.func(vs1.str) ? "true" :"false" )<< endl;
    cout << "Is vs2 is string " << (vs2.func(vs2.str) ? "true" :"false" )<< endl;
}
