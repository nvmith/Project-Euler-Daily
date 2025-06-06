#include <bits/stdc++.h>

using namespace std;

int fac[10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int result = 0;
    
    fac[0] = 1;
    for (int i = 1; i < 10; i++)
        fac[i] = fac[i - 1] * i;
    
    for(int i=10;i<=999999;i++)
    {
        int sum = 0, n = i;
        
        while (n > 0)
        {
            sum += fac[n % 10];
            n /= 10;
        }

        if (sum == i)
            result += i;
    }
    
    cout << result;
}