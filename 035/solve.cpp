#include <bits/stdc++.h>

using namespace std;

vector<bool> isPrime(1000000, true);

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < 1000000; i++) 
    {
        if (!isPrime[i]) continue;
        for (int j = i * i; j < 1000000; j += i)
            isPrime[j] = false;
    }
}

vector<int> rotateDigits(int n) 
{
    vector<int> rotations;
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++) 
    {
        rotate(s.begin(), s.begin() + 1, s.end());
        rotations.push_back(stoi(s));
    }
    return rotations;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    sieve();
    
    int cnt = 0;
    
    for(int i=2; i<1000000;i++)
    {
        if(!isPrime[i]) continue;
        
        bool isCP = true;
        
        for (int rot : rotateDigits(i)) 
        {
            if (!isPrime[rot]) 
            {
                isCP = false;
                break;
            }
        }
    
        if (isCP) cnt++;
    }
    
    cout << cnt;
}