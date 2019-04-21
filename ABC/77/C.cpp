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

signed main()
{
    int n;
    cin >> n;
    vector<int> a, b, c;
    rep(i, n)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    rep(i, n)
    {
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }
    rep(i, n)
    {
        int tmp;
        cin >> tmp;
        c.push_back(tmp);
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());

    vector<int> n_use_b(n, 0);
    int index = 0;
    for (int i = 0; i < b.size(); i++)
    {
        while (index <= n && c[index] > b[i])
        {
            index++;
        }
        n_use_b[i] = index;
    }

    index = 0;
    int pre = 0;
    vector<int> n_use_a(n, 0);
    for (int i = 0; i < a.size(); i++)
    {
        while (index <= n && b[index] > a[i])
        {
            index++;
        }
        n_use_a[i] = index;
    }

    int ans = 0;
    vector<int> n_ans(n, 0);
    for (int j = 0; j < n_use_a[0]; j++)
    {
        ans += n_use_b[j];
    }
    n_ans[0] = ans;

    for (int i = 0; i < n - 1; i++)
    {
        n_ans[i + 1] += n_ans[i];
        for (int j = n_use_a[i]; j < n_use_a[i + 1]; j++)
        {
            n_ans[i + 1] += n_use_b[j];
        }
        ans += n_ans[i + 1];
    }
    cout << ans << endl;
}