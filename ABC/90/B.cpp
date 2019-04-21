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

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; i++)
    {
        string tmp = to_string(i);
        string rvs = "";
        for (int i = tmp.size() - 1; i >= 0; i--)
        {
            rvs = rvs + tmp[i];
        }
        if (rvs == tmp)
            ans++;
    }
    cout << ans << endl;
}