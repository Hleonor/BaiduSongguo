//
// Created by Hleonor on 2022-09-23.
//
#include <iostream>
#include <string>
using namespace std;
struct NODE* createRoot(struct NODE* root);
void handleString(struct NODE* node , int index);
struct NODE
{
    string node_str;
    int len = 0;
    struct NODE* parent = NULL;
    struct NODE* left = NULL;
    struct NODE* right = NULL;
    NODE(){}; //构造函数
};

string mainString;
int main()
{
    struct NODE* root = createRoot(root);
    cin >> mainString;
    handleString(root , 0);
    printf("%d" , root->len);
    return 0;
}

NODE* createRoot(NODE* root)
{
    root = new NODE();
    return root;
}

NODE* createNode(string sub_str , NODE* father)
{
    NODE* new_node = new NODE();
    new_node->node_str = sub_str;
    new_node->len = sub_str.length();
    new_node->parent = father;
    return new_node;
}

void handleString(NODE* node , int index)
{
    string temp; // 临时存储字符串
    NODE* current_node = node;
    node->left = createNode(temp , node); // 首先创建左子节点

    for (int i = index; i < mainString.size(); i++) // 从当前index位置遍历主串
    {
        if (mainString[i] == 'a') // 遇到a字符，将a字符保存到temp中
        {
            temp += mainString[i];
            node->left->node_str = temp; // 将temp赋值给左子节点
        }
        else if (mainString[i] == '|') // 遇到 | 字符，创建一个兄弟节点
        {

        }
        else if (mainString[i] == '(') // 遇到左括号，创建一个空子节点
        {
            current_node = node->left;
            NODE* new_node = createNode(0 , current_node);
        }
        else // 遇到右括号，将父亲节点的两个孩子子串比较大小，取较长者存入父亲的node_str中
        {

        }
    }
}