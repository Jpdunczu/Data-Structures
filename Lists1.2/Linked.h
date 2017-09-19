//
//  Linked.h
//  PC003
//
//  Created by Joshua Duncan on 10/16/15.
//  Copyright (c) 2015 Joshua Duncan. All rights reserved.
//

#include <iostream>

using namespace std;

#ifndef PC003_Linked_h
#define PC003_Linked_h

class Linked
{
private:
    struct Node
    {
        int i;
        Node* next;
    };
    
    Node* head;
    
public:
    Linked();
    ~Linked();
    void clear();
    int push( int );
    int pop( int& );
    int enqueue( int );
    int dequeue( int& );
    int top( int& ) const;
    bool isFull() const;
    bool isEmpty() const;
    void print() const;
};

Linked::Linked()
{
    head = NULL;
}

Linked::~Linked()
{
    Node* temp = NULL;
    
    while( head )
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void Linked::clear()
{
    Node* temp = NULL;
    
    while( head )
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int Linked::push( int i )
{
    Node* temp = new Node;
    temp->i = i;
    
    if( head == NULL )
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        head = head->next;
        temp->next = head;
        head = temp;
    }
    
    return 0;
}

int Linked::pop( int& i )
{
    if( isEmpty() == true )
    { return -1; }
    
    Node* temp = new Node;
    temp = head;
    i = temp->i;
    head = head->next;
    
    delete temp;
    
    return 0;
}

int Linked::top( int& i ) const
{
    if( isEmpty() == true )
    { return -1; }
    
    Node* temp = new Node;
    temp = head;
    i = temp->i;
    
    delete temp;
    
    return 0;
}

int Linked::enqueue( int i )
{
        Node* newNode = new Node;
        newNode->i = i;
        newNode->next = NULL;
    
    if( head == NULL )
    { head = newNode; }
    
    Node* p = head;
    
    while( p->next )
    { p = p->next; }
    
    p->next = newNode;
    
    return 0;
}

int Linked::dequeue( int& i )
{
    if( head == NULL )
    { return -1; }
    
    Node* temp = head;
    i = temp->i;
    head = head->next;
    
    delete temp;
    
    return 0;
}

bool Linked::isFull() const
{
    Node* newNode;
    
    try
    {
        newNode = new Node;
        delete newNode;
        return false;
    }
    catch ( bad_alloc exception )
    { return true; }
}

bool Linked::isEmpty() const
{
    bool empty = false;
    
    if( head == NULL )
    { empty = true; }
    
    return empty;
}

void Linked::print() const
{
    Node* temp = head;
    
    while( temp )
    {
        cout << temp->i << " ";
        temp = temp->next;
    }
    cout << endl;
}
#endif
