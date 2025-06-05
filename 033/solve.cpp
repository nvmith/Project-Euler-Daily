#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll afterReduceDenom(ll numer, ll denom) 
{
    for (ll i = 2; i <= numer; i++) 
    {
        while (numer % i == 0 && denom % i == 0) 
        {
            numer /= i;
            denom /= i;
        }
    }
    
    return denom;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll numerator = 1, denominator = 1;
    
    for (int i = 10; i < 100; i++) // 분자
    {
        for (int j = i + 1; j < 100; j++) // 분모
        {
            if (i % 10 == 0 || j % 10 == 0) continue;

            int i1 = i / 10, i2 = i % 10;
            int j1 = j / 10, j2 = j % 10;

            if (i2 == j1 && i * j2 == j * i1) {
                numerator *= i;
                denominator *= j;
            }
            else if (i1 == j2 && i * j1 == j * i2) {
                numerator *= i;
                denominator *= j;
            }
            else if (i1 == j1 && i * j2 == j * i2) {
                numerator *= i;
                denominator *= j;
            }
            else if (i2 == j2 && i * j1 == j * i1) {
                numerator *= i;
                denominator *= j;
            }
        }
    }
    cout << afterReduceDenom(numerator, denominator);
}