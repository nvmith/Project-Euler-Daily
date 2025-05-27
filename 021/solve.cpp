#include <bits/stdc++.h>

using namespace std;

int arr[10001];

int d(int n)
{
    int sum = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i)
                sum += n / i;
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int result = 0;
    
    // 🧠 개선 아이디어:
    // - 아래와 같은 체 방식도 가능함:
    /*
    vector<int> sumDiv(LIMIT + 1, 1);
    for (int i = 2; i <= LIMIT / 2; ++i) {
        for (int j = i * 2; j <= LIMIT; j += i) {
            sumDiv[j] += i;
        }
    }
    */
    
    for(int i=1;i<=10000;i++)
        arr[i] = d(i);
    
    for(int i=1; i<=10000; i++)
        if(i != arr[i] && arr[i] <= 10000 && i == arr[arr[i]])
            result += i;
    
    cout << result;
}