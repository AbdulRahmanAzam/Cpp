// in abcde
// out edcba

#include <iostream>
using namespace std;

void reverse(string& name, int s){
    if(s > name.size()/2){
        return;
    }
    
    reverse(name, s+1);
    
    swap(name[s],name[name.size()-1-s]);
}

int main(){
    string name = "abcde";
    
    reverse(name, 0);
    
    cout << name << endl;
}
