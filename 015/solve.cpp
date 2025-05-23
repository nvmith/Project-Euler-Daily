#include <bits/stdc++.h>

using namespace std;

using ll = long long;



ll combination(int n, int k)
{
    ll res = 1;
    for (int i = 1; i <= k; i++) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << combination(40, 20);
}
