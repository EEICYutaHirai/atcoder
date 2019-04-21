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
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<int> x_pos, y_pos;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        x_pos.push_back(tmp);
    }
    for (int i = 0; i < M; i++)
    {
        int tmp;
        cin >> tmp;
        y_pos.push_back(tmp);
    }

    sort(x_pos.begin(), x_pos.end());
    sort(y_pos.begin(), y_pos.end());

    if (x_pos[x_pos.size() - 1] < y_pos[0] && x_pos[x_pos.size() - 1] < Y && X < y_pos[0])
    {
        cout << "No War" << endl;
    }
    else
    {
        cout << "War" << endl;
    }
}