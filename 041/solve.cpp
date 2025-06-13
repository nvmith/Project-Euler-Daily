#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    if(n<2) return false;
    for(int i=2; i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s = "7654321";
    do 
    {
        int num = stoi(s);
        if(isPrime(num))
        {
            cout << num;
            break;
        }
        
    } while (prev_permutation(s.begin(), s.end()));
}
