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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool ans = false;
    if (abs(a - c) <= d)
        ans = true;
    if (abs(a - b) <= d && abs(b - c) <= d)
        ans = true;
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}