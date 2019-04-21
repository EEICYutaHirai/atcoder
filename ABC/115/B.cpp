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
    vector<int> data;
    rep(i, N)
    {
        int tmp;
        cin >> tmp;
        data.push_back(tmp);
    }
    sort(data.begin(), data.end());
    int ans = 0;
    for (int i = 0; i < N - 1; i++)
    {
        ans += data[i];
    }
    ans += data[N - 1] / 2;
    cout << ans << endl;
}