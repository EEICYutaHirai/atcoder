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

typedef pair<int, int> pint;
typedef long long ll;

int N;
int data[300][300];
int d[300];
bool has_road[300][300];

bool bellman(int start)
{
    fill(d, d + N, INF);
    d[start] = 0;
    bool used_road[N][N];
    rep(i, N)
    {
        fill(used_road[i], used_road[i] + N, false);
    }
    priority_queue<pint, vector<pint>, greater<pint>> q;
    q.push(pint(0, start));
    while (q.size())
    {
        pint p = q.top();
        q.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        rep(i, N)
        {
            if (d[i] > d[v] + data[v][i])
            {
                used_road[i][v] = true;
                d[i] = d[v] + data[v][i];
                q.push(pint(d[i], i));
            }
        }
    }
    rep(j, N)
    {
        if (data[start][j] != d[j])
        {
            return false;
        }
    }
    return true;
}

signed main()
{
    cin >> N;
    rep(i, N)
    {
        rep(j, N)
        {
            cin >> data[i][j];
        }
    }

    rep(i, N)
    {
        fill(has_road[i], has_road[i] + N, false);
    }
    rep(i, N)
    {
        if (!bellman(i))
        {
            cout << -1 << endl;
            return 0;
        }
    }

    int ans = 0;
    /*
    rep(i, N)
    {
        for (int j = i + 1; j < N; j++)
        {
            int tmp = data[i][j];
            data[i][j] = INF;
            data[j][i] = INF;
            bellman(i);
            if (d[j] == tmp)
            {
                has_road[i][j] = false;
            }
            data[i][j] = data[j][i] = tmp;
        }
    }
    */
    rep(i, N)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (has_road[i][j])
            {
                ans += data[i][j];
            }
        }
    }
    cout << ans << endl;
}