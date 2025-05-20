#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a = 1, b = 2;
    int sum = 2;

    while (1) {
        int next = a + b;
        if (next > 4000000) break;
        if (next % 2 == 0) sum += next;
        a = b;
        b = next;
    }
    cout << sum;
}
