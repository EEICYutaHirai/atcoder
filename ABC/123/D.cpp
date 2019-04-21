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

#define int ll

signed main()
{
    int X[3];
    int K;
    for (int i = 0; i < 3; i++)
    {
        cin >> X[i];
    }
    cin >> K;
    vector<int> taste[3];
    vector<int> sum_data;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < X[i]; j++)
        {
            int tmp;
            cin >> tmp;

            taste[i].push_back(tmp);
        }
    }

    for (int i = 0; i < X[0]; i++)
    {
        for (int j = 0; j < X[1]; j++)
        {
            sum_data.push_back(taste[0][i] + taste[1][j]);
        }
    }

    sort(taste[2].begin(), taste[2].end(), greater<int>());
    sort(sum_data.begin(), sum_data.end(), greater<int>());

    priority_queue<int> ans;
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < K; j++)
        {
            if (i >= sum_data.size() || j >= taste[2].size())
                continue;
            ans.push(sum_data[i] + taste[2][j]);
        }
    }
    for (int i = 0; i < K; i++)
    {
        cout << ans.top() << endl;
        ans.pop();
    }
}