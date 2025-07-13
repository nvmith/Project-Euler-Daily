#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string Add(string a, string b) 
{
    int i = a.size(), j = b.size(), carry = 0;
    string res;
    while (i || j || carry) 
    {
        if (i) carry += a[--i] - '0';
        if (j) carry += b[--j] - '0';
        res += (carry % 10) + '0';
        carry /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string ReverseStr(string st)
{
    string rev(st.rbegin(), st.rend());
    return rev;
}

bool IsSym(string st)
{
    string rev(st.rbegin(), st.rend());
    return st==rev;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int lychrel = 0;
    
    for (int i = 1; i <= 10000; i++)
    {
        string num = to_string(i);
        bool isLy = true;

        for (int cnt = 0; cnt < 50; cnt++)
        {
            num = Add(num, ReverseStr(num));
            
            if (IsSym(num))
            {
                isLy = false;
                break;
            }
        }

        if (isLy)
            lychrel++;
    }

    cout << lychrel;
}