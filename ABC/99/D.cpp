/*
title:D - Good Grid

url:https://abc099.contest.atcoder.jp/tasks/abc099_d

問題がややこしいだけの問題
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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int N, C;
    cin >> N >> C;
    int d[C][C];
    int c[N][N];

    for (int i = 0; i < C; i++)
        for (int j = 0; j < C; j++)
            cin >> d[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> c[i][j];
    //すべてC色に染めた時の、mod i の座標の違和感の合計を格納する
    int data[3][C];
    memset(data, 0, sizeof(data));
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                data[(j + k) % 3][i] += d[c[j][k] - 1][i];
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < C; j++)
        {
            for (int k = 0; k < C; k++)
            {
                if (i != j && j != k && k != i)
                    ans = min(ans, data[0][i] + data[1][j] + data[2][k]);
            }
        }
    }
    cout << ans << endl;
}