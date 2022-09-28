//
// Created by Hleonor on 2022-09-25.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct student
{
    int number;
    int score;
    student(int number , int socre) : number(number) , score(socre) {};
    bool operator < (student a)
    {
        if (score != a.score)
        {
            return score > a.score;
        }
        else
        {
            return number < a.number;
        }
    }
};

int score_index[100010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int number , score;
        scanf("%d%d", &number, &score);
        score_index[number] = score;
    }

    int m = 0;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        vector<student> tmp;
        int check = 0;

        while (1)
        {
            scanf("%d" , &check);
            if (check == 0)
            {
                break;
            }
            student stu = {check , score_index[check]};
            tmp.push_back(stu);
        }
        sort(tmp.begin() , tmp.end());
        for (auto k : tmp)
        {
            printf("%d ", k.number);
        }
        tmp.clear();
    }

    return 0;
}