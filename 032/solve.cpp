#include <bits/stdc++.h>

using namespace std;

int toNumber(vector<int> nums, int start, int end)
{
    int num = 0;
    for (int i = start; i <= end; ++i) {
        num = num * 10 + nums[i];
    }
    return num;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    set<int> s;
    
    do
    {
        int a = nums[0];
        int b = toNumber(nums, 1, 4);
        int c = toNumber(nums, 5, 8);
        if (a * b == c) s.insert(c);
        
        a = toNumber(nums, 0, 1);
        b = toNumber(nums, 2, 4);
        c = toNumber(nums, 5, 8);
        if (a * b == c) s.insert(c);

    }while(next_permutation(nums.begin(),nums.end()));
    
    cout << accumulate(s.begin(), s.end(), 0);
}