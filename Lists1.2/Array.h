//
//  Array.h
//  PC003
//
//  Created by Joshua Duncan on 10/16/15.
//  Copyright (c) 2015 Joshua Duncan. All rights reserved.
//

#include <iostream>

using namespace std;

#ifndef PC003_Array_h
#define PC003_Array_h

class Array
{
private:
    int* a;
    int capacity;
    int length;
    
public:
    Array( int c )
    {
        capacity = c;
        length = 0;
        a = new int[c];
    }
    
    ~Array()
    { delete [] a; }
    
    void clear()
    {
        for( int i = 0; i <= length; i++ )
        { a[i] = 0; }
        
        length = 0;
    }
    
    int push( int i )
    {
        int x;
        
        if( isFull() == true )
        { return -1; }
        
        a[top(x)] = i;
        length++;
        
        return 0;
    }
    
    int pop( int& i )
    {
        int x;
        
        if( isEmpty() == true )
        { return -1; }
        
        i = a[top(x)];
        length--;
        
        return 0;
    }
    
    int enqueue( int i )
    {
        int rear;
        
        if( isFull() == true )
        { return -1; }
        
        a[((top(rear)+1)%capacity)] = i;
        length++;
        
        return 0;
    }
    
    int dequeue( int& i )
    {
        int front;
        
        if( isEmpty() == true )
        { return -1; }
        
        i = a[((top(front)+capacity)-1)%capacity];
        length--;
        
        return 0;
    }
    
    int top( int& i ) const
    {
        i = length;
        
        return i;
    }
    
    bool isFull() const
    {
        bool full = true;
        if( length < capacity )
        { full = false; }
        
        return full;
    }
    
    bool isEmpty() const
    {
        bool empty = false;
        if( length == 0 )
        { empty = true; }
        
        return empty;
    }
    
    void print() const
    {
        for( int i = 0; i <= length; i++ )
        cout << a[i] << ", ";
    }
};

#endif
