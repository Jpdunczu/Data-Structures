//
//  ArrayList.h
//  PC02
//
//  Created by Joshua Duncan on 10/11/15.
//  Copyright (c) 2015 Joshua Duncan. All rights reserved.
//

#ifndef PC02_ArrayList_h
#define PC02_ArrayList_h

#include <iostream>

using namespace std;

class ArrayList
{
private:
    int *a;
    int capacity;
    int length;
    
public:
    ArrayList( int c )
    {
        a = new int[c];
        capacity = c;
        length = 0;
    }
    
    ~ArrayList()
    { delete [] a; }
    
    void clear()
    {
        for( int i = 0; i <= length; i++ )
        {
            a[i] = 0;
        }
        
        length = 0;
    }
    
    int insert( int i )
    {
        if( isFull() == true )
        {
            return -1;
        }
        else
        {
        int j;
        // searchin
        for ( j = 0; j <= length && i > a[j]; j++ );
        
        // shiftin
        for ( int k = length; k > j; k-- )
            a[k] = a[k-1];
        
        a[j] = i;
        
        length++;
        }
        
        return 0;
    }
    
    int append( int i )
    {
        if( isFull() == false )
        {
            a[length + 1] = i;
            length++;
            return 0;
        }
        
        return -1;
    }
    
    int remove( int i )
    {
        for( int j = 0; j <= length; j++ )
        {
           if( a[j] == i )
           { a[j] = 0; }
        }
        
        return 0;
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
    
    int getLength() const
    {
        return length;
    }
    
    bool find( int i ) const
    {
        bool found = false;
        for( int j = 0; j <= length; j++ )
        {
            if( a[j] == i )
            { found = true; }
        }
        
        return found;
    }
    
    void print() const
    {
        for( int i = 0; i <= length; i++ )
        cout << a[i] << ", ";
    }
};

#endif
