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
    int n;
    cin >> n;
    string s = to_string(n);
    rep(i, 2)
    {
        bool ans = true;
        for (int j = i; j < i + 3; j++)
        {
            if (s[i] != s[j])
            {
                ans = false;
            }
        }
        if (ans)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}