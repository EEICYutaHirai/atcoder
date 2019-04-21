/*
title:

url:

よくわからなかったので解説をみた。
なんとなくの理解を明晰に言葉で表すのって難しい
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
    string s;
    cin >> s;
    int ans = s.size();
    rep(i, s.size() - 1)
    {
        if (s[i] != s[i + 1])
        {
            ans = min(ans, max(i + 1, (int)s.size() - i - 1));
        }
    }
    cout << ans << endl;
}