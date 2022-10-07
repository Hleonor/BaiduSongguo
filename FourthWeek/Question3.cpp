#include<bits/stdc++.h>
#define _MAX_ 9999999
using namespace std;

struct NODE
{
    int left;
    int right;
};

NODE conn[_MAX_];
bool book[_MAX_];

int n,m;
inline void add(int a,int b)
{
    int tmp = conn[a].right;
    int tmp2 = conn[b].left;
    conn[tmp2].right = tmp;
    conn[tmp].left = tmp2;

    conn[b].left = a;
    conn[a].right = b;
}

int main()
{
    scanf("%d%d",&n,&m);

    for (int i = 1; i <= n; i++)
    {
        conn[i].left = i;  conn[i].right = i;
        book[i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!book[i])
        {
            int tmp = i;
            while (!book[tmp])
            {
                printf("%d ",tmp);
                book[tmp] = true;
                tmp = conn[tmp].right;
            }
            printf("\n");
        }
    }
    return 0;
}