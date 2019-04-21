/*
title:

url:

ベルマンフォード法のいい練習問題
計算量が心配だったが、問題なかった。
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
    int h, w;
    cin >> h >> w;
    //i->jの書き換え
    int c[10][10];
    rep(i, 10)
    {
        rep(j, 10)
        {
            cin >> c[i][j];
        }
    }
    int kabe[h][w];
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> kabe[i][j];
        }
    }

    //最短の書き換え
    //ベルマンフォード
    int d[10][10];
    rep(i, 10)
    {
        fill(d[i], d[i] + 10, INF);
        d[i][i] = 0;
        while (true)
        {
            bool update = false;
            rep(j, 10)
            {
                rep(k, 10)
                {
                    if (d[i][j] != INF && d[i][k] > d[i][j] + c[j][k])
                    {
                        d[i][k] = d[i][j] + c[j][k];
                        update = true;
                    }
                }
            }
            if (!update)
                break;
        }
    }

    int ans = 0;
    rep(i, h)
    {
        rep(j, w)
        {
            if (kabe[i][j] == -1)
                continue;
            else
                ans += d[kabe[i][j]][1];
        }
    }
    cout << ans << endl;
}