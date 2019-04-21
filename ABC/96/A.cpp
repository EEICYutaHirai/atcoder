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
    int a, b;
    cin >> a >> b;
    int m = 1;
    int d = 1;
    int ans = 0;
    for (int i = 0; i < 365; i++)
    {
        if (d == 29 && m == 2)
        {
            m++;
            d = 1;
        }
        if (d == 31 && (m == 4 || m == 6 || m == 9 || m == 11))
        {
            m++;
            d = 1;
        }
        if (d == 32 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
        {
            m++;
            d = 1;
        }
        if (m == d)
        {
            ans++;
        }
        if (m == a && d == b)
        {
            break;
        }
        d++;
    }
    cout << ans << endl;
}