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
typedef pair<int, pint> ppint;
typedef long long ll;

signed main()
{
    int N;
    cin >> N;
    vector<pint> data_x, data_y;
    rep(i, N)
    {
        int x, y;
        cin >> x >> y;
        data_x.push_back(pint(x, i));
        data_y.push_back(pint(y, i));
    }
    sort(data_x.begin(), data_x.end());
    sort(data_y.begin(), data_y.end());
    vector<ppint> weight;
    for (int i = 0; i < N - 1; i++)
    {
        weight.push_back(ppint(data_x[i + 1].first - data_x[i].first, pint(data_x[i].second, data_x[i + 1].second)));
        weight.push_back(ppint(data_y[i + 1].first - data_y[i].first, pint(data_y[i].second, data_y[i + 1].second)));
    }
    sort(weight.begin(), weight.end());
    vector<int> e_data;
    int ans = 0;

    for (int i = 0; i < weight.size(); i++)
    {
        auto res1 = find(e_data.begin(), e_data.end(), weight[i].second.first);
        auto res2 = find(e_data.begin(), e_data.end(), weight[i].second.second);
        if (res1 == e_data.end() && res2 == e_data.end())
        {
            ans += weight[i].first;
            e_data.push_back(weight[i].second.first);
            e_data.push_back(weight[i].second.second);
        }
        else if (res1 == e_data.end() && res2 != e_data.end())
        {
            ans += weight[i].first;
            e_data.push_back(weight[i].second.first);
        }
        else if (res1 != e_data.end() && res2 == e_data.end())
        {
            ans += weight[i].first;
            e_data.push_back(weight[i].second.second);
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
}