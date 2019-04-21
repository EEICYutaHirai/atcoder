/*
title:

url:

WAの理由がよくわからない
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
#define INF 10000000000007
#define int long long

typedef pair<int, int> pint;
typedef long long ll;

struct Union_Find
{
    vector<int> data;
    Union_Find(int size) : data(size, -1) {}
    bool union_set(int x, int y)
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
    bool find_set(int x, int y)
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

signed main()
{
    int n, m;
    cin >> n >> m;
    int x[n];
    REP(i, n)
    {
        x[i] = -INF;
    }
    Union_Find u(n);

    int l[m], r[m], d[m];
    REP(i, m)
    {
        cin >> l[i] >> r[i] >> d[i];
        l[i]--;
        r[i]--;
    }

    //2個以上が同じグループに入ってたら、距離は決めとく
    REP(i, m)
    {
        if (u.find_set(l[i], r[i]))
        {
            if (x[r[i]] - x[l[i]] != d[i])
            {
                cout << "No" << endl;
                return 0;
            }
        }
        else if (u.size(l[i]) == 1 && u.size(r[i]) == 1)
        {
            x[l[i]] = 0;
            x[r[i]] = d[i];
            u.union_set(l[i], r[i]);
        }
        else if (u.size(l[i]) == 1)
        {
            x[l[i]] = x[r[i]] - d[i];
            u.union_set(l[i], r[i]);
        }
        else if (u.size(r[i]) == 1)
        {
            x[r[i]] = x[l[i]] + d[i];
            u.union_set(l[i], r[i]);
        }
        else
        {
            //要素が複数あるグループが合併する時、片方を全てずらす
            //重複する要素はない
            x[r[i]] = x[l[i]] + d[i];
            for (int j = 0; j < i; j++)
            {
                if (l[j] == r[i])
                    x[r[j]] = x[l[j]] + d[j];
                else if (r[j] == r[i])
                    x[l[j]] = x[r[j]] - d[j];
            }
            u.union_set(l[i], r[i]);
        }
    }
    cout << "Yes" << endl;
}