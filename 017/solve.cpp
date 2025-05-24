#include <bits/stdc++.h>

using namespace std;

string ones[] = {
    "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen"
};

string tens[] = {
    "", "", "twenty", "thirty", "forty", "fifty",
    "sixty", "seventy", "eighty", "ninety"
};

int numCount(int n)
{
    int count=0;
    
    if(n==1000)
        return string("onethousand").size();
    if(n>=100)
    {
        count += ones[n / 100].size();
        count += string("hundred").size();
        if (n % 100 != 0)
            count += string("and").size();
        n %= 100;
    }
    if (n >= 20) {
        count += tens[n / 10].size();
        count += ones[n % 10].size();
    } 
    else 
        count += ones[n].size();
    
    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int result = 0;
    
    for(int i=1;i<=1000;i++)
        result += numCount(i);
    
    cout << result;
}