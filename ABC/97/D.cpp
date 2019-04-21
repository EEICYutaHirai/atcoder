/*
title:

url:

方針:
交換可能な組み合わせ、(i, j), (j, k)が存在するならば、(i, k)も可能であると仮定してとく
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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

struct UnionFind
{
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unionSet(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x != y)
        {
            if (data[y] < data[x])
                swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y)
    {
        return root(x) == root(y);
    }
    int root(int x)
    {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x)
    {
        return -data[root(x)];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    int data[n];
    UnionFind u(n);
    REP(i, n)
    {
        cin >> data[i];
    }
    REP(i, m)
    {
        int a, b;
        cin >> a >> b;
        u.unionSet(a - 1, b - 1);
    }
    int ans = 0;
    REP(i, n)
    {
        if (u.findSet(i, data[i] - 1))
            ans++;
    }
    cout << ans << endl;
}