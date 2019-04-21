/*
title:

url:

あり本の区間スケジューリング問題に似ている。貪欲法で解ける
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

int main()
{
    int n;
    cin >> n;
    vector<pair<pint, bool>> p, q;
    int ans = 0;
    REP(i, n)
    {
        int a, b;
        cin >> a >> b;
        p.push_back(make_pair(make_pair(a, b), false));
    }
    REP(i, n)
    {
        int a, b;
        cin >> a >> b;
        q.push_back(make_pair(make_pair(a, b), false));
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    for (int i = p.size() - 1; i >= 0; i--)
    {
        int ymin = INF;
        int index = -1;
        for (int j = 0; j < n; j++)
        {
            if (p[i].first.first < q[j].first.first && p[i].first.second < q[j].first.second && q[j].second == false)
            {
                if (ymin > q[j].first.second)
                {
                    ymin = q[j].first.second;
                    index = j;
                }
            }
        }
        if (index != -1)
        {
            ans++;
            q[index].second = true;
        }
    }
    cout << ans << endl;
}