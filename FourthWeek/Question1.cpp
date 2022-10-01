//
// Created by Hleonor on 2022-09-28.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 思路：用一个类似邻接表的结构存储长度的范围，比如第0个元素里维护的链表是长度为0的范围
 * 第1个元素维护的是长度为1的范围，第2个元素维护的是长度为2的范围，以此类推
 * 当该邻接表构造完了以后
 * 从该表第一个元素开始取出，然后遍历各个数组，查看数组内的元素是否出现在当前范围内
 */
int number[5010][30] = {0};

int main()
{
    vector<int> sort_number;
    string tmp;
    int groupNum = 0;
    int n;
    scanf("%d" , &n);
    getchar();
    while (groupNum != n)
    {
        char ch = getchar();
        int numberCnt = 0;
        while(ch != '\n')
        {
            if (ch == ' ')
            {
                number[groupNum][numberCnt] = atoi(tmp.c_str());
                sort_number.push_back(number[groupNum][numberCnt]);
                numberCnt++;
                tmp.clear();
            }
            else
            {
                tmp += ch;
            }
            ch = getchar();
        }
        number[groupNum][numberCnt] = atoi(tmp.c_str());
        sort_number.push_back(number[groupNum][numberCnt]);
        tmp.clear();
        groupNum++;
    }

    sort(sort_number.begin() , sort_number.end());
    for (int i= 0; i < sort_number.size(); i++)
    {
        cout << sort_number[i] << " ";
    }

    return 0;
}