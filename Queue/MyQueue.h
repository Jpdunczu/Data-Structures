//
//  MyQueue.h
//  PC1804
//
//  Created by Joshua Duncan on 5/27/15.
//  Copyright (c) 2015 Joshua Duncan. All rights reserved.
//

#ifndef PC1804_MyQueue_h
#define PC1804_MyQueue_h
#include <iostream>

using namespace std;

template < class T >
class DynamicQueue
{
    struct QueueNode
    {
        T value;
        QueueNode *next;
    };
    
    QueueNode *front;
    QueueNode *rear;
    int numItems;
public:
    DynamicQueue();
    DynamicQueue( const T& );
    
    ~DynamicQueue();
    
    void Enqueue(T);
    void dequeue(T &);
    DynamicQueue operator=(const T& );
    bool isEmpty() const;
    void clear();
    int size() const
    { return numItems; }
};

template<class T>
DynamicQueue<T>::DynamicQueue()
{
    front = NULL;
    rear = NULL;
    numItems = 0;
}

template< class T >
DynamicQueue<T>::DynamicQueue(const T& obj)
{
    obj.front = front;
    obj.rear = rear;
    obj.numItems = numItems;
}

template< class T >
DynamicQueue<T>::~DynamicQueue()
{
    clear();
}

template< class T >
void DynamicQueue<T>::Enqueue(T item)
{
    QueueNode *newNode;
    
    newNode = new QueueNode;
    newNode->value = item;
    newNode->next = NULL;
    
    if(isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    
    numItems++;
    
    cout << "Customer number " << item << " now in line!\n";
    cout << "There are now " << numItems << " people in line\n";
}

template< class T >
void DynamicQueue<T>::dequeue( T &item )
{
    QueueNode *temp;
    
    if(isEmpty())
    {
        throw "The Queue is empty\n";
    }
    else
    {
        cout << "Now serving customer number " << item << "!\n";
        item = front->value;
        
        temp = front;
        front = front->next;
        delete temp;
        
        numItems--;
    }
    
    cout << "There are now " << numItems << " in line!\n";
}

template< class T >
DynamicQueue<T> DynamicQueue<T>::operator=(const T &right)
{
    front = right.front;
    rear = right.rear;
    numItems = right.numItems;
}

template< class T >
bool DynamicQueue<T>::isEmpty() const
{
    bool status;
    
    if( numItems > 0 )
        status = false;
    else
        status = true;
    return status;
    
}

template< class T >
void DynamicQueue<T>::clear()
{
    T value;
    
    while(!isEmpty())
        dequeue(value);
}

#endif
