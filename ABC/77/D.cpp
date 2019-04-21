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
#define int long long
#define MAX 15
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef pair<int, int> pint;
typedef long long ll;

vector<int> d;

int get_ans(int n, int index)
{
    if (index == d.size() - 1)
    {
        return n;
    }
    if (n == 0)
    {
        return 0;
    }
    return MIN(MIN(9, n / d[index]) + get_ans(n - d[index] * MIN(9, n / d[index]), index + 1), get_ans(n, index + 1));
}

signed main()
{
    int n;
    cin >> n;
    d.push_back(1);
    bool looped = false;
    for (int i = 1; i >= 0; i++)
    {
        int tmp;
        tmp = (d[i - 1] * 10) % n;
        if (find(d.begin(), d.end(), tmp) != d.end())
        {
            break;
        }
        d.push_back(tmp);
    }

    int ans = 0;
    sort(d.begin(), d.end(), greater<int>());

    if (d[d.size() - 1] == 0)
    {
        cout << 1 << endl;
        return 0;
    }

    cout << get_ans(n, 0) << endl;
    return 0;
}