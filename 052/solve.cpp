#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPermutation(ll a, ll b)
{
    string sa = to_string(a), sb = to_string(b);
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    return sa == sb;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(ll i=1;;i++)
    {
        bool ok = true;
        
        for(int j=2;j<7;j++)
        {
            if(!isPermutation(i,i*j))
            {
                ok = false;
                break;
            }
        }
        
        if(ok)
        {
            cout << i;
            break;
        }
    }
}