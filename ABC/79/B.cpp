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
#include <iterator>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

int dp[87];

int luca(int n)
{
    if (n == 0)
    {
        return 2;
    }
    if (n == 1)
    {
        return 1;
    }
    if (dp[n] >= 0)
    {
        return dp[n];
    }
    return (dp[n] = luca(n - 1) + luca(n - 2));
}

signed main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << luca(n) << endl;
}