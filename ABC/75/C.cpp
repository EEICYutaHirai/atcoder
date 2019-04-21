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

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    bool data[n][n];
    rep(i, n)
    {
        rep(j, n)
        {
            data[i][j] = false;
        }
    }
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        data[a][b] = true;
        data[b][a] = true;
    }

    int ans = 0;
    rep(i, n)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (data[i][j])
            {
                data[i][j] = false;
                data[j][i] = false;
                bool seen[n];
                fill(seen, seen + n, false);
                queue<int> q;
                q.push(0);
                while (q.size())
                {
                    int tmp = q.front();
                    q.pop();
                    seen[tmp] = true;
                    rep(k, n)
                    {
                        if (data[tmp][k] == true && seen[k] == false)
                        {
                            q.push(k);
                        }
                    }
                }
                data[i][j] = true;
                data[j][i] = true;
                bool is_good = true;
                rep(k, n)
                {
                    if (!seen[k])
                    {
                        is_good = false;
                        break;
                    }
                }
                if (!is_good)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}