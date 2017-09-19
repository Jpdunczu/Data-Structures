//
//  main.cpp
//  PC1804
//
//  Created by Joshua Duncan on 5/27/15.
//  Copyright (c) 2015 Joshua Duncan. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "MyQueue.h"

using namespace std;

int main(int argc, const char * argv[])
{
    DynamicQueue<int> queue;
    char answer;
    int size = 1;
    
    do
    {
        cout << "(E)nqueue" << endl;
        cout << "(D)equeue" << endl;
        cout << "(Q)uit" << endl;
        cout << "\n[DEQ]: ";
        cin >> answer;
        
        if( answer == 'e' || answer == 'E' )
            queue.Enqueue(size);
        if( answer == 'd' || answer == 'D' )
        {
            
            try
            { queue.dequeue(size); }
        catch( const char* exc )
            { cout << exc; }
        }
        if( answer == 'q' || answer == 'Q' )
            return 0;
        
        size++;
    }while(answer != 'q' && answer != 'Q');
    
    return 0;
}
