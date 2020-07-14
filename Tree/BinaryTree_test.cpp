#include<iostream>
using namespace std;
#include "BinaryTree.h"

int main()
{
    BinaryTree bintree = BinaryTree();
    bintree.creat_new_node(&bintree.root);
    //cout << bintree.root->data << ' ' << bintree.root->leftchild->data << ' '<< bintree.root->leftchild->leftchild->data << endl;
    //print_all_data(bintree.root);
    display(bintree.root,1);
}