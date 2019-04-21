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
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int n;
    cin >> n;
    int a[n];
    REP(i, n)
    {
        cin >> a[i];
    }
    int ansn = *max_element(a, a + n);
    cout << ansn << " ";
    int ansk = *min_element(a, a + n);
    REP(i, n)
    {
        if (abs(ansn / 2 - ansk) > abs(ansn / 2 - a[i]))
        {
            ansk = a[i];
        }
    }
    cout << ansk << endl;
}