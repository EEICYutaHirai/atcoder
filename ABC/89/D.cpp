/*
title:D - Practical Skill Test

url:

二次元配列の要素がすべて異なるという、少し変わった（？）条件があるので、
1次元配列に変換して、計算量を減らすことができる。
ただ、それだけではダメで、累積和をとってさらに計算量を減らさないといけない。
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
    int h, w, d;
    cin >> h >> w >> d;
    pint *data = (pint *)malloc(sizeof(pint) * (300 * 300 + 1));
    REP(i, h)
    {
        REP(j, w)
        {
            int tmp;
            scanf("%d", &tmp);
            data[tmp] = make_pair(i, j);
        }
    }
    int *cm_sum = (int *)malloc(sizeof(int) * (300 * 300 + 1));
    for (int i = 0; i < d; i++)
    {
        cm_sum[i] = 0;
    }
    for (int i = d + 1; i <= h * w; i++)
    {
        int next = i;
        int pre = next - d;
        cm_sum[i] = abs(data[pre].first - data[next].first) +
                    abs(data[pre].second - data[next].second);
        cm_sum[i] += cm_sum[i - d];
    }

    int q = 0;
    cin >> q;
    pint problem[q];
    REP(i, q)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        problem[i] = make_pair(l, r);
    }
    REP(i, q)
    {
        int ans = cm_sum[problem[i].second] - cm_sum[problem[i].first];
        cout << ans << endl;
    }
    return 0;
}