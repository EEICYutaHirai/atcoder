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

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int n, X;
    cin >> n >> X;
    int x[n];
    bool used[n];

    int ans = 0;
    ans += X * n;
    fill(used, used + n, false);
    int nlarge = 0;
    rep(i, n)
    {
        cin >> x[i];
        if (x[i] >= X / 2)
            nlarge++;
    }

    rep(i, n)
    {
        }
}