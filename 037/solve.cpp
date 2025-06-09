#include <bits/stdc++.h>

using namespace std;

vector<bool> isPrime(1000000, true);

void sieve() 
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < 1000000; ++i) 
    {
        if (!isPrime[i]) continue;
        for (int j = i * i; j < 1000000; j += i)
            isPrime[j] = false;
    }
}

bool isTruncatable(int n) 
{
    string s = to_string(n);

    for (int i = 0; i < s.size(); ++i)
        if (!isPrime[stoi(s.substr(i))]) return false;

    for (int i = s.size(); i > 0; --i)
        if (!isPrime[stoi(s.substr(0, i))]) return false;

    return true;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    sieve();

    int sum = 0, found = 0;
    for (int i = 10; found < 11; i++) 
    {
        if (isPrime[i] && isTruncatable(i)) 
        {
            sum += i;
            found++;
        }
    }

    cout << sum;
}
