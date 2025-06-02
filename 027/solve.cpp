#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) 
{
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int maxA = 0, maxB = 0, maxCount = 0;

    for (int a = -999; a < 1000; a++) 
    {
        for (int b = 2; b < 1000; b++) 
        {
            if (!isPrime(b)) continue;

            int n = 0;
            while (isPrime(n * n + a * n + b)) {
                n++;
            }

            if (n > maxCount) {
                maxCount = n;
                maxA = a;
                maxB = b;
            }
        }
    }
    cout << (maxA * maxB);
}
