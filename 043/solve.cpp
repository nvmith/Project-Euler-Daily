#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> n = {0,1,2,3,4,5,6,7,8,9};
    sort(n.begin(), n.end());
    
    int p[7] = {2,3,5,7,11,13,17};
    long long result = 0;
    
    do
    {
        bool pass = true;
        
        for(int i=0;i<7;i++)
        {
            int tmp = n[i+1]*100 + n[i+2]*10 + n[i+3];
            if(tmp%p[i]!=0)
            {
                pass = false;
                break;
            }
        }
        
        if(pass) 
        {
            long long num = 0;
            
            for (int i = 0; i < 10; i++) 
                num = num * 10 + n[i];
            result += num;
        }

    }while(next_permutation(n.begin(),n.end()));
    
    cout << result;
}