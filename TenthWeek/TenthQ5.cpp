//
// Created by Hleonor on 2022-11-17.
//
#include<bits/stdc++.h>

using namespace std;

int main( )
{
    int n;
    scanf("%d", &n);
    if (n == 2)
    {
        printf("1");
        exit(0);
    }
    int ret = 1; // n从3开始
    int add_number = 2;
    int tmp = 1;
    for (int i = 1; i <= n - 2; i++)
    {
        tmp = tmp + add_number;
        ret += tmp;
        add_number++;
    }
    printf("%d", ret);
    return 0;
}