//
// Created by Hleonor on 2022-09-25.
//
#include <iostream>
using namespace std;

string str;
int pos = 0;

int handle_bracket()
{
    pos++;
    int sub_len = 0;
    int tmplen = 0;
    bool book = false;
    while (str[pos] != ')')
    {
        if (str[pos] == '(')
        {
            sub_len += handle_bracket();
        }
        else if (str[pos] == '|')
        {
            tmplen = max(tmplen, sub_len);
            sub_len = 0;
            book = true;
        }
        else if (str[pos] == 'a')
        {
            sub_len++;
        }
        pos++;
    }
    if (book)
    {
        return max(sub_len, tmplen);
    }
    else
    {
        return sub_len;
    }
}

int main()
{
    cin >> str;
    int maxlen = 0;
    int tmplen = 0;
    bool book = false;
    while (pos < str.length())
    {
        if (str[pos] == 'a')
        {
            maxlen++;
        }
        else if (str[pos] == '(')
        {
            maxlen += handle_bracket();
        }
        else if (str[pos] == '|')
        {
            tmplen = max(maxlen , tmplen);
            maxlen = 0;
            book = true;
        }
        pos++;
    }
    if (book)
    {
        cout << max(maxlen, tmplen);
    }
    else
    {
        cout << maxlen;
    }
    return 0;
}