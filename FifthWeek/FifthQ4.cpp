//
// Created by Hleonor on 2022-10-14.
//
#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    long long n;
    scanf("%lld" , &n);
    printf("%lld", n - (long long)sqrt(n) - (long long)sqrt(n / 2));
    return 0;
}