//
// Created by Hleonor on 2022-11-10.
//
#include<bits/stdc++.h>

using namespace std;
int A, B;
int x, y, z;

int cost[210][210];
int result = 0;
void findClosest(int questionLoc)
{
    if (cost[x][questionLoc] <= cost[y][questionLoc] && cost[x][questionLoc] <= cost[z][questionLoc])
    {
        result += cost[x][questionLoc];
        x = questionLoc;
    }
    else if (cost[y][questionLoc] <= cost[x][questionLoc] && cost[y][questionLoc] <= cost[z][questionLoc])
    {
        result += cost[y][questionLoc];
        y = questionLoc;
    }
    else if (cost[z][questionLoc] <= cost[x][questionLoc] && cost[z][questionLoc] <= cost[y][questionLoc])
    {
        result += cost[z][questionLoc];
        z = questionLoc;
    }
}

int main( )
{

    scanf("%d %d", &A, &B);
    scanf("%d %d %d", &x, &y, &z);
    for (int i = 1; i <= A; i++)
    {
        for (int j = 1; j <= A; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    int questionMark = -1;
    for (int i = 1; i <= B; i++)
    {
        scanf("%d", &questionMark);
        // 如果x, y, z三者中有一方已经在问号处，则无需处理
        if (x == questionMark || y == questionMark || z == questionMark)
        {
            continue;
        }
        findClosest(questionMark);
    }
    printf("%d", result);
    return 0;
}