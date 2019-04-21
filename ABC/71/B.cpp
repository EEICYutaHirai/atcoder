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
    bool used[26];
    fill(used, used + 26, false);
    string s;
    cin >> s;
    rep(i, s.size())
    {
        used[s[i] - 'a'] = true;
    }

    rep(i, 26)
    {
        if (!used[i])
        {
            printf("%c\n", i + 'a');
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}