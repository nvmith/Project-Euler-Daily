#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPermutation(ll a, ll b)
{
    string sa = to_string(a);
    string sb = to_string(b);
 
    if(sa.size()!=sb.size()) return false;
    
    int cnt[10] = {0,};
    
    for(int i=0;i<sa.size();i++)
    {
        cnt[sa[i]-'0']++;
        cnt[sb[i]-'0']--;
    }
    
    for(int i=0;i<10;i++)
        if(cnt[i]!=0) return false;
    
    return true;
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