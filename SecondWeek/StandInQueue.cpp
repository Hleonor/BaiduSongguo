#include <iostream>
#include <unordered_map>
using namespace std;

struct position
{
    int num;
    int before;
    int next;
    position(){};
};

int main()
{
    int n;
    int m;
    scanf("%d%d" , &n , &m);

    unordered_map<int , position*> pos;
    auto* head = new position();
    position* prev = head;
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d" , &num);
        prev = new position; // 声明一个新的节点
        prev->num = num;
        pos.insert(make_pair(num , prev));
    }

    for (int i = 0; i < m; i++)
    {
        int number1;
        int number2;
        int book;
        scanf("%d%d%d" , &number1 , &number2 , &book);
        position *p1 = pos[number1];
        position *p2 = pos[number2];

        if (!p1->next)
        {
            pos.at(p1->before)->num = 0;
        }
        else
        {
            if (!p1->before)
            {
                head->next = p1->next;
            }
            else
            {
                pos.at(p1->before)->next = p1->next;
            }
            pos.at(p1->next)->before = p1->before;
        }

        if (!book)
        {
            if (!p2->before)
            {
                head->next = number1;
            }
            else
            {
                pos.at(p2->before)->next = number1;
            }
            p1->before = p2->before;
            p1->next = number2;
            p2->before = number1;
        }
        else
        {
            p1->before = number2;
            p1->next = p2->next;
            if (p2->next)
            {
                pos.at(p2->next)->before = number1;
            }
            p2->next = number1;
        }
    }

    position* p = pos.at(head->next);
    for (int i = 0; i < n; i++)
    {
        printf("%d " , p->num);
        p = pos.at(p->next);
    }

    return 0;
}