//
//  main.cpp
//  PC1802
//
//  Created by Joshua Duncan on 5/27/15.
//  Copyright (c) 2015 Joshua Duncan. All rights reserved.
//
#include "MyStack.h"
#include <iostream>
#include <string>

int main(int argc, const char * argv[])
{
    DynamicStack<char> stack;
    
    int size = 0;
    
    char *c;
    c = new char;
    
    cout << ">> ";
    cin.getline(c, 50);
    
    size = strlen( c );
    
    for( int i = 0; i < size; i ++ )
    { stack.push(c[i]); }
    
    char item;
    for( int i = 0; i < size ; i ++)
    {
        try
        {
            stack.pop(item);
            cout << item;
        }
        catch( const char* exc )
        { cout << exc; }
    }
    
    delete [] c;
    
    return 0;
}
