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
    int ans = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '2')
        {
            ans++;
        }
    }
    cout << ans << endl;
}