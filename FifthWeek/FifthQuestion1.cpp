//
// Created by Hleonor on 2022-10-14.
//
#include <iostream>
using namespace std;

int getReverse(string number)
{
    string reverse = "";
    for (int i = number.length() - 1; i >= 0; i--)
    {
        reverse += number[i];
    }
    return stoi(reverse);
}

int main()
{
    long n;
    scanf("%ld",&n);
    string number;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        number = to_string(i);
        int reverse = getReverse(number);
        if (i % reverse == 0)
        {
            cnt++;
        }
    }
    printf("%d",cnt);

    return 0;
}