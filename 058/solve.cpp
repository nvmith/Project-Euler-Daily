#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPrime(ll n)
{
    if (n<2) return false;
    if (n==2 || n==3) return true;
    if (n%2==0 || n%3==0) return false;
    
    for (ll i=5; i*i<=n; i+=6)
    {
        if (n%i == 0 || n % (i+2) == 0)
            return false;
    }
    return true;
}

int main()
{
    ll vertexCnt = 1;
    ll primeCnt = 0;
    
    for (ll i=3;; i+=2)
    {
        ll sq = i * i;
        for (int j = 1; j <= 3; j++)
        {
            if (isPrime(sq-j*(i-1)))
                primeCnt++;
        }
        vertexCnt += 4;
    
        if ((double)primeCnt / vertexCnt < 0.1)
        {
            cout << i;
            return 0;
        }
    }
}