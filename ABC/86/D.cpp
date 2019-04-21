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

template <class T>
vector<vector<T>> Imos2D(const vector<vector<T>> &a)
{
    int h = a.size();
    int w = a[0].size();
    vector<vector<T>> s(h + 1, vector<T>(w + 1, 0));
    rep(i, h) rep(j, w) s[i + 1][j + 1] = a[i][j];
    rep(i, h + 1) rep(j, w) s[i][j + 1] += s[i][j];
    rep(i, h) rep(j, w + 1) s[i + 1][j] += s[i][j];
    return s;
}

//元のでーたで(i-1,j-1)を頂点とし、１辺がh,wの長方形の中のsum
template <class T>
int sum(const std::vector<std::vector<T>> &s, int i, int j, int h, int w)
{
    return s[i + h][j + w] - s[i][j + w] + s[i][j] - s[i + h][j];
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> vwhite(2 * k, vector<int>(2 * k, 0));
    vector<vector<int>> vblack(2 * k, vector<int>(2 * k, 0));

    int sumb, sumw;
    sumb = sumw = 0;

    rep(i, n)
    {
        int x, y;
        string s;
        cin >> x >> y >> s;
        if (s[0] == 'B')
        {
            vblack[x % (2 * k)][y % (2 * k)]++;
            sumb++;
        }
        else
        {
            vwhite[x % (2 * k)][y % (2 * k)]++;
            sumw++;
        }
    }

    auto imos_white = Imos2D(vwhite);
    auto imos_black = Imos2D(vblack);

    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int answ = 0, ansb = 0;
            int x[5] = {i, 0, 0, i + k, i + k};
            int y[5] = {j, j + k, 0, j + k, 0};
            int dx[5] = {k, i, i, k - i, k - i};
            int dy[5] = {k, k - j, j, k - j, j};
            rep(k, 5)
            {
                answ += sum(imos_white, x[k], y[k], dx[k], dy[k]);
                ansb += sum(imos_black, x[k], y[k], dx[k], dy[k]);
            }
            ans = max({ans, answ + (sumb - ansb), ansb + (sumw - answ)});
        }
    }

    cout << ans << endl;
}