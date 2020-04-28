#include<iostream>
using namespace std;

class SequenceStack
{
    private:
        // top指向栈顶的上一位置
        int top;
        int max_size;
        int *elem;
    public:
        SequenceStack(int max_size);
        ~SequenceStack();
        bool is_empty();
        bool is_full();
        bool push(int value);
        int pop();
        int get_top();
};

SequenceStack::SequenceStack(int max_size)
{
    this->max_size = max_size;
    this->elem = new int[this->max_size];
    this->top = 0;
}

SequenceStack::~SequenceStack()
{
    delete []this->elem;
}

bool SequenceStack::is_empty()
{
    return this->top == 0;
}

bool SequenceStack::is_full()
{
    return this->top == this->max_size;
}

bool SequenceStack::push(int value)
{
    return is_full()?false:(this->elem[this->top++] =  value,true);
}

int SequenceStack::get_top()
{
    return is_empty()?false:this->elem[this->top - 1];
}

int SequenceStack::pop()
{
    return is_empty()?false:this->elem[--this->top];
}

