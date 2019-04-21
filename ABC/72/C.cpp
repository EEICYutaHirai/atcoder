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
    int data[100001] = {};
    rep(i, N)
    {
        int tmp;
        cin >> tmp;
        data[tmp]++;
    }

    int ans = 0;

    ans = max(ans, data[0] + data[1]);
    ans = max(ans, data[100000] + data[100000 - 1]);
    for (int i = 1; i < 100000; i++)
    {
        int tmp_ans = 0;
        tmp_ans += data[i];
        tmp_ans += data[i - 1];
        tmp_ans += data[i + 1];
        ans = max(ans, tmp_ans);
    }
    cout << ans << endl;
}