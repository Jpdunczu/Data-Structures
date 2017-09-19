//
//  TREE.h
//  PC06
//
//  Created by Joshua Duncan on 11/17/15.
//  Copyright (c) 2015 Joshua Duncan. All rights reserved.
//

#ifndef PC06_TREE_h
#define PC06_TREE_h

#include <iostream>
#include <cstdlib>
using namespace std;

class Tree
{
private:
    struct Node
    {
        int i;
        Node* right;
        Node* left;
    };
    
    Node* root;
    
    void clear( Node*& n )
    {
        if( n != NULL )
        {
            clear( n->left );
            clear( n->right );
            delete n;
        }
    }
    
    void insert( Node*& r, Node* n )
    {
        if( r == NULL )
        {
            r = new Node;
            r->i = n->i;
            r->right = NULL;
            r->left = NULL;
        }
        
        if( r->i < n->i )
        {
            insert( r->right, n );
        }
        
        if( r->i > n->i )
        {
            insert( r->left, n );
        }
    }
    
    void inprint( Node* n ) const
    {
        if( n )
        {
            inprint( n->left );
            cout << n->i << ", ";
            inprint( n->right );
        }
    }
    
    bool find( Node* n, int i ) const
    {
        if( n != NULL )
        {
            if( n->i == i )
            { return true; }
            else if ( i < n->i )
            { find( n->left, i ); }
            else
            { find( n->right, i ); }
        }
        return false;
    }
    
    int seek( Node*& n, int i )
    {
            if ( i < n->i )
            { seek( n->left, i ); }
            else if ( i > n->i )
            { seek( n->right, i ); }
            else
            {
                destroy( n );
                return 0;
            }
        
        return -1;
    }
    
    void destroy( Node*& n )
    {
        Node* nodeToDestroy = n;
        
        Node* attachPoint;
        
        if( n->right == NULL )
        { n = n->left; }
        else if ( n->left == NULL )
        { n = n->right; }
        else
        {
            attachPoint = n->right;
            
            while( attachPoint->left != NULL )
            {
                attachPoint = attachPoint->left;
            }
            attachPoint->left = n->left;
            
            n = n->right;
        }
        
        delete nodeToDestroy;
    }
    
    int count( Node* n ) const
    {
        if( n == NULL )
        {
            return 0;
        }
        else
        {
            return count(n->left) + count(n->right) + 1;
        }
        
    }
    
    void copyTree( Node*& copy, const Node* r )
    {
        if( r == NULL )
        { copy = NULL; }
        else
        {
            copy = new Node;
            copy->i = r->i;
            copyTree( copy->left, r->left );
            copyTree( copy->right, r->right );
        }
    }
    
public:
    Tree()
    { root = NULL; }
    
    Tree( const Tree& rhs )
    { copyTree( root, rhs.root ); }
    
    ~Tree()
    { clear( root ); }
    
    Tree& operator= ( const Tree& rhs )
    {
        Tree lhs( rhs );
        return lhs;
    }
    
    bool operator== ( const Tree& rhs )
    { return count( root ) == count( rhs.root ); }
    
    bool operator< ( const Tree& rhs )
    { return count( root ) < count( rhs.root ); }
    
    bool isFull() const
    {
        Node* dummy;
        
        try
        {
            dummy = new Node;
            delete dummy;
            return false;
        } catch (bad_alloc exception) {
            return true;
        }
    }
    
    bool isEmpty() const
    { return root == NULL; }
    
    void clear()
    { clear( root ); }
    
    int insert( int i )
    {
        Node* newNode = new Node;
        newNode->i = i;
        
        if( isFull() == true )
        { return -1; }
        
        insert( root, newNode );
        
        return 0;
    }
    
    bool find( int i ) const
    {
        return find( root, i );
    }
    
    int remove( int i )
    { return seek( root, i ); }
    
    void inprint() const
    { inprint( root ); }
    
    void count() const
    {
        cout << count( root );
    }
    
};

#endif
