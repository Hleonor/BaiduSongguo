//
// Created by Hleonor on 2022-11-10.
//
#include<bits/stdc++.h>

using namespace std;
int n;
int streetLight[1110];
void test(int number)
{
    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0) // 如果i是number的因数
        {
            streetLight[i] = !streetLight[i]; // 翻转灯的状态
        }
    }
}

int main()
{
    scanf("%d", &n);
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        streetLight[i + 1] = str[i] - '0';
    }
    for (int i = 1; i <= n; i++)
    {
        if (streetLight[i])
        {
            test(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << streetLight[i];
    }
    return 0;
}