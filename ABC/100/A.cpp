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

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define INF 1000000007

typedef pair<int, int> p_i;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a <= 8 && b <= 8)
        cout << "Yay!" << endl;
    else
        cout << ":(" << endl;
    return 0;
}