//
//  Circular.h
//  PC04
//
//  Created by Joshua Duncan on 10/24/15.
//  Copyright (c) 2015 Joshua Duncan. All rights reserved.
//

#include <iostream>

using namespace std;

#ifndef PC04_Circular_h
#define PC04_Circular_h

class Circular
{
private:
    struct Node
    {
        int i;
        Node* next;
    };
    Node* p; // head
    Node* q; // current
    
public:
    Circular();
    Circular( const Circular& c );
    ~Circular();
    Circular& operator= ( const Circular& c );
    bool operator== ( const Circular& c ) const;
    bool operator< ( const Circular& c ) const;
    void clear();
    int insert( int i );
    int remove( int i );
    int getNext( int& i );
    bool find( int i ) const;
    bool isFull() const;
    bool isEmpty() const;
    void print() const;
};
#endif


Circular::Circular()
{ };
Circular::Circular( const Circular& c )
{ operator=( c ); };

Circular::~Circular()
{ clear(); };

void Circular::clear()
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
    };
    
Circular& Circular::operator= ( const Circular& c )
    {
        if( this != &c )
        {
            Node* temp = p;
            
            while( temp != NULL )
            {
                temp->i = c.p->i;
                temp = temp->next;
            }
            p = c.p;
            q = c.q;
        }
        
        return *this;
    };
    
bool Circular::operator== ( const Circular& c ) const
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
        
        temp = c.p;
        
        while( temp != NULL )
        {
            temp2++;
            temp = c.p->next;
        }
        
        if( temp1 == temp2 )
        { equals = true; }
        
        return equals;
    };

bool Circular::operator< ( const Circular& c ) const
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
    
    temp = c.p;
    
    while( temp != NULL )
    {
        temp2++;
        temp = c.p->next;
    }
    
    if( temp1 < temp2 )
    { lessThan = true; }
    
    return lessThan;
};

int Circular::insert( int i )
{
    Node* newNode = new Node;
    newNode->i = i;
    
    if( isFull() == false )
    { return -1; }
    
        if( p == NULL )
        {
            p = newNode;
            newNode->next = NULL;
            return 0;
        }
    
    Node* prev = NULL;
    Node* temp = p;
    
    if( newNode->i < p->i )
    {
        newNode->next = p->next;
        p = newNode;
        return 0;
    }
    
    while( temp != NULL && temp->i < newNode->i )
    {
        prev = temp;
        temp = temp->next;
    }
    
    if( temp == NULL )
    {
        prev->next = newNode;
        newNode->next = NULL;
        return 0;
    }
    else
    {
        newNode->next = temp;
        prev->next = newNode;
        return 0;
    }
    
    return 0;
};

int Circular::remove( int i )
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
    Node* prev = NULL;
    while( temp != NULL && temp->i != i )
    {
        prev = temp;
        temp = temp->next;
    }
    
    if( temp == NULL )
    { return -1; }
    
    if( temp != NULL )
    {
        prev->next = temp->next;
        delete temp;
    }
    
    return 0;
};

bool Circular::find( int i ) const
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
};

bool Circular::isFull() const
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
};

bool Circular::isEmpty() const
{
    bool empty = false;
    
    if( p == NULL )
    {
        empty = true;
    }
    
    return empty;
};

void Circular::print() const
{
    Node* temp = p;

    while( temp )
    {
        cout << temp->i << " ";
        temp = temp->next;
    }
    
    cout << endl;
};

int Circular::getNext( int& i )
{
    try
    {
        i = q->i;
        q = q->next;
        
        if( i != q->i )
        {
            throw "fail";
        }
    }
    catch (string)
    {
        return -1;
    }
    
    return 0;
};