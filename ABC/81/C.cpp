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
    int data[(int)2e5 + 1] = {};
    int n, k;
    cin >> n >> k;
    rep(i, n)
    {
        int tmp;
        cin >> tmp;
        data[tmp]++;
    }

    priority_queue<int, vector<int>, greater<int>> q;
    rep(i, (int)2e5 + 1)
    {
        if (data[i] > 0)
        {
            q.push(data[i]);
        }
    }

    int ans = 0;
    while (q.size() > k)
    {
        ans += q.top();
        q.pop();
    }

    cout << ans << endl;
}