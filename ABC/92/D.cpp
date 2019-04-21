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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> pint;
typedef long long ll;

int main()
{
    int w, b;
    cin >> b >> w;
    string s[100];
    string str_black(100, '#');
    string str_white(100, '.');
    for (int i = 0; i < 50; i++)
    {
        s[i] = str_black;
    }
    for (int i = 50; i < 100; i++)
    {
        s[i] = str_white;
    }

    for (int i = 0; i < b - 1; i++)
    {
        int y = (i / 50) * 2;
        int x = (i % 50) * 2;
        s[y][x] = '.';
    }
    for (int i = 0; i < w - 1; i++)
    {
        int y = (i / 50) * 2 + 51;
        int x = (i % 50) * 2;
        s[y][x] = '#';
    }
    cout << 100 << " " << 100 << endl;
    for (int i = 0; i < 100; i++)
    {
        cout << s[i] << endl;
    }
    return 0;
}