//
//  Hash.h
//  PC08
//
//  Created by Joshua Duncan on 12/4/15.
//  Copyright (c) 2015 Joshua Duncan. All rights reserved.
//

#ifndef PC08_Hash_h
#define PC08_Hash_h

#include <iostream>

using namespace std;

class chain
{
    int key;
    string s;
    chain* next;
    
public:
        chain( int key, string s )
        {
            this->key = key;
            this->s = s;
            this->next = NULL;
        }
    
        int getKey() const
        { return key; }
        
        string getString() const
        { return s; }
        
        void setString( string s )
        { this->s = s; }
        
        chain* getNext() const
        { return next; }
        
        void setNext( chain* next )
        { this->next = next; }
};

class Hash
{
    
    int len;
    int hash( string s )
    {
        int l;
        l = s.length();
        
        return l%100;
    }
    
    int capacity;
    
    chain** table;
    
public:
    Hash( int i )
    {
        table = new chain*[i];
        len = 0;
        capacity = i;
        for( int n = 0; n <= i; n++ )
        {
            table[i] = NULL;
        }
    }
    
    ~Hash()
    {
    }
    
    Hash( const Hash& rhs )
    {
        len = rhs.len;
        capacity = rhs.capacity;
        *this = rhs;
    }
    
    Hash& operator= ( const Hash& rhs )
    {
        if( rhs.isEmpty() )
        { return *this; }
        
        capacity = rhs.capacity;
        len = rhs.len;
        
        table = new chain*[rhs.capacity];
        
        for( int i = 0; i <= rhs.capacity; i++ )
        {
            table[i] = rhs.table[i];
        }
        return *this;
    }
    
    bool operator< ( const Hash& rhs ) const
    { return len < rhs.len; }

    bool operator== ( const Hash& rhs ) const
    { return len == rhs.len; }
    
    int insert( string s )
    {
        if( isFull() == true )
        { return -1; }
        
        int loc;
        loc = hash( s );
        
        if( table[loc] == NULL )
        { table[loc] = new chain( loc, s ); }
        else
        {
            chain* newChain = table[loc];

            while( newChain->getNext() != NULL )
                newChain = newChain->getNext();
            if( newChain->getKey() == loc )
            { newChain->setNext( new chain( loc, s ) ); }
        }
        
        len++;
        return 0;
    }

    int remove( string s )
    {
        if( isEmpty() == true )
        { return -1; }
        
        int loc = hash( s );
        
        if( table[loc] != NULL )
        {
            chain* prevChain = NULL;
            chain* newChain = table[loc];
            while( newChain->getNext() != NULL && newChain->getString() != s )
            {
                prevChain = newChain;
                newChain = newChain->getNext();
            }
            if( newChain->getString() == s )
            {
                
                        if( prevChain == NULL )
                        {
                            chain* nextChain = newChain->getNext();
                            delete newChain;
                            table[loc] = nextChain;
                        }
                        else
                        {
                            chain* nextChain = newChain->getNext();
                            delete newChain;
                            prevChain->setNext( nextChain );
                        }
                
                
            }
        }
        len--;
        return 0;
    }

    bool find( string s )
    {
        int loc = hash( s );
        if( table[loc] == NULL)
        { return false; }
        else
        {
            chain* newChain = table[loc];
            
            while( newChain != NULL && newChain->getString() != s )
            {
                newChain = newChain->getNext();
            }
                if( newChain == NULL )
                { return false; }
                else
                {
                    cout << newChain->getString() << endl;
                    return true;
                }
        }
        
        
        return false;
    }

    void clear()
    {
        for( int n = 0; n <= capacity; n++ )
        {
            table[n] = NULL;
        }
        capacity = 0;
        len = 0;
    }
 
    bool isFull() const
    { return len == capacity; }
    
    bool isEmpty() const
    {
        bool empty = false;
        if( len == 0 )
        { empty = true; }
        return empty;
    }
    
    int size() const
    { return len; }
    
    void print() const
    {
        for( int i = 0; i <= capacity; i ++ )
        {
            if( table[i] != NULL )
            {
                chain* newChain = table[i];
                
                while( newChain != NULL )
                {
                    cout << newChain->getString() << endl;
                    newChain = newChain->getNext();
                }
            }
        }
        
    }
 
};

#endif
