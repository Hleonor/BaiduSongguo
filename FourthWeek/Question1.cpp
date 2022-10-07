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
struct BOUNDARY
{
    int left;
    int right;
    BOUNDARY* next = NULL;
};
int number[5010][30] = {0};
BOUNDARY* boundary[250] = {NULL};
int count_of_number[5010]; // 记录每个数组有几个数字

int main()
{
    vector<int> sort_number;
    string tmp;
    int groupNum = 0;
    int n;
    scanf("%d" , &n);
    getchar();
    int min_left = INT_MAX;
    int max_right = -1;
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
                if (number[groupNum][numberCnt] < min_left)
                {
                    min_left = number[groupNum][numberCnt];
                }
                if (number[groupNum][numberCnt] > max_right)
                {
                    max_right = number[groupNum][numberCnt];
                }
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
        count_of_number[groupNum] = numberCnt + 1;
        sort_number.push_back(number[groupNum][numberCnt]);
        if (number[groupNum][numberCnt] < min_left)
        {
            min_left = number[groupNum][numberCnt];
        }
        if (number[groupNum][numberCnt] > max_right)
        {
            max_right = number[groupNum][numberCnt];
        }
        // sort(sort_number.begin(), sort_number.end());
        tmp.clear();
        groupNum++;
    }
    // sort(sort_number.begin() , sort_number.end());
    // int maxBoundary = sort_number[sort_number.size() - 1] - sort_number[0];
    int maxBoundary = max_right - min_left;
    printf("%d %d\n" , min_left , max_right);


    for (int i = 0; i < sort_number.size(); i++)
    {
        for (int j = i + 1; j < sort_number.size(); j++)
        {
            int left = sort_number[i];
            int right = sort_number[j];
            if(boundary[right - left] == NULL)
            {
                boundary[right - left] = new BOUNDARY;
                boundary[right - left]->left = left;
                boundary[right - left]->right = right;
            }
            else
            {
                BOUNDARY* tmp = boundary[right - left];
                while (tmp->next != NULL)
                {
                    tmp = tmp->next;
                }
                tmp->next = new BOUNDARY;
                tmp->next->left = left;
                tmp->next->right = right;
            }
        }
    }

    int min_left_boundary = INT_MAX;
    int range_length = 0;
    int appear_row = 0;
    for (int i = 1; i <= maxBoundary;)
    {
        if (boundary[i] == NULL)
        {
            i++;
            continue;
        }

        bool appear = false;
        for (int j = 0; j < n; j++)
        {
            int number_count = count_of_number[j];
            appear = false; // 重置，为当前数组做准备
            for (int k = 0; k < number_count; k++) // 第i个数组的第j个数字逐个判断
            {
                if (number[j][k] > boundary[i]->right)
                {
                    appear = false;
                    break;
                }
                else if (number[j][k] <= boundary[i]->right && number[j][k] >= boundary[i]->left)
                {
                    appear = true;
                    break; // 说明改数组中有一个数字出现在了该范围中，不用判断其他数字，判断下一个数组
                }
            }
            if (appear == false) //  如果该数组中没有一个数字出现在该范围中，说明该范围不满足条件，不用判断其他数组，选取下一个范围
            {
                break;
            }
        }
        // 所有数组都判断完毕，如果appear为true，说明该范围满足条件
        // 此时找到的范围是距离最小的范围，所有可能的结果必然出现在该行内，不可能出现在下一行，因为已经有了一个最小的满足情况的范围了
        // 此时只需要该范围和本行中上一次找到的范围谁的左边界更小
        if (appear)
        {
            appear_row = i;
            if (boundary[i]->left < min_left_boundary)
            {
                min_left_boundary = boundary[i]->left;
                range_length = boundary[i]->right - boundary[i]->left;
            }
            // printf("%d %d" , boundary[i]->left , boundary[i]->right);
        }
        if (boundary[i]->next != NULL)
        {
            boundary[i] = boundary[i]->next;
        }
        else
        {
            if (appear_row != 0)
            {
                printf("%d %d" , min_left_boundary , min_left_boundary + range_length);
                return 0;
            }
            i++;
        }
    }
    return 0;
}