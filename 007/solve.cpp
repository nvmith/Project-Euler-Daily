#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

bool isPrime(int n)
{
    for(int i=2; i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=2;;i++)
    {
        if(isPrime(i)) cnt++;
        
        if(cnt==10001)
        {
            cout << i;
            break;
        }
    }
}