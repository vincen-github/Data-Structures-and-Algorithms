#include<iostream>
#pragma once
#include "..\..\LinkList\LinkList.h"
using namespace std;

//首元结点一直为栈顶
class LinkedStack
{
    private:
        linklist stack;
    public:
        LinkedStack();
        bool is_empty();
        void push(int value);
        int destack();
        int get_top();
};

LinkedStack::LinkedStack()
{
    this->stack = init_linklist();
    this->stack->next = NULL;
    // 头结点储存stack元素个数
    this->stack->elem = 0;
}

bool LinkedStack::is_empty()
{
    return this->stack->next == NULL;
}

//实质为链表的头插法
void LinkedStack::push(int value)
{
    add(this->stack,value);
}

//实质为获取链表stack的首元结点elem域
int LinkedStack::get_top()
{
    return is_empty()?false:this->stack->next->elem;
}

int LinkedStack::destack()
{
    if (!is_empty())
    {
        int pop_elem = pop(this->stack,1);
        return pop_elem;
    }
    return false;
}