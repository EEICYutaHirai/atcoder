/*
title:

url:D - Remainder Reminder

数学的な考察で解けた。
O(n)で解けるのでは？という直感（見通し）が役に立った。
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

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007
#define int long long
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = k + 1; i <= n; i++)
    {
        int rm = (n + 1) / i;
        int quo = (n + 1) % i;
        ans += rm * (i - k) + MAX(0, quo - k);
    }
    //(0, ?)のものを数えてしまった分を消す
    if (k == 0)
    {
        ans -= n;
    }
    cout << ans << endl;
}