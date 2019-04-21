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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int data[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> data[i];
    }
    int max = *max_element(data, data + 3);
    REP(i, 3)
    {
        data[i] -= max;
    }
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        while (!(data[i] == -1 || data[i] == 0))
        {
            data[i] += 2;
            ans++;
        }
    }
    while (!(data[0] == data[1] && data[1] == data[2]))
    {
        (*min_element(data, data + 3))++;
        (*min_element(data, data + 3))++;
        ans++;
    }
    cout << ans << endl;
}