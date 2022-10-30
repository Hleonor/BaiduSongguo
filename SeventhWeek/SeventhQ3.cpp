//
// Created by Hleonor on 2022-10-30.
//
#include<iostream>
using namespace std;

int main()
{
    double p, n;
    double a = 1;;
    scanf("%lf %lf", &p, &n);
    p /= 100;
    for (int i = 0; i < n - 1; i++)
    {
        a = a * (1-p);
    }
    a *= p;
    printf("%0.2f", a);
    return 0;
}