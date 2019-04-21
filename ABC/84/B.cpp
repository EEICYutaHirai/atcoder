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
    int a, b;
    string s;
    cin >> a >> b >> s;
    for (int i = 0; i < a; i++)
    {
        if (s[i] - '0' < 0 || s[i] - '0' > 10)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    if (s[a] != '-')
    {
        cout << "No" << endl;
        return 0;
    }
    for (int i = a + 1; i < a + b + 1; i++)
    {
        if (s[i] - '0' < 0 || s[i] - '0' > 10)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}