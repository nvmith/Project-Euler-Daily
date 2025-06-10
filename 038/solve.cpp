#include <bits/stdc++.h>

using namespace std;

bool isPandigital(string s) 
{
    if (s.length() != 9) return false;

    set<char> digits(s.begin(), s.end());
    return digits == set<char>{'1','2','3','4','5','6','7','8','9'};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int maxPandigital = 0;

    for (int x = 1; x < 10000; ++x) 
    {
        string s = "";
        for (int n = 1; s.length() < 9; ++n) 
        {
            s += to_string(x * n);
        }
        if (s.length() == 9 && isPandigital(s)) 
        {
            maxPandigital = max(maxPandigital, stoi(s));
        }
    }
    
    cout << maxPandigital;
}