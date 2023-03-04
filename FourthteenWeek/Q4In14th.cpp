//
// Created by Hleonor on 2023-01-14.
//
#include <iostream>
#include <cstring>

using namespace std;


int fullValue[10010]; // 饱腹值
int deliciousValue[2010]; // 美味值
int h[2010]; // 表示第i家店不吃的最大美味值
int f[2010]; // 表示第i家店吃的最大美味值
int whichCakeStore = 0; // 表示当前不能吃是受到哪家店的影响

int main()
{
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> fullValue[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> deliciousValue[i];
    }

    // 初始化，头两家特殊处理
    h[1] = 0;
    f[1] = deliciousValue[1];

    int h1 = -1; // 第i - 1家吃了导致第i家不能吃的最大美味值
    int affectedByWhichStore_1 = 0; // 对应导致h1结果的店

    int h2 = -1; // 第i - 1家没吃，但是第i家能吃却没吃的最大美味值
    int affectedByWhichStore_2 = 0; // 对应导致h2结果的店

    int h3 = -1; // 第i - 1家没吃，第i家不能吃的最大美味值
    int affectedByWhichStore_3 = 0; // 对应导致h3结果的店，如果是这种情况被选择，则需要继承自上一轮的whichCakeStore

    for (int i = 2; i <= n; i++)
    {
        // 第i - 1家吃了，第i家不能吃
        h1 = f[i - 1];
        affectedByWhichStore_1 = i - 1; // 受上家影响

        // 第i - 1家没吃，第i家需要判断能不能吃
        if (i - whichCakeStore > fullValue[whichCakeStore]) // 第i - 1家没吃，第i家能吃的情况（只有严格大于才可以吃）
        {
            f[i] = h[i - 1] + deliciousValue[i]; // 能吃且吃了

            h2 = h[i - 1]; // 能吃但不吃
            affectedByWhichStore_2 = i; // 受自己影响

            h3 = -1;
        }
        else // 第i - 1家没吃，第i家不能吃的情况
        {
            h3 = h[i - 1];
            affectedByWhichStore_3 = whichCakeStore; // 受上一轮的影响
            f[i] = -1; // -1表示不能吃

            h2 = -1;
        }

        // 比较h1, h2, h3中最大的，然后赋值给h[i]，并且更新whichCakeStore为对应的店
        if (h1 >= h2 && h1 >= h3)
        {
            h[i] = h1;
            whichCakeStore = affectedByWhichStore_1;
        }
        else if (h2 >= h1 && h2 >= h3)
        {
            h[i] = h2;
            whichCakeStore = affectedByWhichStore_2;
        }
        else
        {
            h[i] = h3;
            whichCakeStore = affectedByWhichStore_3;
        }
    }
    // 当i = n时，h[n]和f[n]中的最大值就是最终结果
    cout << max(h[n], f[n]) << endl;
    return 0;
}