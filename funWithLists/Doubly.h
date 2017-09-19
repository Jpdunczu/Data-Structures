//
//  Doubly.h
//  PC04
//
//  Created by Joshua Duncan on 10/24/15.
//  Copyright (c) 2015 Joshua Duncan. All rights reserved.
//

#include <iostream>

using namespace std;

#ifndef PC04_Doubly_h
#define PC04_Doubly_h

class Doubly
{
private:
    struct Node
    {
        int i;
        Node* next;
        Node* prev;
    };
    
    Node* p; // head
    Node* q; // tail
    
public:
    Doubly();
    Doubly( const Doubly& d );
    ~Doubly();
    Doubly& operator= ( const Doubly& d );
    bool operator== ( const Doubly& d ) const;
    bool operator< ( const Doubly& d ) const;
    void clear();
    int insert( int i );
    int remove( int i );
    bool find( int i ) const;
    void reverse() const;
    bool isFull() const;
    bool isEmpty() const;
    void print() const;
};

Doubly::Doubly()
{
    p = NULL;
    q = NULL;
}

Doubly::Doubly( const Doubly& d )
{
    operator=( d );
}

Doubly::~Doubly()
{
    clear();
}

Doubly& Doubly::operator= ( const Doubly& d )
{
    if( this != &d )
    {
        Node* temp = p;
        
        while( temp != NULL )
        {
            temp->i = d.p->i;
            temp = temp->next;
        }
        
        q = d.q;
        p = d.p;
    }
    
    return *this;
}

bool Doubly::operator== ( const Doubly& d ) const
{
    int temp1 = 0;
    int temp2 = 0;
    bool equals = false;
    
    Node* temp = p;
    
    while( temp != NULL )
    {
        temp1++;
        temp = temp->next;
    }
    
    temp = d.p;
    
    while( temp != NULL )
    {
        temp2++;
        temp = d.p->next;
    }
    
    if( temp1 == temp2 )
    { equals = true; }
    
    return equals;
}

bool Doubly::operator< ( const Doubly& d ) const
{
    int temp1 = 0;
    int temp2 = 0;
    bool lessThan = false;
    
    Node* temp = p;
    
    while( temp != NULL )
    {
        temp1++;
        temp = temp->next;
    }
    
    temp = d.p;
    
    while( temp != NULL )
    {
        temp2++;
        temp = d.p->next;
    }
    
    if( temp1 < temp2 )
    { lessThan = true; }
    
    return lessThan;
}

int Doubly::insert( int i )
{
    Node* newNode = new Node;
    newNode->i = i;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    if( isFull() == false )
    { return -1; }
    else
    {
        if( p == NULL )
        {
            p = newNode;
            newNode->next = q;
            newNode->prev = NULL;
            return 0;
        }
        
        if( newNode->i < p->i )
        {
            p->prev = newNode;
            newNode->next = p;
            newNode->prev = NULL;
            p = newNode;
            
            return 0;
        }
        
        Node* temp = p;
        temp->prev = NULL;
        
        while( temp != NULL && temp->i < newNode->i )
        {
            temp->prev = temp;
            temp = temp->next;
        }
        
        if( temp == NULL )
        {
            temp = newNode;
            newNode->prev = temp->prev;
            newNode->next = NULL;
            q = newNode;
            return 0;
        }
    }
    return -1;
}

void Doubly::print() const
{
    Node* temp = p;
    
    while( temp != NULL )
    {
        cout << temp->i << ", ";
        temp = temp->next;
    }
    cout << endl;
}

void Doubly::reverse() const
{
    Node* temp = p;
   
    if( temp == NULL )
    { return; }
    
    while( temp->next != NULL )
    { temp = temp->next; }
    while( temp != NULL )
    {
        cout << temp->i << ", ";
        temp = temp->prev;
    }
    cout << endl;
}

bool Doubly::isFull() const
{
    Node* newNode;
    
    try {
        newNode = new Node;
        delete newNode;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

bool Doubly::isEmpty() const
{
    bool empty = false;
    
    if( p == NULL )
    {
        empty = true;
    }
    
    return empty;
}

int Doubly::remove( int i )
{
    if( p == NULL )
    { return -1; }
    
    if( p->i == i )
    {
        Node* temp = p;
        p = p->next;
        delete temp;
        return 0;
    }
    
    Node* temp = p;
    temp->prev = NULL;
    
    while( temp != NULL && temp->i != i )
    {
        temp->prev = temp;
        temp = temp->next;
    }
    if( temp == NULL )
    { return -1; }
    
    if( temp != NULL )
    {
        q = temp->prev;
        q->next = NULL;
        delete temp;
    }
    return 0;
}

bool Doubly::find( int i ) const
{
    bool found = false;
    
    Node* temp = p;
    
    while( temp )
    {
        if( temp->i == i )
        {
            found = true;
        }
        
        temp = temp->next;
    }
    
    return found;
}

void Doubly::clear()
{
    Node* temp = NULL;
    
    while( p )
    {
        temp = p;
        p = p->next;
        delete temp;
    }
    
    p = NULL;
    q = NULL;
}
#endif
