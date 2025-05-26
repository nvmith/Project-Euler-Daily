#include <bits/stdc++.h>

using namespace std;

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int daysInMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    int day = 1;
    int cnt = 0;

    for (int year = 1900; year <= 2000; year++) {
        for (int month = 1; month <= 12; month++) {
            if (year >= 1901 && day % 7 == 0)
                cnt++;

            int days = daysInMonth[month];
            if (month == 2 && isLeap(year)) days++;

            day += days;
        }
    }

    cout << cnt;
}
