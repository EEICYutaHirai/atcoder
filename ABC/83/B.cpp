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
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        string tmp = to_string(i);
        int tmp_sum = 0;
        rep(i, tmp.size())
        {
            tmp_sum += tmp[i] - '0';
        }
        if (tmp_sum >= a && tmp_sum <= b)
        {
            ans += i;
        }
    }

    cout << ans << endl;
}