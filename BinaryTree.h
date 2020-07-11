#pragma once

#include<iostream>
#include<string>
using namespace std;
#define ElementType string

/*
struct Node 
attrubite:
    Element data:存储的数据，类型可从宏定义处修改
    Node *leftchild:指向左孩子结点的指针
    Node *rightchild：指向右孩子结点的指针
*/
typedef struct TreeNode
{
    public:
    ElementType data;
    TreeNode *leftchild;
    TreeNode *rightchild; 
}TreeNode;

/*
BinaryTree Object
public attribute: TreeNode *root:根节点指针
public function:
    BinaryTree:递归初始化树
    ~BinaryTree:析构函数(可省略)
    void print_all_data():中序遍历打印所有结点
    void display():横向树型打印object
*/
class BinaryTree
{
    public:
        TreeNode *root;
        BinaryTree();
        ~BinaryTree(){};
        void creat_new_node(TreeNode **root);
        friend void print_all_data(TreeNode *root);
        friend void display(TreeNode *root,int layer_num);
};

BinaryTree::BinaryTree()
{
    this->root = NULL;
}

void BinaryTree::creat_new_node(TreeNode **root)
{
    //时刻注意root是指针的指针，与上class中的root含义不同
    ElementType str;
    string end_str(";");
    cout << "Please enter the data of node:";
    getline(cin,str);
    if((str.compare(end_str)) == 0)
    {
        *root = NULL;
    }
    else
    {   
        TreeNode *new_tree_node =  new TreeNode;
        new_tree_node->data = str;
        /*
        new_tree_node->leftchild = NULL;
        new_tree_node->rightchild = NULL;
        */
        *root = new_tree_node;
        /*
        (*root)->data = str;//new_tree_node;
        //直接赋值会导致第二次添加结点时leftchild与rightchild是无指向的
        */
        creat_new_node(&((*root)->leftchild));
        creat_new_node(&((*root)->rightchild));
    }
}

void print_all_data(TreeNode *root)
{
    cout << root->data << endl;
    print_all_data(root->leftchild);
    print_all_data(root->rightchild);
}

/*
横向树状打印,适合RDL遍历实现，每打印一次换行
有无方法不传入参数layer使该函数完成相同操作?
*/
/*
void display(TreeNode *root,int layer_num)
{
    //若右孩子不为空，往右孩子方向走，并且横向打印空格
    if(root->rightchild != NULL)
    {
        for(int i = 0 ;i < layer_num ;i++)
        {
            cout << ' ';
        }
        display(root->rightchild,layer_num+1);
    }
    cout << root->data << endl;
    if(root->leftchild != NULL)
    {
        for(int i = 0 ;i < layer_num ;i++)
        {
            cout << ' ';
        }
        display(root->leftchild,layer_num+1);
    }
}
*/