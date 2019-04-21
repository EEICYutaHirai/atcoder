/*
title:D - 感雨時刻の整理

url:https://abc001.contest.atcoder.jp/tasks/abc001_4

author:Yuta Hirai

date:2018-8-11
*/

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int start[N];
    int finish[N];
    char _;

    //偶数のindexが時間に相当
    int rainy_time[24 * 60 / 5 + 1 + 24 * 60 / 5] = {};

    for (int i = 0; i < N; i++)
    {
        cin >> start[i] >> _ >> finish[i];
        //分に直す（1105＝＞665分）
        start[i] = (int)(start[i] / 100) * 60 + start[i] % 100;
        finish[i] = (int)(finish[i] / 100) * 60 + finish[i] % 100;
        //5分単位にまとめる
        start[i] -= start[i] % 5;
        if ((finish[i] % 5))
        {
            finish[i] += 5 - (finish[i] % 5);
        }
        start[i] /= 5;
        finish[i] /= 5;
        for (int j = start[i] * 2; j <= finish[i] * 2; j++)
        {
            rainy_time[j] = 1;
        }
    }

    bool is_rainy = false;
    for (int i = 0; i < 24 * 60 / 5 + 1; i++)
    {
        if (is_rainy == false && rainy_time[2 * i] == 1)
        {
            printf("%04d-", (i * 5 % 60) + (i * 5 / 60) * 100);
            is_rainy = true;
        }

        if (i > 0)
        {
            if (rainy_time[2 * i - 1] == 0 && rainy_time[2 * i] == 1 && rainy_time[2 * i - 2] == 1)
            {
                printf("%04d\n", ((i * 5 - 5) % 60) + ((i * 5 - 5) / 60) * 100);
                printf("%04d-", (i * 5 % 60) + (i * 5 / 60) * 100);
            }
        }

        if (is_rainy == true && rainy_time[2 * i] == 0)
        {
            printf("%04d\n", ((i * 5 - 5) % 60) + ((i * 5 - 5) / 60) * 100);
            is_rainy = false;
        }
    }
    if (is_rainy)
    {
        cout << "2400" << endl;
    }
    return 0;
}