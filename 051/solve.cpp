#include <bits/stdc++.h>

using namespace std;

vector<bool> isPrime(1000001, true);

int changeNum(string s, int target, int origin)
{
    // target 값이 들어 있는 자리 인덱스를 저장
    vector<int> targetPositions;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] - '0' == target)
            targetPositions.push_back(i);
    }

    int sz = targetPositions.size();

    // 가능한 자리 조합을 모두 탐색, mask가 0일땐 아무것도 바꾸지 않는 것이라 제외
    for (int mask = 1; mask < (1 << sz); mask++)
    {
        int count = 0;
        bool include_origin = false;

        for (int digit = 0; digit <= 9; digit++)
        {
            string tmp = s;
            for (int i = 0; i < sz; i++)
                if (mask & (1 << i))
                    tmp[targetPositions[i]] = digit + '0';
            
            if (tmp[0] == '0') continue;

            int num = stoi(tmp);
            if (isPrime[num])
            {
                count++;
                if (num == origin) include_origin = true;
            }
        }
        if (count >= 8 && include_origin)
            return 1;
    }
    
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> primes;

    // 에라토스테네스의 체
    for (int i = 2; i * i <= 1000000; i++)
    {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= 1000000; j += i)
            isPrime[j] = false;
    }
    
    for (int i = 2; i <= 1000000; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }

    for (int i = 0; i < primes.size(); i++)
    {
        int num = primes[i];
        string s = to_string(num);

        for (int digit = 0; digit <= 9; digit++)
        {
            if (changeNum(s, digit, num))
            {
                cout << num;
                return 0;
            }
        }
    }
}
