#include<iostream>
#include "LinkedStack.h"
using namespace std;
int main()
{
    LinkedStack link_stack;
    link_stack = LinkedStack();
    link_stack.push(1);
    cout << link_stack.get_top() << endl;
    link_stack.push(2);
    cout << link_stack.get_top() << endl;
    link_stack.destack();
    cout << link_stack.get_top() << endl;
    cout << link_stack.is_empty() << endl;
    link_stack.destack();
    cout << link_stack.is_empty() << endl;
    return 0;
}