/*
title:

url:

わからなかったので解答を見た。
1次元の時から類推していけばとけたか...?
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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007
#define int long long

typedef pair<int, int> p_i;

signed main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int> sum[8];
    int x[8] = {1, -1, 1, 1, 1, -1, -1, -1};
    int y[8] = {1, 1, -1, 1, -1, 1, -1, -1};
    int z[8] = {1, 1, 1, -1, -1, -1, 1, -1};

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = 0; j < 8; j++)
        {
            sum[j].push(a * x[j] + b * y[j] + c * z[j]);
        }
    }

    int ans = -INF;
    for (int i = 0; i < 8; i++)
    {
        int tmp = 0;
        for (int j = 0; j < m; j++)
        {
            tmp += sum[i].top();
            sum[i].pop();
        }
        if (tmp > ans)
        {
            ans = tmp;
        }
    }
    cout << ans << endl;
}