#include <iostream>
using namespace std;

bool isPalindrome(string str, int s,  int e){
    //base case
    if(s > e) return true;
    
    if(str[s] == str[e]){
        return checkPalindrome(str, s+1, e-1);   
    }
    else return false;
}

int main(){
    string name = "aabbbaa";
    
    if(isPalindrome(name, 0, name.size() - 1)){
        cout << " is palindrome " << "\n\n";
    }else {
        cout << " not palindrome" << "\n\n";
    }
    
    cout << name << endl;
}
