//
// Created by Hleonor on 2022-09-25.
//
#include <iostream>
#include <algorithm>
using namespace std;

struct student
{
    int number;
    int score;
    student(){};
};
struct index
{
    int number;
    int position;
};
student* stu[100001];
index* ind[100001];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        stu[i] = new student;
        scanf("%d%d", &stu[i]->number, &stu[i]->score);
    }

    return 0;
}