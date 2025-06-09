#include <bits/stdc++.h>

using namespace std;

bool isSymBinary(int n) 
{
    string ori;
    while (n > 0) {
        ori = char('0' + (n % 2)) + ori;
        n /= 2;
    }
    string rev(ori.rbegin(), ori.rend());
    return ori==rev;
}

bool isSym(int n)
{
    string ori = to_string(n);
    string rev(ori.rbegin(), ori.rend());
    return ori==rev;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int sum = 0;
    
    for(int i=1;i<1000000;i++)
    {
        if(isSym(i) && isSymBinary(i))
            sum += i;
    }
    
    cout << sum;
}