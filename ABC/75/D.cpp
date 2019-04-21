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

typedef long long ll;
typedef pair<ll, ll> pint;

template <class T>
std::vector<std::vector<T>> Imos2D(const std::vector<std::vector<T>> &a)
{
    int h = a.size(), w = a[0].size();
    std::vector<std::vector<T>> s(h + 1, std::vector<T>(w + 1, 0));
    rep(i, h) rep(j, w) s[i + 1][j + 1] = a[i][j];
    rep(i, h + 1) rep(j, w) s[i][j + 1] += s[i][j];
    rep(i, h) rep(j, w + 1) s[i + 1][j] += s[i][j];
    return s;
}

//(i, j)を始点とし、そこからi,j含めてh,wこの点を含む長方形内の累積和
template <class T>
int sum(const std::vector<std::vector<T>> &s, int i, int j, int h, int w)
{
    return s[i + h][j + w] - s[i][j + w] + s[i][j] - s[i + h][j];
}

signed main()
{
    int n, k;
    cin >> n >> k;
    pint tmp_x[n], tmp_y[n];
    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        tmp_x[i] = pint(x, i);
        tmp_y[i] = pint(y, i);
    }
    sort(tmp_x, tmp_x + n);
    sort(tmp_y, tmp_y + n);

    vector<vector<int>> is_exist(n, vector<int>(n, 0));
    int nx[n], ny[n];
    rep(i, n)
    {
        rep(j, n)
        {
            if (tmp_x[i].second == tmp_y[j].second)
            {
                is_exist[i][j] = 1;
                nx[i] = tmp_x[i].first;
                ny[j] = tmp_y[j].first;
            }
        }
    }

    auto imos = Imos2D(is_exist);
    int ans = (int)1e19;
    rep(i, n)
    {
        rep(j, n)
        {
            for (int p = 1; p + i <= n; p++)
            {
                for (int q = 1; q + j <= n; q++)
                {
                    if (sum(imos, i, j, p, q) >= k)
                    {
                        ans = min(ans, (nx[p + i - 1] - nx[i]) * (ny[q + j - 1] - ny[j]));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}