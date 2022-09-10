#include<bits/stdc++.h>
using namespace std;

// Refer Bases - https://www.topcoder.com/thrive/articles/Mathematics%20for%20Topcoders
int toDecimal(int n, int b) {
  int result = 0;
  int multiplier = 1;

  while (n > 0) {
    result += n % 10 * multiplier;
    multiplier *= b;
    n /= 10;
  }

  return result;
}

int fromDecimal(int n, int b) {
  int result = 0;
  int multiplier = 1;

  while (n > 0) {
    result += n % b * multiplier;
    multiplier *= 10;
    n /= b;
  }

  return result;
}

int main(){
    cout<<toDecimal(101, 2)<<endl;
    cout<<fromDecimal(5, 2)<<endl;
    return 0;
}