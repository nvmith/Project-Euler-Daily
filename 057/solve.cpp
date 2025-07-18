#include <bits/stdc++.h>

using namespace std;

struct BigInt
{
    BigInt() { len = 0; }
    BigInt(int m)
    {
        len = 0;
        while(m)
        {
            v[len++] = m%10;
            m /= 10;
        }
    }
    void mul2add(BigInt &a)
    {
        int carry = 0;
        for(int i = 0; i < len; i++)
        {
            carry += v[i]*2 + ((i<a.len) ? a.v[i] : 0);
            v[i] = carry%10;
            carry /= 10;
        }
        while(carry)
        {
            v[len++] = carry%10;
            carry /= 10;
        }
    }
    int len;
    char v[1024];
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    BigInt d = 2, n = 3, d1 = 1, n1 = 1;
    int cnt = 0;
    for(int i=2; i<=1000; i++)
    {
        BigInt t;
        t = d; d.mul2add(d1); d1 = t;
        t = n; n.mul2add(n1); n1 = t;
        if(n.len > d.len) cnt++;
    }
    cout << cnt;
}