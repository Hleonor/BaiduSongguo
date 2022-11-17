//
// Created by Hleonor on 2022-11-12.
//
#include<bits/stdc++.h>

using namespace std;

int main( )
{
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++)
    {
        double a, b;
        double ret;
        scanf("%lf %lf", &a, &b);
        if (a <= 4 * b)
        {
            ret = a / (16 * b) + (double)1 / (double)2;
        }
        else
        {
            ret = 1 - b / a;
        }
        printf("%.10lf\n", ret);
    }
    return 0;
}