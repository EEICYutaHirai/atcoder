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
    string S, T;
    cin >> S >> T;
    char s_to_t[26];
    for (int i = 0; i < 26; i++)
    {
        s_to_t[i] = '0';
    }
    for (int i = 0; i < S.size(); i++)
    {
        if (s_to_t[S[i] - 'a'] == '0')
        {
            s_to_t[S[i] - 'a'] = T[i];
        }
        else if (s_to_t[S[i] - 'a'] != T[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (s_to_t[i] != '0' && s_to_t[i] == s_to_t[j])
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < S.size(); i++)
    {
        S[i] = s_to_t[S[i] - 'a'];
    }
    if (S == T)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}