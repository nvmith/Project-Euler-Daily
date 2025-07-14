#include <bits/stdc++.h>

using namespace std;

int PowerSum(int base, int power) 
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
    
    int result = 0;
    
    for(auto c: num)
        result += c-'0';
    
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int maxResult = 0;
    
    for(int i=1;i<100;i++)
        for(int j=1;j<100;j++)
            maxResult = max(PowerSum(i,j),maxResult);
            
    cout << maxResult;
}