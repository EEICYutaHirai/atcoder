/*
title:

url:

あんま綺麗な実装じゃない
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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> p_i;

int main()
{
    int n, k;
    cin >> n >> k;

    int m = 0;
    while (true)
    {
        int min = m * k - (m - 1);
        int max = (m + 1) * k - m;
        m++;
        if (min <= n && n <= max)
        {
            break;
        }
    }
    cout << m << endl;
}