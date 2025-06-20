#include <bits/stdc++.h>

using namespace std;

int countPrimeFactors(int n)
{
    int cnt = 0;
    
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) 
        {
            cnt++;
            while (n % i == 0) n /= i;
        }
    }
    if(n>1) cnt++;
    
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int cnt = 0;
    for (int i = 646;; i++) 
    {
        if (countPrimeFactors(i) == 4) 
        {
            cnt++;
            if (cnt == 4) 
            {
                cout << i - 3;
                break;
            }
        } 
        else cnt = 0;
    }
}