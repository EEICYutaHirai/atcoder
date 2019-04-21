/*
title:

url:
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <queue>
#include <limits>
#include <string>
#include <utility>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int d, x;
    cin >> d >> x;
    int a[n];
    REP(i, n)
    {
        cin >> a[i];
    }
    int ans = n + x;
    for (int i = 0; i < n; i++)
    {
        int day = 1;
        while (day + a[i] <= d)
        {
            day += a[i];
            ans++;
        }
    }
    cout << ans << endl;
}