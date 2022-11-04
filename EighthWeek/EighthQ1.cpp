//
// Created by Hleonor on 2022-11-03.
//
#include<bits/stdc++.h>
#include <cstring>

using namespace std;

int phai[10010] ={0};

/*int Euler(int N)
{
    int ret = N;
    for(int i = 2; i * i <= N; i++) // 因为是找质数，所以只需要找到根号N就行
    {
        if(N % i == 0) // 如果i是N的因子，则应该除去i的贡献；第一个找到的因子必然是最小的，是质数的
        {
            ret = ret * (i - 1) / i;
            while(N % i == 0) // 这部分对应：n=p1^a1*p2^a2*...*pk^ak，这一步的目的是找到下一个不同的质因子，去掉p1^a1的贡献
            {
                N /= i;
            }
        }
    }
    if(N > 1) // 会出现这一步是因为最后一个质因子可能是大于根号N的，所以需要单独处理
    {
        ret = ret * (N - 1) / N;
    }
    return ret;
}*/

void Euler(int n) // 打表法
{
    for (int i = 2; i <= n; i++)
    {
        if (phai[i] == 0) // 如果phai[i]没处理过，则是没有被之前的素数处理过，这里保证只处理质因数
        {
            for (int j = i; j <= n; j += i) // 处理j以及j的倍数
            {
                if (phai[j] == 0) // 如果phai[j]没处理过，用欧拉函数进处理
                {
                    phai[j] = j;
                }
                phai[j] = phai[j] / i * (i - 1); // 因为j是i的倍数，所以phai[j]要消除i的贡献
            }
        }
    }
}

long a[10010];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%ld", &a[i]);
    }
    int sumOfbi = 0;
    for (int i = 1; i <= n; i++) // 对每一个ai
    {
        int min_bi = INT_MAX;
        for (int j = 2; j <= 1000; j++) // 从1开始挨个求j的欧拉函数值
        {
            Euler(j);
            if (phai[j] >= a[i] && phai[j] < min_bi)
            {
                min_bi = phai[j];
            }
            memset(phai, 0, sizeof(int));
        }
        sumOfbi += min_bi;
        memset(phai, 0, sizeof(int));
    }
    printf("%d", sumOfbi);
    return 0;

}