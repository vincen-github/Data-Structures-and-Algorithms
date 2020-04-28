/*
Author: vincen
Date:3/26/2020
Description:链表的实现
*/
#include<iostream>
#include "LinkList.h"
using namespace std;
int main()
{   
    linklist L;
    // init test
    L = init_linklist();
    cout << "Head node next:" << L->next << endl;
    //add test
    add(L,3);
    cout << "The next node address of head node next:" << L->next << endl;
    add(L,5);
    cout << "The length of linklist is:"<< L -> elem << endl;
    cout << "The address of the last node in linklst:" << L->next->next->next << endl;
    //append test
    append(L,6);
    Node *cur = L;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cout<< "The value of the last node's elem:" << cur->elem <<endl;
    cout << "The length of L:" << len(L) <<endl;
    //display test
    display(L);
    // remove test
    remove(L,4);
    cout << "The length of L:" << len(L) <<endl;
    /*
    remove(L,6);
    display(L);
    cout << "The length of L:" << len(L) <<endl;
    */
    remove(L,5);
    display(L);
    cout << "The length of L:" << len(L) <<endl;
    remove(L,3);
    display(L);
    cout << "The length of L:" << len(L) <<endl;
    remove(L,6);
    cout << "The length of L:" << L->elem << ' ' << "The next of L:" << L->next << endl;
    display(L);
    remove(L,7);
    // isnull test
    cout << "The return bool value of the isnull function:" << isnull(L) << endl;
    // pop test
    append(L,1);
    append(L,2);
    append(L,3);
    display(L);
    cout << "The return bool value of the isnull function:" << isnull(L) << endl;
    cout << "The length of L:"<< L->elem << endl;
    cout << "The value be poped:" << pop(L) << endl;
    cout << "The length of L:"<< L->elem << endl;
    cout << "The value be poped:" << pop(L,2) << endl;
    cout << "The length of L:"<< L->elem << endl;
    pop(L,-10);
    pop(L,5);
    cout << "The value be poped:" << pop(L,1) << endl;
    pop(L);
    cout << "The return bool value of the isnull function:" << isnull(L) << endl;
    // insert test
    insert(L,1);
    display(L);
    cout << "The length of L:" << L->elem <<endl;
    insert(L,2,3);
    insert(L,2,2);
    display(L);
    cout << "The length of L:" << L->elem <<endl;
    return 0;
}