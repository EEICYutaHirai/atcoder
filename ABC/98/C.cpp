/*
title:C - Attention

url:

尺取り法で解く
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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int ans[n] = {};
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'E')
            ans[0]++;
    }

    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1];
        if (s[i] == 'E')
            ans[i]--;
        if (s[i - 1] == 'W')
            ans[i]++;
    }

    cout << *min_element(ans, ans + n) << endl;
}