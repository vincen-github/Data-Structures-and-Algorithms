#include<iostream>
using namespace std;

class MyCircularQueue 
{
    private:
        int max_size;
        int front;
        int rear;
        int *elem;
    public:
        /** Initialize your data structure here. Set the size of the queue to be k. */
        MyCircularQueue(int k);
        /**Destructor*/
        ~MyCircularQueue();
        /** Insert an element into the circular queue. Return true if the operation is successful. */
        bool enQueue(int value);
        /** Delete an element from the circular queue. Return true if the operation is successful. */
        bool deQueue();
        /** Get the front item from the queue. */
        int Front();
        /** Get the last item from the queue. */
        int Rear();
        /** Checks whether the circular queue is empty or not. */
        bool isEmpty();
        /** Checks whether the circular queue is full or not. */
        bool isFull();
};

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue::MyCircularQueue(int k)
{
    /*In order to distinguish between full and empty, the queue stores at most k elements, the length of the array is k + 1.*/
    this->max_size = k+1;
    this->front = 0;
    this->rear = 0;
    this->elem = new int[this->max_size];
}
/**Destructor*/
MyCircularQueue::~MyCircularQueue()
{
    if(this->elem != NULL)
    {
        delete []this->elem;
    }
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool MyCircularQueue::enQueue(int value) 
    {
        if(isFull())
        {
            return false;
        }
        else
        {
            this->elem[this->rear] = value;
            this->rear = (++this->rear)%(this->max_size);
            return true;
        }
    }

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool MyCircularQueue::deQueue()
{
    if(isEmpty()) return false;
    else
    {
        this->front = (++this->front)%(this->max_size);
        return true;
    }
}

/** Get the front item from the queue. */
int MyCircularQueue::Front()
{
    return (this->isEmpty())?-1:this->elem[this->front];
}
        
/** Get the last item from the queue. */
int MyCircularQueue::Rear() 
{
    if(this->isEmpty()) return -1;
    else return (this->rear == 0)?this->elem[this->max_size-1]:this->elem[this->rear-1];
}

/** Checks whether the circular queue is empty or not. */
bool MyCircularQueue::isEmpty() 
{
    return this->front == this->rear;
}
        
/** Checks whether the circular queue is full or not. */
bool MyCircularQueue::isFull() 
{
    return this->front == (this->rear + 1)%this->max_size;
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */