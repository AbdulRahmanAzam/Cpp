#include <iostream>
using namespace std;

bool isPalindrome(string str, int s){
    //base case
    if(s > str.size()-1) return true;
    
    if(str[s] == str[str.size()-1-s]){
        return isPalindrome(str, s+1);   
    }
    else return false;
}

int main(){
    string name = "aabbbaa";
    
    if(isPalindrome(name, 0)){
        cout << " is palindrome " << "\n\n";
    }else {
        cout << " not palindrome" << "\n\n";
    }
    
    cout << name << endl;
}
