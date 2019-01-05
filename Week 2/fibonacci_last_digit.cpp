#include <iostream>
#include <vector>

using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    int fib = 0;
    if (n <= 1){fib = n;}
    else
    {
        vector<int> fiblist(n);
        fiblist[0] = 1;
        for (int i = 1; i < n ; i++){fiblist[i] = (fiblist[i-1] + fiblist[i-2])%10;}
        fib = fiblist[n-1];
    }
    return fib;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
