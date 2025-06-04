#include <bits/stdc++.h>

using namespace std;

int fivePower(int n)
{
    int sum = 1;
    for(int i=0;i<5;i++)
        sum *= n;
    return sum;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int result = 0;
    
    for(int i=10;i<=6*fivePower(9);i++)
    {
        string s = to_string(i);
        int sum = 0;
        for(auto c : s)
            sum += fivePower(c-'0');
        if(i==sum)  result += sum;
    }
    
    cout << result;
}
