/*
title:

url:

これがとけたのはうれしい
マスクビットなどうまく使えた
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

int N, M, R;

struct Edge
{
    int dst;
    int weight;
    Edge(int dst, int weight) : dst(dst), weight(weight) {}
};

vector<Edge> Edges[200];
int d[200];

void dijkstra(int s)
{
    priority_queue<pint, vector<pint>, greater<pint>> q;
    fill(d, d + 200, INF);
    d[s] = 0;
    q.push(pint(0, s));
    while (q.size())
    {
        pint p = q.top();
        q.pop();
        int v = p.second;
        if (d[v] < p.first)
        {
            continue;
        }
        for (int i = 0; i < Edges[v].size(); i++)
        {
            Edge e = Edges[v][i];
            if (d[e.dst] > d[v] + e.weight)
            {
                d[e.dst] = d[v] + e.weight;
                q.push(pint(d[e.dst], e.dst));
            }
        }
    }
}

int d_goal[8][8];
int solve(int n_visited, int now_pos)
{
    if ((1 << R) - 1 == n_visited)
    {
        return 0;
    }

    int res = INF;
    rep(i, R)
    {
        if (!(n_visited & (1 << i)))
        {
            res = min(res, solve(n_visited | (1 << i), i) + d_goal[i][now_pos]);
        }
    }
    return res;
}

int main()
{
    cin >> N >> M >> R;
    int goal[R];
    rep(i, R)
    {
        cin >> goal[i];
        goal[i]--;
    }
    rep(i, M)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        Edges[a].push_back(Edge(b, c));
        Edges[b].push_back(Edge(a, c));
    }

    rep(i, R)
    {
        dijkstra(goal[i]);
        rep(j, R)
        {
            d_goal[i][j] = d[goal[j]];
        }
    }

    int ans = INF;
    rep(i, R)
    {
        ans = min(ans, solve(0 | (1 << i), i));
    }
    cout << ans << endl;
}