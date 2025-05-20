#include <bits/stdc++.h>
using ll = long long;

using namespace std;

bool isSym(ll num)
{
    string s = to_string(num);
    string rev(s.rbegin(), s.rend());
    
    return s == rev;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll biggest = 0;
    
    for(int i=999;i>0;i--)
    {
        for(int j=i;j>0;j--)
        {
            ll value = 1LL*i*j;
            if(isSym(value))
                biggest = max(biggest, value);
        }
    }
    
    cout << biggest << '\n';
}
