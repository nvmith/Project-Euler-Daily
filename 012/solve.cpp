#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int factorCnt(ll n)
{
    int cnt=0;
    
    for (ll i = 1; i*i<=n; i++)
        if(n%i==0) cnt+=2;
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(ll i=1;;i++)
    {
        ll t_num = i*(i+1)/2;
        
        if(factorCnt(t_num)>500)
        {
            cout<<t_num<<'\n';
            break;
        }
    }
}