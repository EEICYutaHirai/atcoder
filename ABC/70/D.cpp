/*
title:

url:

INFの値に注意
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
#define INF 10000000000000007
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

int N;

struct Edge
{
    int dst, cost;
    Edge(int dst, int cost) : dst(dst), cost(cost) {}
};

vector<Edge> Edges[100000];

int d[100000];
void dijkstra(int start)
{
    fill(d, d + 100000, INF);
    priority_queue<pint, vector<pint>, greater<pint>> q;
    q.push(pint(0, start));
    d[start] = 0;
    while (q.size())
    {
        pint p = q.top();
        q.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        rep(i, Edges[v].size())
        {
            Edge e = Edges[v][i];
            if (d[e.dst] > d[v] + e.cost)
            {
                d[e.dst] = d[v] + e.cost;
                q.push(pint(d[e.dst], e.dst));
            }
        }
    }
}

signed main()
{
    cin >> N;
    rep(i, N - 1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        Edges[a].push_back(Edge(b, c));
        Edges[b].push_back(Edge(a, c));
    }

    int Q, K;
    cin >> Q >> K;
    dijkstra(K - 1);
    int x[Q], y[Q];
    rep(i, Q)
    {
        cin >> x[i] >> y[i];
    }
    rep(i, Q)
    {
        cout << d[x[i] - 1] + d[y[i] - 1] << endl;
    }
    return 0;
}