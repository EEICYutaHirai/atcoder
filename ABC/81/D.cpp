/*
title:

url:

すべてが正、あるいは負の時を考えると、これは、すぐに整列できることが分かる（n-1回）
なので、すべてを生にすればいいが、これもn-1かいでできる
簡単？
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
    int data[n];
    rep(i, n)
    {
        int tmp;
        cin >> tmp;
        data[i] = tmp;
    }

    auto max_ite = max_element(data, data + n);
    auto min_ite = min_element(data, data + n);
    int max_data = *max_ite;
    int min_data = *min_ite;

    vector<pint> ans;
    if (!(min_data > 0 || max_data < 0))
    {
        if (abs(min_data) > abs(max_data))
        {
            rep(i, n)
            {
                ans.push_back(pint(distance(data, min_ite) + 1, i + 1));
                data[i] += min_data;
            }
        }
        else
        {
            rep(i, n)
            {
                ans.push_back(pint(distance(data, max_ite) + 1, i + 1));
                data[i] += max_data;
            }
        }
    }

    if (*min_element(data, data + n) >= 0)
    {
        rep(i, n - 1)
        {
            ans.push_back(pint(i + 1, i + 2));
            data[i + 1] += data[i];
        }
    }
    else
    {
        for (int i = n - 1; i >= 1; i--)
        {
            ans.push_back(pint(i + 1, i));
            data[i - 1] += data[i];
        }
    }

    cout << ans.size() << endl;
    rep(i, ans.size())
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}