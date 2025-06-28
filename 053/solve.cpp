#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool comb(int n, int r)
{
    long long res = 1;
    for (int i = 1; i <= r; i++)
    {
        res *= (n - i + 1);
        res /= i;
        if (res > 1000000) return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int result = 0;
    
    for(int n=1;n<=100;n++)
    {
        for (int r = 1; r <= n / 2; r++)
        {
            if (comb(n, r))
            {
                result += (n - 2 * r + 1);
                break;
            }
        }
    }
    
    cout << result;
}