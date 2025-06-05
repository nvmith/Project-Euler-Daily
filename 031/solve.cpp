#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int coins[8] = {1,2,5,10,20,50,100,200};
    int target = 200;
    
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int coin : coins) 
        for (int i = coin; i <= target; i++)
            dp[i] += dp[i - coin];
    
    cout << dp.back();
}