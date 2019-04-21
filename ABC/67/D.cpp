/*
title:

url:

これが一発で解けたのはかなりうれしい
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

struct Edge
{
    int to;
    Edge(int to) : to(to) {}
};

int main()
{
    int N;
    cin >> N;
    vector<Edge> Edges[N];
    rep(i, N - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        Edges[a].push_back(Edge(b));
        Edges[b].push_back(Edge(a));
    }

    //0->null, 1=black, -1=white
    int color[N] = {};
    queue<pint> q;
    q.push(pint(0, 1));
    q.push(pint(N - 1, -1));
    while (q.size())
    {
        pint p = q.front();
        q.pop();
        if (color[p.first] != 0)
            continue;
        color[p.first] = p.second;
        rep(i, Edges[p.first].size())
        {
            int v = Edges[p.first][i].to;
            q.push(pint(v, p.second));
        }
    }

    int black = 0;
    int white = 0;
    rep(i, N)
    {
        if (color[i] == 1)
        {
            black++;
        }
        else
        {
            white++;
        }
    }
    if (black > white)
    {
        cout << "Fennec" << endl;
    }
    else if (black < white)
    {
        cout << "Snuke" << endl;
    }
    else
    {
        if (N % 2 == 0)
        {
            cout << "Snuke" << endl;
        }
        else
        {
            cout << "Fennec" << endl;
        }
    }
    return 0;
}