#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int result = 1;
    int target = 1;
    int digitCount = 0;

    for (int i = 1; target <= 1000000; i++) 
    {
        string num = to_string(i);
        int len = num.length();

        if (digitCount + len >= target) {
            result *= num[target - digitCount - 1] - '0';
            target *= 10;
        }

        digitCount += len;
    }

    cout << result;
}
