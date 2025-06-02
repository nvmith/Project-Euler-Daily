#include <bits/stdc++.h>

using namespace std;

int CountRepeat(int n)
{
    int cur = 1;
    int cnt = 0;
    vector<bool> visited(n,false);
    
    while(cur && !visited[cur])
    {
        visited[cur] = true;
        cur = (cur*10) % n;
        cnt++;
    }
    
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int maxRepeat = 0;
    int maxRepeatNum;
    
    for(int i=2;i<=1000;i++)
    {
        int cr = CountRepeat(i);
        if(cr > maxRepeat)
        {
            maxRepeatNum = i;
            maxRepeat = cr;
        }
    }
    
    cout << maxRepeatNum;
}