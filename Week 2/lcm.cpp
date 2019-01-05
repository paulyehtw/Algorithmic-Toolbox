#include <iostream>

using namespace std;

long long lcm_fast(long a, long b) {
  long gcd = max(a,b);
  long small = min(a,b);
  long temp_s = 0;
  while (small != 0){
    temp_s = small;
    small = gcd%small;
    gcd = temp_s;
  }
  long long lcm = abs(a*b)/gcd;
  return lcm;
}

int main() {
  long a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
