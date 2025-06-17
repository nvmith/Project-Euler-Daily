#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool isPrime(ll n)
{
    for(ll i = 2; i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(ll i=9;;i+=2)
    {
        if(isPrime(i)) continue;
        
        bool found = false;

        for (ll p = 2; p < i; p++)
        {
            if (!isPrime(p)) continue;
            ll rem = i - p;
            if (rem % 2 != 0) continue;
            ll k = sqrt(rem / 2);
            if (k * k == rem / 2) 
            {
                found = true;
                break;
            }
        }
        if (!found) 
        {
            cout << i;
            break;
        }
    }
}