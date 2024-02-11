// https://www.codingninjas.com/studio/problems/minimum-cost-to-make-string-valid_1115770?

#include <bits/stdc++.h> 
#include <stack> 

int findMinimumCost(string str) {
  // if it is an odd number then return -1
  if(str.length() % 2)
    return -1;

  stack<char> s;
  for(int i=0; i< str.size(); i++){
    char ch = str[i];
  // if '{' push it
    if(ch == '{'){
      s.push(ch);

    } else {
      // if stack top is '{' then pop it 
      if (!s.empty() && s.top() == '{'){
        s.pop();

      }else{
        s.push(ch);
      }

    }
  }
// used for maths 
  int a =0, b= 0;
  while (!s.empty()) {
    if (s.top() == '{'){
      b++;
    }else{
      a++;
    }
    s.pop();
  }
// mathematical equation (derived)
  int ans = (a+1)/2 + (b+1)/2;
  return ans;
}
