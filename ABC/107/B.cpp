#include <iostream>
#include <cstdio>
#include <string>

#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

//汚い解き方
//charだとめんどくさいのでstringを使おう。

int main()
{
    int H, W;
    scanf("%d %d\n", &H, &W);

    string data[H];
    string ans[H];
    REP(i, H)
    {
        cin >> data[i];
        ans[i] = data[i];
    }

    REP(i, H)
    {
        int j;
        for (j = 0; j < W; j++)
        {
            if (data[i][j] == '#')
            {
                break;
            }
        }

        //j == H なら１度もbreakしてない <=> 全て'.'
        if (j == W)
        {
            REP(k, W)
            {
                ans[i][k] = 'n';
            }
        }
    }

    REP(i, W)
    {
        int j;
        for (j = 0; j < H; j++)
        {
            if (data[j][i] == '#')
                break;
        }
        if (j == H)
        {
            REP(k, H)
            {
                ans[k][i] = 'n';
            }
        }
    }

    REP(i, H)
    {
        bool check = true;
        REP(j, W)
        {
            if (ans[i][j] != 'n')
            {
                cout << ans[i][j];
                check = false;
            }
        }
        if (!(check))
            cout << endl;
    }
}