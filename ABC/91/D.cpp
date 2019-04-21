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
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

signed main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    REP(i, n)
    {
        cin >> a[i];
    }
    REP(i, n)
    {
        cin >> b[i];
    }
    int ans = 0;

    int tmpb[30][n];
    for (int i = 0; i < 30; i++)
    {
        int bpow = (1 << i);
        for (int j = 0; j < n; j++)
        {
            tmpb[i][j] = b[j] % (bpow * 2);
        }
        sort(tmpb[i], tmpb[i] + n);
    }

    for (int i = 0; i < 30; i++)
    {
        int bitsum = 0;
        for (int j = 0; j < n; j++)
        {
            int bpow = (1 << i);
            int tmpa = a[j] % (2 * bpow);
            //両方ともlower_boundでいい（以上、未満）
            //distanceを用いる方法もある。
            bitsum += lower_bound(tmpb[i], tmpb[i] + n, 2 * bpow - tmpa) -
                      lower_bound(tmpb[i], tmpb[i] + n, bpow - tmpa);
            bitsum += lower_bound(tmpb[i], tmpb[i] + n, 4 * bpow - tmpa) -
                      lower_bound(tmpb[i], tmpb[i] + n, 3 * bpow - tmpa);
            bitsum %= 2;
        }
        ans |= (bitsum << i);
    }
    cout << ans << endl;
}