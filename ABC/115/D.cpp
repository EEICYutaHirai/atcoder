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

int solve(int n, int x)
{
    if (n == 0)
    {
        return 1;
    }
    if (x == 1)
    {
        return 0;
    }
    else if (x <= (1ull << (n + 1)) - 2)
    {
        return solve(n - 1, x - 1);
    }
    else if (x == (1ull << (n + 1)) - 1)
    {
        return (1ull << n);
    }
    else if (x <= (1ull << (n + 2)) - 4)
    {
        return (1ull << n) + solve(n - 1, x - (1ull << (n + 1)) + 1);
    }
    else
    {
        return (1ull << (n + 1)) - 1;
    }
}

signed main()
{
    int N, X;
    cin >> N >> X;
    cout << solve(N, X) << endl;
}