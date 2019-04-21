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
    int N;
    cin >> N;
    int s[N];
    int a[N];
    rep(i, N)
    {
        cin >> s[i];
    }
    rep(i, N)
    {
        cin >> a[i];
    }
    int ans = 0;
    rep(i, N)
    {
        ans = max(ans, a[i] * s[i]);
    }
    cout << ans << endl;
    return 0;
}