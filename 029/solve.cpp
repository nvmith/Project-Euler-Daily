#include <bits/stdc++.h>
using namespace std;

string stPower(int base, int power) 
{
    string num = "1";

    for (int p = 0; p < power; p++) 
    {
        string res;
        int carry = 0;

        for (int i = num.size() - 1; i >= 0; i--) 
        {
            int digit = num[i] - '0';
            int product = digit * base + carry;
            res += (product % 10) + '0';
            carry = product / 10;
        }

        while (carry > 0) 
        {
            res += (carry % 10) + '0';
            carry /= 10;
        }

        reverse(res.begin(), res.end());
        num = res;
    }
    return num;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    set<string> s;

    for (int a = 2; a <= 100; a++) 
    {
        for (int b = 2; b <= 100; b++) 
        {
            s.insert(stPower(a, b));
        }
    }

    cout << s.size();
}
