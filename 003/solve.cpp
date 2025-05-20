#include <bits/stdc++.h>
using ll = long long;

using namespace std;

int main() {
    ll n = 600851475143;
    ll biggest;

    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            biggest = i;
            n /= i;
        }
    }

    if (n > 1) biggest = n;
    
    cout << biggest << '\n';
}
