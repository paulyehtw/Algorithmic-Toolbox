#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    int fib = 0;
    if (n <= 1){fib = n;}
    else
    {
        vector<int> fiblist(n);
        fiblist[0] = 1;
        for (int i = 1; i < n ; i++){fiblist[i] = fiblist[i-1] + fiblist[i-2];}
        fib = fiblist[n-1];
    }
    return fib;
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
