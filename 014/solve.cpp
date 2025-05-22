#include <bits/stdc++.h>

using namespace std;

using ll = long long;

unordered_map<ll, int> memo;

int hailstone(ll n) {
    if (memo.count(n)) return memo[n];

    if (n == 1) return 1;

    int next = (n % 2 == 0) ? hailstone(n / 2) : hailstone(3 * n + 1);
    memo[n] = 1 + next;
    return memo[n];
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int most = 0;
    int mostNum = 0;
    
    for(int i=1000000;i>0;i--)
    {
        ll cur = hailstone(i);
        
        if(cur>most)
        {
            most = cur;
            mostNum = i;
        }
    }
    
    cout << mostNum;
}