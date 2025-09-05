#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPrime(ll n)
{
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

ll concatNum(int a, int b)
{
    string sa = to_string(a);
    string sb = to_string(b);
    return stoll(sa + sb);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int limit = 10000;
    vector<bool> is(limit + 1, true);
    is[0] = false; is[1] = false;
    for (int i = 2; i * i <= limit; i++)
    {
        if (!is[i]) continue;
        for (int j = i * i; j <= limit; j += i) 
            is[j] = false;
    }

    vector<int> primes;
    for (int i = 2; i <= limit; i++)
        if (is[i] && i != 2 && i != 5) 
            primes.push_back(i);

    ll bestSum = LLONG_MAX;
    int n = (int)primes.size();

    for (int a = 0; a < n; a++)
    {
        if (1LL * primes[a] * 5 >= bestSum) break;

        for (int b = a + 1; b < n; b++)
        {
            if (!isPrime(concatNum(primes[a], primes[b]))) continue;
            if (!isPrime(concatNum(primes[b], primes[a]))) continue;

            for (int c = b + 1; c < n; c++)
            {
                bool ok = true;
                for (int x : {a, b})
                {
                    if (!isPrime(concatNum(primes[x], primes[c])) ||
                        !isPrime(concatNum(primes[c], primes[x])))
                        ok = false; break;
                }
                if (!ok) continue;

                for (int d = c + 1; d < n; d++)
                {
                    ok = true;
                    for (int x : {a, b, c})
                    {
                        if (!isPrime(concatNum(primes[x], primes[d])) ||
                            !isPrime(concatNum(primes[d], primes[x])))
                            ok = false; break;
                    }
                    if (!ok) continue;

                    for (int e = d + 1; e < n; e++)
                    {
                        ok = true;
                        for (int x : {a, b, c, d})
                        {
                            if (!isPrime(concatNum(primes[x], primes[e])) ||
                                !isPrime(concatNum(primes[e], primes[x])))
                                ok = false; break;
                        }
                        if (!ok) continue;

                        ll sum = 1LL * primes[a] + primes[b] + primes[c] + primes[d] + primes[e];
                        if (sum < bestSum) bestSum = sum;
                    }
                }
            }
        }
    }

    cout << bestSum;
}
