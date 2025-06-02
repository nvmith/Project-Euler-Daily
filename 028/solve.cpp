#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int step = 2;
    int corners_remaining = 4;
    int result = 1;
    
    for (int corner = 3; corner <= 1001 * 1001; corner += step)
    {
        result += corner;
        corners_remaining--;
    
        if (corners_remaining == 0)
        {
            corners_remaining = 4;
            step += 2;
        }
    }
    
    cout << result;
}
