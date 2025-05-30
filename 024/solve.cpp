#include <bits/stdc++.h>

using namespace std;

vector<int> nums = {0,1,2,3,4,5,6,7,8,9};

int factorial(int n)
{
    int result = 1;
    for(int i=1;i<=n;i++)
        result *= i;
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int target = 999999;
    string answer = "";
    
    for (int i = 9; i >= 0; i--) {
        int f = factorial(i);
        int index = target / f;
        answer += to_string(nums[index]);
        nums.erase(nums.begin() + index);
        target %= f;
    }
    cout << answer;
}