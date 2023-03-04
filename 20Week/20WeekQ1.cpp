//
// Created by Hleonor on 2023-03-03.
//
#include<bits/stdc++.h>

using namespace std;
// 需要一个数组来记录过程中求到的多个结果
int triangle[510];
int acceptInput[510];
int main()
{
    triangle[1] = 1;
    triangle[2] = 5;
    int ret = 0;
    int lastRound = 1;
    int k = 1;
    for (int i = 3; i <= 501; i++)
    {
        k += i - 1;
        ret = i * i + k + lastRound;
        triangle[i] = ret;
        lastRound += k;
    }

    int N;
    ::scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        ::scanf("%d", &acceptInput[i]);
    }

    for (int i = 1; i <= N; i++)
    {
        cout << triangle[acceptInput[i]] << endl;
    }

    return 0;
}
