#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int a=1;a<1000;a++)
    {
        for(int b=a+1;b<1000-a;b++)
        {
            int c = 1000 - a - b;
            if(a*a + b*b == c*c)
            {
                cout << a * b * c;
                return 0;
            }
        }
    }
}