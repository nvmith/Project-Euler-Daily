#include <bits/stdc++.h>

using ll = long long;
using namespace std;

map<int,int> factorMap;

map<int,int> fac(int n)
{
    map<int, int> f;
    
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            f[i]++;
            n /= i;
        }
    }
    if(n>1) f[n]++;
    
    return f;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=2;i<=20;i++)
    {
        map<int, int> current = fac(i);

        for (auto p : current) {
            int num = p.first;
            int count = p.second;

            if (factorMap[num] < count)
                factorMap[num] = count;
        }
    }
    
    ll result = 1;
    
    for(auto a : factorMap)
        for(int i=0;i<a.second;i++)
            result *= a.first;
    
    cout << result;
}
