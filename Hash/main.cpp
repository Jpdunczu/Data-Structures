//
//  main.cpp
//  PC08
//
//  Created by Joshua Duncan on 12/4/15.
//  Copyright (c) 2015 Joshua Duncan. All rights reserved.
//

#include <iostream>
#include "Hash.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Hash t(30);
    Hash t2(30);
    
    //cout << t.isFull() << endl;
    //cout << t.isEmpty() << endl;
    
    t.insert( "Joshua Duncan" );
    t.insert( "Jonathan Dunham" );
    t.insert( "Phuntsok Dolma" );
    
    //cout << t.size() << endl;
    t2 = t;
    //cout << "t2 size = " << t2.size() << endl;
    
    //t.print();
    
    //cout << "t2 print = : " << endl;
    
    //t2.print();
    
    t.insert( "Joshua Duncan" );
    t.insert( "Jobajd hgnesn" );
    
    t.print();
    cout << t.size() << endl;
    if( t.find( "Joshua Duncan" ) == true )
    { cout << "yes" << endl; }
    else
    { cout << "no" << endl; }
    
   
    t.remove( "Jobajd hgnesn" );
    t.print();
    
    t.clear();
    cout << "clear";
    
    t.print();
    return 0;
}
