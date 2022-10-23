//
// Created by Hleonor on 2022-10-23.
//
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int terraces[2010][2010];
int book[2010][2010];
struct NODE
{
    int x = 0;
    int y = 0;
    int height = 0;
    NODE(int x, int y, int height):x(x), y(y), height(height){};

    /*bool operator < (const NODE &a) const
    {
        return height < a.height;
    }
    bool operator > (const NODE &a) const
    {
        return height > a.height;
    }*/
};
bool cmp(const NODE* a, const NODE* b)
{
    return a->height > b->height;
}

NODE* my_node[4000000];
int n; // 梯田的行数
void check(int i, int j) // 递归
{
    if (i < 1 || i > n || j < 1 || j > n || book[i][j] == 0)
    {
        return;
    }
    book[i][j] = 0;
    if (terraces[i][j] > terraces[i][j + 1])
    {
        check(i, j + 1);
    }
    if (terraces[i][j] > terraces[i + 1][j])
    {
        check(i + 1, j);
    }
    if (terraces[i][j] > terraces[i][j - 1])
    {
        check(i, j - 1);
    }
    if (terraces[i][j] > terraces[i - 1][j])
    {
        check(i - 1, j);
    }

}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= 2000; i++) // 初始化
    {
        for (int j = 0; j <= 2000; j++)
        {
            terraces[i][j] = 200;
            book[i][j] = -1;
        }
    }
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &terraces[i][j]);
            my_node[cnt++] = new NODE(i, j, terraces[i][j]);
        }
    }
    sort(my_node + 1, my_node + n * n + 1, cmp);
    int bucket = 0;
    int count = 1;
    while (true)
    {
        while (count <= n * n && book[my_node[count]->x][my_node[count]->y] == 0)
        {
            count++;
        }
        if (count > n * n)
        {
            break;
        }
        check(my_node[count]->x, my_node[count]->y);
        bucket++;
    }
    printf("%d", bucket);
    return 0;
}