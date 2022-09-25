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
    int node_num = 0;
    NODE(){}; //构造函数
};

int node_count = 1;

NODE* createRoot(NODE* root)
{
    root = new NODE();
    root->node_num = 1;
    node_count++;
    return root;
}

NODE* createNode(NODE* father)
{
    NODE* new_node = new NODE();
    new_node->parent = father;
    new_node->node_num = node_count;
    node_count++;
    return new_node;
}

string mainString;
struct NODE* root;
struct NODE *current_node; // 指向当前处理的节点
NODE* add_a_node;

string str_compare() // 比较谁的字符长度更长
{
    NODE* father = current_node->parent;
    return father->left->node_str.length() > father->right->node_str.length() ? father->left->node_str : father->right->node_str;
}

void combine()
{
    if (current_node->parent->left && current_node->parent->right == NULL)
    {
        current_node->parent->node_str += current_node->node_str;
        current_node = current_node->parent;
        free(current_node->left);
    }
    else if (current_node->parent->left && current_node->parent->right)
    {
        current_node->parent->node_str += str_compare();
        current_node = current_node->parent;
        delete current_node->left;
        delete current_node->right;
    }
}

void handle_a()
{
    if (current_node->left == NULL)
    {
        NODE* new_node = createNode(current_node);
        current_node->left = new_node;
        add_a_node = new_node;
        //current_node = new_node;
    }
    else if (current_node->right == NULL)
    {
        NODE* new_node = createNode(current_node);
        current_node->right = new_node;
        add_a_node = new_node;
        // current_node = new_node;
    }
    add_a_node->node_str += 'a';
}

void handle_left_bracket()
{
    if (current_node->left == NULL)
    {
        NODE* new_node_1 = createNode(current_node);
        current_node->left = new_node_1;
        current_node = new_node_1;
    }
    else
    {
        NODE* new_node_1 = createNode(current_node);
        current_node->right = new_node_1;
        current_node = new_node_1;
    }
}

void handle_right_bracket()
{
    // 遇到右括号，合并current_node父亲节点的两个孩子节点
    combine();
    if (current_node->parent->node_str != "")
    {
        combine();
        // current_node = current_node->parent;
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
            // 遇到分隔符，创建一个兄弟节点
            if (mainString[i + 1] == '(') // 需要跨越| 和 (
            {
                NODE* brother = createNode(current_node->parent);
                current_node->parent->right = brother;
                NODE* new_node = createNode(brother);
                brother->left = new_node;
                current_node = new_node;
                i++;
            }
            else if (mainString[i + 1] == 'a') // 只需要跨越 |
            {
                NODE* brother = createNode(current_node->parent);
                current_node->parent->right = brother;
                current_node = brother;
            }
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
    combine(); // 最后将结果combine到父节点
}

// TODO:思路错了，遇到左括号的时候不应该连着创建两个节点，第二个节点应该是什么应该具体根据下一个字符是a还是(来进一步判断
int main()
{
    root = createRoot(root);
    current_node = root;
    cin >> mainString;
    // 根节点开始的时候不保存内容，因为遍历字符串的顺序是从左到右
    // 所以一开始传入左子节点当作待操作节点

    handleString();
    printf("%d" , root->node_str.size());
    return 0;
}