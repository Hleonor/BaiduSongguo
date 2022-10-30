//
// Created by Hleonor on 2022-10-30.
//
#include<iostream>
using namespace std;

int main()
{
    int n;
    float p = 0;
    scanf("%f %d", &p, &n);
    p /= 100;
    float ret = 1;
    for (int i = 1; i <= n - 1; i++)
    {
        ret *= (1 - p);
    }
    ret *= p;
    printf("%.2f", ret);
    return 0;
}