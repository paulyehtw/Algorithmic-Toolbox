#include <iostream>
#include <vector>

using namespace std;

long long get_fibonacci_huge_fast(unsigned long long n, unsigned long long m) {
    unsigned long long fib = 0;
    unsigned long long period = n;
    if (n <= 1){fib = n;}
    else
    {
        unsigned long long fib0 = 0;
        unsigned long long fib1 = 1;
        unsigned long long n_pas = n;
        for (unsigned long long i = 2; i < n ; i++){
            unsigned long long fib_temp = fib1%m;
            fib1 = (fib0 + fib1)%m;
            fib0 = fib_temp;
            if(fib1 == 1 && fib0 == 0){
                period = i - 1;
                n_pas = n%period;
                break;}
            }
        if (n_pas <= 1){fib = n_pas;}
        else{
            vector<unsigned long long> fiblist(n_pas+1);
            fiblist[0] = 0;
            fiblist[1] = 1;
            for (int i = 2; i < n_pas+1 ; i++){fiblist[i] = (fiblist[i-1] + fiblist[i-2])%m;}
            fib = fiblist[n_pas];    
            } 
    }
    return fib;
}

int main() {
    unsigned long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
