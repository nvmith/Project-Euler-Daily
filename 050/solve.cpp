#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> isPrime(1000001, true);
    vector<int> primes;

    for (int i = 2; i*i <= 1000000; i++) 
    {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= 1000000; j += i)
            isPrime[j] = false;
    }

    for (int i = 2; i <= 1000000; ++i)
        if (isPrime[i]) primes.push_back(i);
    
    int result = 0;
    int max_length = 0;
    
    for (int i = 0; i < primes.size(); i++) 
    {
        int sum = 0;
        for (int j = i; j < primes.size(); j++) 
        {
            sum += primes[j];
            if (sum > 1000000) break;
            if (isPrime[sum] && (j - i + 1) > max_length) 
            {
                result = sum;
                max_length = j - i + 1;
            }
        }
    }
    
    cout << result;
}