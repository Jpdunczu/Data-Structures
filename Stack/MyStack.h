//
//  MyStack.h
//  PC1802
//
//  Created by Joshua Duncan on 5/27/15.
//  Copyright (c) 2015 Joshua Duncan. All rights reserved.
//

#ifndef PC1802_MyStack_h
#define PC1802_MyStack_h
#include <iostream>

using namespace std;

template< class T >
class DynamicStack
{
    struct StackNode
    {
        T value;
        StackNode *next;
    };
    
    StackNode *top;
    
public:
    DynamicStack()
    { top = NULL; }
    
    DynamicStack( const T & );
    
    ~DynamicStack();
    
    void push( T );
    void pop( T & );
    bool isEmpty();
    DynamicStack operator=( const T & );
};

template< class T >
DynamicStack<T>::DynamicStack( const T &obj )
{
    top = obj.top;
}

template< class T >
DynamicStack<T>::~DynamicStack()
{
    StackNode *nodeptr, *nextNode;
    
    nodeptr = top;
    
    while (nodeptr != NULL)
    {
        nextNode = nodeptr->next;
        delete nodeptr;
        nodeptr = nextNode;
    }
}

template< class T >
void DynamicStack<T>::push( T item )
{
    StackNode *newNode;
    
    newNode = new StackNode;
    newNode->value = item;
    
    if(isEmpty())
    {
        top = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

template< class T >
void DynamicStack<T>::pop( T &item )
{
    StackNode *temp;
    
    if (isEmpty())
    {
        throw "The stack is empty.\n";
    }
    else
    {
        item = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
}

template< class T >
bool DynamicStack<T>::isEmpty()
{
    bool status;
    
    if(!top)
        status = true;
    else
        status = false;
    
    return status;
}

template< class T >
DynamicStack<T> DynamicStack<T>::operator=( const T &right )
{
    top = right.top;
}


#endif
