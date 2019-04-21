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

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    string S;
    cin >> S;
    int ans[2] = {0, 0};

    for (int i = 0; i < S.size(); i++)
    {
        if (i % 2 == 0 && S[i] == '0')
        {
            ans[0]++;
        }
        if (i % 2 == 0 && S[i] == '1')
        {
            ans[1]++;
        }
        if (i % 2 == 1 && S[i] == '1')
        {
            ans[0]++;
        }
        if (i % 2 == 1 && S[i] == '0')
        {
            ans[1]++;
        }
    }

    cout << min(ans[0], ans[1]) << endl;
}