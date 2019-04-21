/*
title:

url:

Kが５以下であることに注目
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
    string s;
    int k;
    cin >> s >> k;
    string ans[k];
    //find min alpahbet(a, b, c...)
    int count = 0;

    char min_alp = 'a';
    while (true)
    {
        vector<int> min_index;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == min_alp)
            {
                min_index.push_back(i);
            }
        }
        if (!min_index.empty())
        {
            priority_queue<string, vector<string>, greater<string>> q;
            for (int i = 0; i < min_index.size(); i++)
            {
                //cout << min_index[i] << endl;
                string tmp = "";
                for (int j = 0; j + min_index[i] < s.size(); j++)
                {
                    tmp += s[min_index[i] + j];
                    q.push(tmp);
                }
            }
            while (!q.empty())
            {
                ans[count] = q.top();
                while ((!q.empty()) && q.top() == ans[count])
                {
                    q.pop();
                }
                count++;
                if (count == k)
                {
                    cout << ans[k - 1] << endl;
                    return 0;
                }
            }
        }
        min_alp += 1;
    }
}