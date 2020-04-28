#include<iostream>
#pragma once
#include "SequenceStack.h"
using namespace std;

int main()
{
    SequenceStack seq_stack = SequenceStack(3);
    cout << seq_stack.is_empty() << endl;
    cout << seq_stack.push(2) << ' ' << seq_stack.get_top() << endl;
    cout << seq_stack.push(3) << ' ' << seq_stack.get_top() << endl;
    cout << seq_stack.is_full() << endl;
    cout << seq_stack.push(4) << ' ' << seq_stack.get_top() << endl;
    cout << seq_stack.is_full() << endl;
    cout << seq_stack.push(5) << ' ' << seq_stack.get_top() << endl;
    cout << seq_stack.push(6) << ' ' << seq_stack.get_top() << endl;
    cout << seq_stack.pop() << endl;
    cout << seq_stack.pop() << endl;
    cout << seq_stack.pop() << endl;
    cout << seq_stack.pop() << endl;
    cout << seq_stack.is_empty() << endl;
    return 0;
}