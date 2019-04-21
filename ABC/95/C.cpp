/*
title:C - Half and Half

url:https://abc095.contest.atcoder.jp/tasks/arc096_a

方針
atcoder begeinner contestのstrange bank に似ている問題
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
    int a, b, c;
    int x, y;
    cin >> a >> b >> c;
    cin >> x >> y;

    int ans = 0;
    int nmin = min(x, y);
    ans += min(a * nmin + b * nmin, c * nmin * 2);
    if (nmin == x)
    {
        ans += min(b * (y - nmin), c * 2 * (y - nmin));
    }
    else
    {
        ans += min(a * (x - nmin), c * 2 * (x - nmin));
    }
    cout << ans << endl;
}