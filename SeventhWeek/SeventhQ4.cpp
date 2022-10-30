//
// Created by Hleonor on 2022-10-30.
//
#include<iostream>
using namespace std;


int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int c = min(a, b);
    int d = min(c, max(a, b) - c);
    printf("%d", c*c+d*d);
    return 0;
}
