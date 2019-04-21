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
    int n, k;
    cin >> n >> k;
    int x[n];
    rep(i, n)
    {
        cin >> x[i];
    }

    int ans = 0;
    rep(i, n)
    {
        ans += 2 * min(x[i], k - x[i]);
    }
    cout << ans << endl;
    return 0;
}