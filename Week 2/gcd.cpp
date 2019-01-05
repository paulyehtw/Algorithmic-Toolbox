#include <iostream>

using namespace std;

int gcd_fast(int a, int b){

  int big = max(a,b);
  int small = min(a,b);
  int temp_s = 0;
  int gcd = 0;
  while (small != 0){
    temp_s = small;
    small = big%small;
    big = temp_s;
  }
  return big;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
