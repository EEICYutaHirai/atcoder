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
    int n;
    cin >> n;
    int data[2][n];
    REP(i, 2)
    {
        REP(j, n)
        {
            cin >> data[i][j];
        }
    }

    int ans[n];

    //iはいつ下に降りるか
    REP(i, n)
    {
        ans[i] = 0;
        for (int j = 0; j <= i; j++)
        {
            ans[i] += data[0][j];
        }
        for (int j = i; j < n; j++)
        {
            ans[i] += data[1][j];
        }
    }

    cout << *max_element(ans, ans + n) << endl;
}