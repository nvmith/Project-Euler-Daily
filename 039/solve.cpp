#include <bits/stdc++.h>

using namespace std;

bool isTri(int a, int b, int c)
{
    return (a * a + b * b == c * c);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int maxCnt = 0;
    int result = 0;
    
    for(int p=12;p<=1000;p++)
    {
        int cnt = 0;
        for(int a=1;a<p/3;a++)
        {
            for(int b=a+1;b<(p-a)/2;b++)
            {
                int c = p - a - b;
                
                if(c>b && isTri(a,b,c))
                    cnt++;
            }
        }
        if(maxCnt < cnt)
        {
            maxCnt = cnt;
            result = p;
        }
    }
    
    cout << result;
}