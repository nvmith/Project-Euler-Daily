#include <bits/stdc++.h>

using namespace std;

using ll = long long;

string multiply(int init, int power) {
    string num = "1";
    
    for (int p = 0; p < power; p++) {
        string res;
        int carry = 0;

        for (int i = num.size() - 1; i >= 0; i--) {
            int digit = num[i] - '0';
            int product = digit * init + carry;
            res += (product % 10) + '0';
            carry = product / 10;
        }

        while (carry > 0) {
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
    
    string result;
    ll sum = 0;
    
    result = multiply(2, 1000);
    
    for(int i=0;i<result.size();i++)
        sum += result[i] - '0';
    
    cout << sum;
}
