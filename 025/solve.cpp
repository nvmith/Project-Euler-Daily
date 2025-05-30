#include <bits/stdc++.h>

using namespace std;

string add(string a, string b) {
    int i = a.size(), j = b.size(), carry = 0;
    string res;
    while (i || j || carry) {
        if (i) carry += a[--i] - '0';
        if (j) carry += b[--j] - '0';
        res += (carry % 10) + '0';
        carry /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    ios:;sync_with_stdio(0);
    cin.tie(0);
    
    string a = "1";
    string b = "1";
    int idx = 2;

    while (b.size() < 1000) {
        string next = add(a, b);
        a = b;
        b = next;
        idx++;
    }

    cout << idx << '\n';
}