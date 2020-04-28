#include<iostream>
#include "CircularQueue.cpp"
using namespace std;

int main()
{
    cout << -1%3 << endl;
    MyCircularQueue circular_queue = MyCircularQueue(7);
    cout << circular_queue.isEmpty() << endl;
    for(int i = 0;i < 7;i++)
    {
        cout << circular_queue.enQueue(i) << endl;
    }
    cout << circular_queue.isFull() << endl;
    cout << circular_queue.isEmpty() << endl;
    return 0;
}