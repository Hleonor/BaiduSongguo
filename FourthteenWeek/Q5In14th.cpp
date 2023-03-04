//
// Created by Hleonor on 2023-01-15.
//
#include<iostream>
#include <cstring>
#include <vector>


using namespace std;

int portals[200010];
int book[200010]; // 表示是否被访问过
int n;
int isInCircle[200010]; // 表示是否在环中
int notInCircle[200010]; // 表示不在环中
int backup_forIsIn[200010]; // 备份
int backup_forNotIn[200010]; // 备份

// 任何一个位置要么能到达0，要么能到达环中的某个位置
bool my_dfs(int x)
{
    if (portals[x] == 0) // 说明这条路径能到达0
    {
        return true;
    }
    if (book[x] == 1) // 说明这条路径不能到达0
    {
        return false;
    }
    book[x] = 1;
    isInCircle[x] = 1;
    notInCircle[x] = 1;
    int next = x + portals[x];
    return my_dfs(next);
}

int main( )
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> portals[i];
    }
    for (int i = 1; i <= n; i++)
    {
        // 每轮开始前先备份isInCircle和notInCircle
        memcpy(backup_forIsIn, isInCircle, sizeof(isInCircle));
        memcpy(backup_forNotIn, notInCircle, sizeof(notInCircle));
        if (isInCircle[i])
        {
            cout << "Y";
        }
        else if (notInCircle[i])
        {
            cout << "N";
        }
        else
        {
            if (!my_dfs(i)) // 不能到达0，说明应该还原能到达0的
            {
                // 用backup_1还原isInCircle
                ::memcpy(isInCircle, backup_forIsIn, sizeof(backup_forIsIn));
                cout << "Y";
            }
            else
            {
                // 用backup_2还原notInCircle
                ::memcpy(notInCircle, backup_forNotIn, sizeof(backup_forNotIn));
                cout << "N";
            }
        }
    }
    return 0;
}