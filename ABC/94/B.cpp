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
    int n, m, x;
    cin >> n >> m >> x;
    int cost[m];
    REP(i, m)
    {
        cin >> cost[i];
    }
    int ans = 0;
    int lans = 0;
    int rans = 0;
    for (int i = 0; i < m; i++)
    {
        if (cost[i] < x)
        {
            lans++;
        }
        else
        {
            rans++;
        }
    }
    ans = min(lans, rans);
    cout << ans << endl;
}