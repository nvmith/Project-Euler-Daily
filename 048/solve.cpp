#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using u128 = __uint128_t;

ll MOD = 10000000000;

ll modpow(ll base, ll exp, ll mod) 
{
    u128 result = 1;
    u128 b = base;
    while (exp > 0) 
    {
        if (exp % 2 == 1)
            result = (result * b) % mod;
        b = (b * b) % mod;
        exp /= 2;
    }
    return result;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll sum = 0;
    for (int i = 1; i <= 1000; i++)
        sum = (sum + modpow(i, i, MOD)) % MOD;
    cout << setfill('0') << setw(10) << sum;
}
