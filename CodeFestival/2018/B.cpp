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

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    int a, b;
    cin >> a >> b;
    bool is_a[n];
    fill(is_a, is_a + n, false);
    REP(i, m)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        for (int i = l; i <= r; i++)
        {
            is_a[i] = true;
        }
    }
    int ans = 0;
    int add = max(a, b);
    REP(i, n)
    {
        if (is_a[i])
        {
            ans += a;
        }
        else
        {
            ans += add;
        }
    }
    cout << ans << endl;
}