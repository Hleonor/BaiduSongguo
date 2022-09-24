//
// Created by Hleonor on 2022-09-23.
//
#include <iostream>
#include <string>
using namespace std;
struct NODE* createRoot(struct NODE* root);
void handleString(struct NODE* node , int index);
void handle_a(NODE* node);
void handle_left_bracket(NODE* node , int index);
void handle_spilt_symbol(NODE* node , int index);
void handle_right_bracket(NODE* node);
void combine(NODE* node);
NODE* createNode(string sub_str , NODE* father);
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
struct NODE* root;
struct NODE *current_node; // 指向当前处理的节点

int main()
{
    root = createRoot(root);
    cin >> mainString;
    // 根节点开始的时候不保存内容，因为遍历字符串的顺序是从左到右
    // 所以一开始传入左子节点当作待操作节点
    current_node = createNode("" , root);
    root->left = current_node;
    handleString(root->left , 0);
    printf("%d" , root->node_str.size());
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
    for (int i = index; i < mainString.size(); i++) // 从index位置遍历主串
    {
        if (mainString[i] == 'a') // 处理 a 字符
        {
            handle_a(node);
        }
        else if (mainString[i] == '|') // 处理 | 字符
        {
            handle_spilt_symbol(node , i + 1); // 越过 | 字符
        }
        else if (mainString[i] == '(') // 处理左括号
        {
            // 传入的索引值为i + 1，越过左括号
            handle_left_bracket(node , i + 1);
        }
        else // 处理右括号
        {
            handle_right_bracket(node);
            // TODO:需要特殊判断它的父节点是不是根节点
            // TODO:需要记录当前走到了字符串的哪个位置
            return;
        }
    }
}

void handle_a(NODE* node)
{
    if (node == NULL) // 如果当前节点为空，则创建一个节点，默认字符置为a
    {
        node = createNode("a" , node);
    }
    // 如果当前节点不为空，则直接在当前节点的字符串后面添加a
    else
    {
        node->node_str += "a";
        node->len += 1;
    }
}

void handle_left_bracket(NODE* node , int index)
{
    NODE* void_node = createNode("" , node); // 创建一个空节点
    // 将新创建的空节点当作子树的根（同root），从当前index位置往后扫描字符串
    // 有左括号的时候进行递归
    // 遇到右括号的时候结束递归
    handleString(void_node->left , index);
}

void handle_spilt_symbol(NODE* node , int index)
{
    // 创建一个兄弟节点
    NODE* father = node->parent;
    NODE* brother = createNode("" , father);

    // 创建兄弟节点时下一个符号有两种情况：是左括号或者是a
    // 以当前节点作为操作节点，传入handleString函数
    handleString(brother , index);
}

void handle_right_bracket(NODE* node) // 遇到右括号，和最近的一个空节点配对
{
    combine(node->parent);
    // TODO：消除一对括号之后判断是否能和其父节点合并
    node = node->parent;

    // 循环和附近节点组合
    while (node->parent && !node->parent->node_str.empty())
    {
        node->parent->node_str += node->node_str;
        node = node->parent;
    }
}

void combine(NODE* node)
{
    if (node->left)
    {
        node->node_str += node->left->node_str;
    }
    if (node->right)
    {
        node->node_str +=  node->right->node_str;
    }
}