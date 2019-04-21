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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int pre[26] = {};
    int post[26] = {};
    for (int i = 0; i < s.size(); i++)
    {
        post[s[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int tmp_ans = 0;
        for (int j = 0; j < 26; j++)
        {
            if (pre[j] > 0 && post[j] > 0)
                tmp_ans++;
        }
        ans = max(ans, tmp_ans);
        pre[s[i] - 'a']++;
        post[s[i] - 'a']--;
    }
    cout << ans << endl;
}