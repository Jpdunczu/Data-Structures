//
//  main.cpp
//  PC06
//
//  Created by Joshua Duncan on 11/17/15.
//  Copyright (c) 2015 Joshua Duncan. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "TREE.h"

int main()
{
    Tree t;
    
    for ( int i = 0; i < 10; i++ )
        t.insert( rand() % 20 );
    
    t.inprint();
    
    Tree s(t);
    
    s.inprint();
    
    cout << ( s < t ) << ( s == t ) << endl;
    
     cout << t.find( 13 ) << t.find( -99 ) << endl;
     //cout << s.count() << endl;
     
     t.remove(12);
     t.inprint();
     
     
     Tree a;
     
     a = t;
     a.inprint();
     
     Tree r(t);
     
     r.inprint();
    
    return 0;
}
