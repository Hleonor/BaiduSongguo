//
// Created by Hleonor on 2022-11-20.
//
#include<bits/stdc++.h>

using namespace std;

int main( )
{
    string str;
    getline(cin, str);
    int result = str.length();
    for (int i = 0; i < str.length()-1; i++)
    {
        if (str[i] == str[i + 1])
        {
            str[i + 1] = 'z';
            result--;
        }
    }
    printf("%d", result);
    return 0;
}