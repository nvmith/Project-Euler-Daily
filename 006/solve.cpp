#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main()
{
    // 1. 수학 공식 기반 풀이 (O(1))
    
    int n = 100;

    ll square_of_sum = n * (n + 1) / 2;
    square_of_sum *= square_of_sum;
    ll sum_of_squares = n * (n + 1) * (2 * n + 1) / 6;
    ll result = square_of_sum - sum_of_squares;
    cout << result << '\n';
    
    // 2. 직관적 반복문 풀이 (O(n^2)) - 공식을 몰라도 접근 가능
    
    result = 0;
    int sum=0;
    
    for(int i=1;i<=100;i++)
    {
        sum = 0;
        for(int j=1;j<=100;j++)
        {
            if(j==i)
                continue;
            sum+=j;
        }
        result += sum * i;
    }
    
    cout << result << '\n';
}