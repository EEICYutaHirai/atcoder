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
    int q;
    cin >> q;
    pint data[q];
    REP(i, q)
    {
        int a, b;
        cin >> a >> b;
        data[i].first = a;
        data[i].second = b;
    }
    REP(i, q)
    {
        int ans = 0;
    }
}