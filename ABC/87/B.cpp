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
    int ncoin[3];
    int coin[3] = {500, 100, 50};
    int x;
    REP(i, 3)
    {
        cin >> ncoin[i];
    }
    cin >> x;

    int ans = 0;
    for (int i = 0; i <= ncoin[0]; i++)
    {
        for (int j = 0; j <= ncoin[1]; j++)
        {
            for (int k = 0; k <= ncoin[2]; k++)
            {
                int sum = i * coin[0] + j * coin[1] + k * coin[2];
                if (sum == x)
                    ans++;
            }
        }
    }
    cout << ans << endl;
}