/*
title:

url:D - Grid Repainting

全体の白色の数から最短経路を引けばいい。
最短経路を求めるには、幅優先探索を用いる。
アリ本の迷路の最短路問題とほぼ同じ
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
    int h, w;
    cin >> h >> w;
    string data[h];
    REP(i, h)
    {
        cin >> data[i];
    }

    queue<pint> q;
    q.push(make_pair(0, 0));
    int d[h][w];
    int n_white = 0;
    REP(i, h)
    {
        REP(j, w)
        {
            d[i][j] = INF;
            if (data[i][j] == '.')
                n_white++;
        }
    }
    d[0][0] = 1;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (q.size())
    {
        pint tmp = q.front();
        q.pop();
        if (tmp.first == h - 1 && tmp.second == w - 1)
            break;
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.first + dx[i];
            int ny = tmp.second + dy[i];
            if (0 <= nx && nx < h && 0 <= ny && ny < w &&
                data[nx][ny] != '#' && d[nx][ny] == INF)
            {
                d[nx][ny] = d[tmp.first][tmp.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    if (d[h - 1][w - 1] == INF)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        cout << n_white - d[h - 1][w - 1] << endl;
    }
}