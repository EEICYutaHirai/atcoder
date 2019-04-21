/*
title:

url:

全然気づかなかった。なるほどなぁ
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

int n, x, y;
vector<int> a;

int get_min_score(int nowx, int nowy, int index);

/*
//ｘはindex<=i<nのあいだのカードから1枚選ぶ
int get_max_score(int nowx, int nowy, int index)
{
    if (index == n - 1)
    {
        return (abs(a[n - 1] - nowy));
    }
    int tmp = abs(a[n - 1] - nowy);
    for (int i = index; i < n - 1; i++)
    {
        tmp = max(tmp, get_min_score(a[i], nowy, i + 1));
    }
    return tmp;
}

int get_min_score(int nowx, int nowy, int index)
{
    if (index == n - 1)
    {
        return (abs(a[n - 1] - nowx));
    }
    int tmp = abs(a[n - 1] - nowx);
    for (int i = index; i < n - 1; i++)
    {
        tmp = min(tmp, get_max_score(nowx, a[i], i + 1));
    }
    return tmp;
}
*/

int main()
{
    cin >> n >> x >> y;
    rep(i, n)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    if (n >= 2)
    {
        cout << max(abs(y - a[n - 1]), abs(a[n - 1] - a[n - 2]));
    }
    else
    {
        cout << abs(y - a[n - 1]) << endl;
    }
    return 0;
}