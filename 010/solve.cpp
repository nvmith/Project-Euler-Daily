#include <bits/stdc++.h>

using ll = long long;
using namespace std;

bool isPrime(int n)
{
    for(int i=2; i*i<=n;i++)
        if(n%i==0)
            return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 반복문을 이용해 매번 비교
    ll sum = 0;
    for(int i=2; i<=2000000; i++)
        if(isPrime(i)) sum += i;
    cout << sum << '\n';
    
    // 2. 에라토스테네스의 체로 푼 방식 - 미리 구해놓은 소수들의 배수들을 삭제하는 방식
    const int N = 2000000;
    vector<bool> isPrimeVector(N + 1, true);
    isPrimeVector[0] = isPrimeVector[1] = false;

    for (int i=2; i*i<=N; i++)
        if (isPrimeVector[i])
            for (int j=i*i; j<=N; j+=i)
                isPrimeVector[j] = false;

    sum = 0;
    for (int i=2; i<=N; i++)
        if (isPrimeVector[i]) sum += i;

    cout << sum << '\n';
}
