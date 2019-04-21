/*
title:C - 風力観測

url:https://abc001.contest.atcoder.jp/tasks/abc001_3

author:Yuta Hirai

date:2018-8-11

problem:

input:

output:

*/

#include <iostream>
#include <string>

using namespace std;

void print_deg(double Deg)
{
    string degs[16] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
    double deg_min = -112.5, deg_max = 112.5;
    double deg_delta = 3600. / 16;
    int index = 0;
    while (!(deg_min <= Deg && Deg < deg_max))
    {
        deg_min += deg_delta;
        deg_max += deg_delta;
        index++;
    }
    cout << degs[index % 16];
}

void print_Dis(double Dis)
{
    if (0.25 <= Dis && Dis < 1.55)
    {
        cout << "1";
    }
    if (1.55 <= Dis && Dis < 3.35)
    {
        cout << "2";
    }
    if (3.35 <= Dis && Dis < 5.45)
    {
        cout << "3";
    }
    if (5.45 <= Dis && Dis < 7.95)
    {
        cout << "4";
    }
    if (7.95 <= Dis && Dis < 10.75)
    {
        cout << "5";
    }
    if (10.75 <= Dis && Dis < 13.85)
    {
        cout << "6";
    }
    if (13.85 <= Dis && Dis < 17.15)
    {
        cout << "7";
    }
    if (17.15 <= Dis && Dis < 20.75)
    {
        cout << "8";
    }
    if (20.75 <= Dis && Dis < 24.45)
    {
        cout << "9";
    }
    if (24.45 <= Dis && Dis < 28.45)
    {
        cout << "10";
    }
    if (28.45 <= Dis && Dis < 32.65)
    {
        cout << "11";
    }
    if (32.65 <= Dis)
    {
        cout << "12";
    }
}

int main()
{

    double Deg, Dis;
    cin >> Deg >> Dis;
    Dis /= 60.;
    if (0 <= Dis && Dis < 0.25)
    {
        cout << "C 0" << endl;
        return 0;
    }
    print_deg(Deg);
    cout << " ";
    print_Dis(Dis);
    cout << endl;
    return 0;
}