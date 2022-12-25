//
// Created by Hleonor on 2022-11-20.
//
#include<bits/stdc++.h>
using namespace std;

int main( )
{
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        int cnt = 1;
        for (int j = 0; j < i; j++)
        {
            bool book = true;
            for (int k = 0; k < i-j; k++)
            {
                if (str[j + k] != str [i - k])
                {
                    book = false;
                    break;
                }
            }
            if (book)
            {
                cnt++;
            }
        }
        printf("%d ", cnt);
    }
    return 0;
}