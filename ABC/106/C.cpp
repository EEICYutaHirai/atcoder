#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int K;
    cin >> K;

    int one_index = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            one_index++;
        }
        else
        {
            break;
        }
    }
    if (one_index >= K)
    {
        cout << 1 << endl;
        return 0;
    }
    else
    {
        cout << s[one_index] << endl;
        return 0;
    }
}