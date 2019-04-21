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
    int N, K;
    cin >> N >> K;
    vector<int> data;
    rep(i, N)
    {
        int tmp;
        cin >> tmp;
        data.push_back(tmp);
    }
    sort(data.begin(), data.end());
    int ans = INF;

    for (int i = 0; i + K - 1 < N; i++)
    {
        int tmp_ans = data[i + K - 1] - data[i];
        if (tmp_ans < ans)
        {
            ans = tmp_ans;
        }
    }

    cout << ans << endl;
}