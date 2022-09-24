//
// Created by Hleonor on 2022-09-23.
//
#include <iostream>
#include <string>
using namespace std;

struct NODE
{
    string node_str;
    struct NODE* parent = NULL;
    struct NODE* left = NULL;
    struct NODE* right = NULL;
    NODE(){}; //构造函数
};

NODE* createRoot(NODE* root)
{
    root = new NODE();
    return root;
}

NODE* createNode(NODE* father)
{
    NODE* new_node = new NODE();
    new_node->parent = father;
    return new_node;
}

string mainString;
struct NODE* root;
struct NODE *current_node; // 指向当前处理的节点

void combine()
{
    if (current_node->parent->left)
    {
        current_node->parent->node_str += current_node->left->node_str;
    }
    if (current_node->parent->right)
    {
        current_node->parent->node_str += current_node->right->node_str;
    }
}

void handle_a()
{
    current_node->node_str += 'a';
}

void handle_left_bracket()
{
    if (current_node->left == NULL)
    {
        NODE* new_node_1 = createNode(current_node);
        current_node->left = new_node_1;
    }
    else
    {
        NODE* new_node_1 = createNode(current_node);
        current_node->right = new_node_1;
    }
    // 遇到左括号的时候必然需要创建两个节点，因为左括号的下一个字符必然是a
    NODE* new_node_2 = createNode(current_node);
    // 第二个创建的新节点一定是第一个创建新节点的右节点
    current_node->left = new_node_2;
}

void handle_right_bracket()
{
    // 遇到右括号，合并current_node父亲节点的两个孩子节点
    combine();
    current_node = current_node->parent;
    if (current_node->parent->node_str != "")
    {
        combine();
        current_node = current_node->parent;
    }
}

void handle_spilt_symbol(int index)
{
    // 遇到分隔符，创建一个兄弟节点
    if (mainString[index + 1] == '(')
    {
        NODE* brother = createNode(current_node->parent);
        current_node->parent->right = brother;
        NODE* new_node = createNode(brother);
        brother->left = new_node;
        current_node = new_node;
    }
    else if (mainString[index + 1] == 'a')
    {
        NODE* brother = createNode(current_node->parent);
        current_node->parent->right = brother;
        current_node = brother;
    }
}

void handleString()
{
    for (int i = 0; i < mainString.size(); i++) // 从index位置遍历主串
    {
        if (mainString[i] == 'a')
        {
            handle_a();
        }
        else if (mainString[i] == '|')
        {
            handle_spilt_symbol(i);
        }
        else if (mainString[i] == '(')
        {
            handle_left_bracket();
        }
        else
        {
            handle_right_bracket();
        }
    }
}

int main()
{
    root = createRoot(root);
    cin >> mainString;
    // 根节点开始的时候不保存内容，因为遍历字符串的顺序是从左到右
    // 所以一开始传入左子节点当作待操作节点
    current_node = createNode(root);
    root->left = current_node;
    handleString();
    printf("%d" , root->node_str.size());
    return 0;
}