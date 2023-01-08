//
// Created by Hleonor on 2023-01-08.
//
#include<bits/stdc++.h>

using namespace std;
int rubikSCube[3][3] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int row;
        char operation;
        scanf("%d%c", &row, &operation);
        row--;
        // 如果字符是L
        if (operation == 'L') // 向左，同一行进行操作
        {
            int tmp = rubikSCube[row][1];
            rubikSCube[row][1] = rubikSCube[row][2];
            rubikSCube[row][2] = rubikSCube[row][0];
            rubikSCube[row][0] = tmp;
        }
        else if (operation == 'R')
        {
            int tmp = rubikSCube[row][1];
            rubikSCube[row][1] = rubikSCube[row][0];
            rubikSCube[row][0] = rubikSCube[row][2];
            rubikSCube[row][2] = tmp;
        }
        else if (operation == 'U') // 在同一列操作
        {
            int tmp = rubikSCube[1][row];
            rubikSCube[1][row] = rubikSCube[2][row];
            rubikSCube[2][row] = rubikSCube[0][row];
            rubikSCube[0][row] = tmp;
        }
        else if (operation == 'D')
        {
            int tmp = rubikSCube[1][row];;
            rubikSCube[1][row] = rubikSCube[0][row];
            rubikSCube[0][row] = rubikSCube[2][row];
            rubikSCube[2][row] = tmp;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (rubikSCube[i][j] == 1)
            {
                cout << "r";
            }
            else if (rubikSCube[i][j] == 2)
            {
                cout << "g";
            }
            else
            {
                cout << "b";
            }
        }
        cout << endl;
    }
    return 0;
}