/*
title:

url:

二分検索を使おう
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
    int N, M;
    vector<int> from1;
    vector<int> toN;
    cin >> N >> M;

    rep(i, M)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == 1)
        {
            from1.push_back(b);
        }
        if (b == N)
        {
            toN.push_back(a);
        }
    }

    sort(from1.begin(), from1.end());
    sort(toN.begin(), toN.end());

    bool possible = false;
    rep(i, from1.size())
    {
        if (upper_bound(toN.begin(), toN.end(), from1[i]) - lower_bound(toN.begin(), toN.end(), from1[i]) != 0)
        {
            possible = true;
            break;
        }
    }

    if (possible)
    {
        cout << "POSSIBLE" << endl;
        ;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}