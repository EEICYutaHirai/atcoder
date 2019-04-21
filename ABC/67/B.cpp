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
    int data[N];
    rep(i, N)
    {
        cin >> data[i];
    }
    sort(data, data + N, greater<int>());
    int ans = 0;
    rep(i, K)
    {
        ans += data[i];
    }
    cout << ans << endl;
    return 0;
}