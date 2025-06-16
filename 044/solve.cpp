#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> pent;
    unordered_set<int> pset;
    
    for (int n = 1; n <= 10000; n++) 
    {
        int pn = n*(3*n-1)/2;
        pent.push_back(pn);
        pset.insert(pn);
    }
    
    int answer = INT_MAX;
    
    for (int j = 0; j < pent.size(); j++) 
    {
        for (int k = j + 1; k < pent.size(); k++) 
        {
            int pj = pent[j];
            int pk = pent[k];
    
            int sum = pj + pk;
            int diff = pk - pj;
    
            if (pset.count(sum) && pset.count(diff))
                answer = min(answer, diff);
        }
    }
    
    cout << answer;
}