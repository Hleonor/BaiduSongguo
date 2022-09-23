//
// Created by Hleonor on 2022-09-23.
//
#include <iostream>
#include <string>
using namespace std;
struct node* createRoot(struct node* root);
void handleString(struct node* node);
struct node
{
    string node_str;
    int len = 0;
    struct node* parent = NULL;
    struct node* left = NULL;
    struct node* right = NULL;
    node(){}; //构造函数
};

string mainString;
int main()
{
    struct node* root = createRoot(root);
    cin >> mainString;
    handleString(root);
    printf("%d" , root->len);
    return 0;
}

node* createRoot(node* root)
{
    root = new node();
    return root;
}

node* createNode(string sub_str , node* father)
{
    node* new_node = new node();
    new_node->node_str = sub_str;
    new_node->len = sub_str.length();
    new_node->parent = father;
    return new_node;
}

void handleString(node* node)
{
    string temp; // 临时存储字符串
    for (int i = 0; i < mainString.size(); i++)
    {
        if (mainString[i] == 'a')
        {
            temp += mainString[i];
        }
        else if (mainString[i] == '|') // 遇到
        {

        }
        else if (mainString[i] == '(')
        {

        }
        else
        {

        }
    }
}