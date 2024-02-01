#include <iostream>
using namespace std;

void rswap(int &a, int &b, int n = 3) {
  if (n == 0) 
    return;
  
  a ^= b;
  rswap(b,a, n - 1);
}

int main() {
  int a = 5, b = 7;

  cout << "Before: " << endl;
  cout << "a = " << a << "  b = " << b << endl;

  rswap(a, b);

  cout << "After: " << endl;
  cout << "a = " << a << "  b = " << b << endl;
}
