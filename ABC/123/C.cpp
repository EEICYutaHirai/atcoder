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
    int N;
    cin >> N;
    int data[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> data[i];
    }
    sort(data, data + 5);
    int ans = 5;
    if (N % data[0] == 0)
    {
        ans += N / data[0] - 1;
    }
    else
    {
        ans += N / data[0];
    }

    cout << ans << endl;
}