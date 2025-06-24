#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) 
{
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> p;
    for (int i = 1000; i <= 9999; i++)
        if (isPrime(i)) p.push_back(i);

    for (int num : p) 
    {
        string s = to_string(num);
        sort(s.begin(), s.end());

        set<int> primes;
        do {
            int tmp = stoi(s);
            if (isPrime(tmp) && tmp >= 1000) primes.insert(tmp);
        } while (next_permutation(s.begin(), s.end()));

        if (primes.size() < 3) continue;

        vector<int> arr(primes.begin(), primes.end());

        for (int i = 0; i < arr.size(); i++) 
        {
            for (int j = i+1; j < arr.size(); j++) 
            {
                int a = arr[i], b = arr[j];
                int diff = b - a;
                int c = b + diff;
                if (primes.count(c)) 
                {
                    if (a == 1487 && b == 4817) continue;
                    cout << a << b << c;
                    return 0;
                }
            }
        }
    }
}
