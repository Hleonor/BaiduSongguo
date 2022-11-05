#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 1000010;

int n;
int phi[maxn];

void Euler()
{
    phi[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!phi[i])
        {
            for (int j = i; j < maxn; j += i)
            {
                if (!phi[j]) phi[j] = j;
                {
                    phi[j] = phi[j] / i * (i - 1);
                }
            }
        }
    }
}

struct node
{
    int id, eu; // eu值是欧拉函数值，id是编号
    node(int i = 0, int e = 0)
    {
        id = i; eu = e;
    }
};

bool cmp(const node& n1, const node& n2)
{
    if (n1.eu == n2.eu) // 如果欧拉函数值相等，按照编号从小到大排序
    {
        return n1.id < n2.id;
    }
    return n1.eu < n2.eu; // 欧拉函数值从小到大排序
}

node p[maxn]; // 存储欧拉函数值和编号
int rk[maxn]; // 存储某个欧拉值对应的编号，含义和p数组相反，rk[欧拉值] = 对应的数字
int a[10010];

int main()
{
    Euler();
    phi[1] = 0;
    for (int i = 1; i < maxn; i++)
    {
        p[i].id = i;
        p[i].eu = phi[i];
        rk[i] = 0x3fffffff; // 初始化为一个很大的数
    }
    sort(p + 1, p + maxn, cmp); // 按照欧拉函数值从小到大排序
    int cnt = -1;
    for (int i = 1; i < maxn; i++)
    {
        if (p[i].eu > cnt)
        {
            cnt = p[i].eu;
            rk[cnt] = p[i].id; // 更新cnt更大的欧拉函数值对应的编号，编号的含义就是欧拉值随对应的那个数字
        }
        else
        {
            continue;
        }
    }
    /*
     * 紧凑，因为要求的是最接近ai的值，所以只需要找到最近的那一个数其欧拉函数值为待求的下标即可
     * 例如不存在某个数字的欧拉函数值为3，但是存在欧拉函数值为4的数字，那么就可以直接用4来代替3
     */
    for (int i = maxn - 2; i >= 1; i--) // 从后往前紧凑
    {
        rk[i] = min(rk[i], rk[i + 1]);
    }
    int n;
    cin >> n;
    LL ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += rk[a[i]];
    }
    cout << ans;
    return 0;
}