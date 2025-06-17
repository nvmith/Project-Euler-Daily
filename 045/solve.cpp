#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool isPentagonal(ll x) 
{
    double n = (1 + sqrt(24 * x + 1)) / 6;
    return n == (ll)n;
}

bool isHexagonal(ll x)
{
    double n = (1 + sqrt(8 * x + 1)) / 4;
    return n == (ll)n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(ll i=286;;i++)
    {
        ll t = (i * (i + 1)) / 2;
        if(isPentagonal(t) && isHexagonal(t))
        {
            cout << t;
            break;
        }
    }
}