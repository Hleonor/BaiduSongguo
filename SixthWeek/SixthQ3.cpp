//
// Created by Hleonor on 2022-10-23.
//
#include<iostream>
using namespace std;
#include<algorithm>
int num[100010];
int main()
{
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("0");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
        }
        // qsort(a + 1, n, sizeof(int), cmp);
        // quick_sort(1, n);
        sort(num + 1, num + n + 1);
        if ((num[n] - num[2]) < (num[n - 1] - num[1]))
        {
            printf("%d", num[n] - num[2]);
        }
        else
        {
            printf("%d", num[n - 1] - num[1]);
        }
    }
    return 0;
}