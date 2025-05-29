#include <bits/stdc++.h>

using namespace std;

bool canBeWritten[28124];
vector<int> abundants;

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
    
    long long result = 0;
    
    for(int i=1;i<=28123;i++)
        if(d(i)>i)
            abundants.push_back(i);
    
   for (int i = 0; i < abundants.size(); i++)
   {
       for (int j = i; j < abundants.size(); j++)
       {
           int sum = abundants[i] + abundants[j];
           
           if(sum > 28123)
               break;
               
            canBeWritten[sum] = 1;
       }
   }
   
   for(int i=0; i<=28123;i++)
       if(!canBeWritten[i]) result += i;
   
   cout << result;
}