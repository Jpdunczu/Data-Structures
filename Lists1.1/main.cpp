//
//  main.cpp
//  PC02
//
//  Created by Joshua Duncan on 10/11/15.
//  Copyright (c) 2015 Joshua Duncan. All rights reserved.
//

#include "LinkedList.h"
#include "ArrayList.h"

#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    LinkedList l;
    ArrayList a(10);
    
    for ( int i = 0; i < 10; i++ )
    {
        a.insert( rand() % 100 );
        a.append( 5 );
        a.print();
    }
    
    cout << endl;
    
    a.print();
    
    cout << a.find( 86 ) << " " << a.find( 0 ) << endl;
    
    cout << a.remove(77) << " " << a.remove(0) << endl;
    
    cout << a.getLength();
    a.print();
    for ( int i = 0; i < 4; i++ )
        cout << l.append( rand() % 100 ) << " ";
    
    cout << endl;
    
    
    l.print();
    
    cout << "length=" << l.getLength() << endl;
    
    cout << l.find(77) << " " << l.find(12) << endl;
    
    cout << l.remove(77) << " " << l.remove(12) << endl;
    
    
    l.insert(87);
    l.print();
    
    l.clear();
    
    l.print();
    
    cout << "length=" << l.getLength() << endl;
    
   
    return 0;
}
