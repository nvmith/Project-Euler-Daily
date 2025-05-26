#include <bits/stdc++.h>

using namespace std;

string multiply(string num, int n) {
    string result = "";
    int carry = 0;

    for (int i = num.size() - 1; i >= 0; i--) {
        int prod = (num[i] - '0') * n + carry;
        result += (prod % 10) + '0';
        carry = prod / 10;
    }
    while (carry) {
        result += (carry % 10) + '0';
        carry /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string factorial(int x) {
    string result = "1";
    for (int i = 2; i <= x; i++) {
        result = multiply(result, i);
    }
    return result;
}

int digitSum(string s)
{
    int sum = 0;
    for(int i=0;i<s.size();i++)
        sum += s[i] - '0';
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << digitSum(factorial(100));
}
