/*
title:B - 罠

url:https://abc002.contest.atcoder.jp/tasks/abc002_2

author:Yuta Hirai
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input_text;
    cin >> input_text;
    string boin = "aiueo";
    for (int i = 0; i < input_text.size(); i++)
    {
        bool is_boin = false;
        for (int j = 0; j < boin.size(); j++)
        {
            if (input_text[i] == boin[j])
            {
                is_boin = true;
            }
        }
        if (is_boin == false)
        {
            cout << input_text[i];
        }
    }
    cout << endl;
}