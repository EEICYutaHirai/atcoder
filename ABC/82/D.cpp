/*
title:

url:

kこの数字が与えられたとき、それを足し引きしてxにできるかどうか
O(2^k)になるように思えるが、動的計画法を用いるとO(k^2)になる。
O(2^k)の計算方法は、再帰で解くことになるだろうが、これは動的計画法でも解くことができるのだ、
という発想が必要だった。(?)
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
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;

    vector<int> xmoves, ymoves;
    bool nextx = true;
    for (int i = 0; i < s.size();)
    {
        if (s[i] == 'T')
        {
            i++;
            nextx = !nextx;
        }
        else
        {
            int count = 0;
            while (i < s.size() && s[i] == 'F')
            {
                i++;
                count++;
            }
            if (nextx)
            {
                xmoves.push_back(count);
            }
            else
            {
                ymoves.push_back(count);
            }
        }
    }

    if (xmoves.size() == 0)
    {
        xmoves.push_back(0);
    }
    if (ymoves.size() == 0)
    {
        ymoves.push_back(0);
    }

    const int maxn = 16030;
    int xdp[xmoves.size()][maxn];
    int ydp[ymoves.size()][maxn];

    rep(i, xmoves.size())
    {
        fill(xdp[i], xdp[i] + maxn, false);
    }
    rep(i, ymoves.size())
    {
        fill(ydp[i], ydp[i] + maxn, false);
    }

    if (s[0] == 'T')
    {
        xdp[0][xmoves[0] + maxn / 2] = true;
        xdp[0][-xmoves[0] + maxn / 2] = true;
    }
    else
    {
        xdp[0][xmoves[0] + maxn / 2] = true;
    }
    xdp[0][xmoves[0] + maxn / 2] = true;
    ydp[0][ymoves[0] + maxn / 2] = true;
    ydp[0][-ymoves[0] + maxn / 2] = true;

    for (int i = 1; i < xmoves.size(); i++)
    {
        rep(j, maxn)
        {
            if (xdp[i - 1][j])
            {
                xdp[i][j + xmoves[i]] = true;
                xdp[i][j - xmoves[i]] = true;
            }
        }
    }

    for (int i = 1; i < ymoves.size(); i++)
    {
        rep(j, maxn)
        {
            if (ydp[i - 1][j])
            {
                ydp[i][j + ymoves[i]] = true;
                ydp[i][j - ymoves[i]] = true;
            }
        }
    }

    if (xdp[xmoves.size() - 1][x + maxn / 2] && ydp[ymoves.size() - 1][y + maxn / 2])
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}