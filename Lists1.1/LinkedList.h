//
//  LinkedList.h
//  PC02
//
//  Created by Joshua Duncan on 10/11/15.
//  Copyright (c) 2015 Joshua Duncan. All rights reserved.
//

/*
 Rename this file to LinkedList.h before submitting.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class LinkedList
{
private:
    
    struct Node
    {
        int x;
        Node* next;
    };
    
    Node* head;
    
public:
    LinkedList();
    ~LinkedList();
    void clear();
    int insert( int );
    int append( int );
    int remove( int );
    bool isFull() const;
    bool isEmpty() const;
    int getLength() const;
    bool find( int ) const;
    void print() const;
};

LinkedList::LinkedList()
{
    // initialize head to null
    head = NULL;
}

LinkedList::~LinkedList()
{
    // delete all nodes in the linked list
    Node* temp = NULL;
    
    while( head )
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::clear()
{
    // initialize a helper pointer to NULL
    Node* temp = NULL;
    
    // while the head pointer is not NULL
    while( head )
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    // set helper to head
    // set head to head's next pointer
    // delete helper
}

int LinkedList::append( int i )
{
// check if there is room, if full quit, returning -1
    if( isFull() == false )
    { return -1; }
// create the new node
    
    Node* newNode = new Node;
    newNode->x = i;
    newNode->next = NULL;
    
// if the list is empty, attach the new node to the head
    
    if( head == NULL )
    {  head = newNode; }
    
// if not, we have to traverse to the end of the list
// need a helper pointer for the traversal, set to head
    
    Node* p = head;
    
// do the traversal
    
    while( p->next )
    { p = p->next; }
    
// attach the new node to the end of the list

    p->next = newNode;
    
    return 0;
};

int LinkedList::remove( int i )
{
    // check if empty
    if( head == NULL )
    { return -1; }
    // check if value is in first node
    // is so, set helper variable to head
    // advance head pointer
    // delete node helper variable points to
    
    if( head->x == i )
    {
        Node* p = head;
        
        head = head->next;
        
        delete p;
        
        return 0;
    }
    // otherwise, we have to go searching
    // set helper pointers to head and head->next, respectively
    
    Node* p = head, *prev = NULL;
    while( p != NULL && p->x != i )
    {
        prev = p;
        p = p->next;
    }
    // if node lead pointer is not NULL and doesn't contain
    // the value you want to remove, advance both pointers
    
    // once that's finished, p is NULL or it's not.  If it's NULL,
    // quit because we didn't find the node to delete.
    if( p == NULL )
    { return -1; }
    // otherwise, we have to set the trailer pointer to point to
    // the node following the lead pointer's node
    if( p != NULL )
    {
        prev->next = p->next;
        delete p;
    }
    // then we can delete the node the lead pointer points to
    return 0;
};

bool LinkedList::isFull() const
{
    // attempt to dynamically allocate a new node
    Node* newNode;
    // if that fails, return false
    try {
        newNode = new Node;
        delete newNode;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
    // otherwise, delete it then return true
};

bool LinkedList::isEmpty() const
{
    bool empty = false;
    
    if( head == NULL )
    {
        empty = true;
    }
    // returns true if the list is empty, false otherwise
    return empty;
};

void LinkedList::print() const
{
    // set a temp pointer to head
    Node* temp = head;
    // use it to traverse the list, printing as we go
    while( temp )
    {
        cout << temp->x << " ";
        temp = temp->next;
    }
    cout << endl;
    // while temp pointer is not null
    
    // print the value in the node whose address temp holds
    
    // advance the pointer
    
}

int LinkedList::getLength() const
{
    int counter = 0;
    // initialize a counter to 0
    
    // set a temp pointer to head
    Node* temp = head;
    
    while( temp )
    {
        ++counter;
        temp = temp->next;
    }
    // while temp pointer isn't null,
    // increment the counter
    // advance the temp pointer
    
    
    // return the counter
    return counter;
};

bool LinkedList::find( int i ) const
{
    // set a temp pointer to the head pointer
    bool found = false;
    
    Node* temp = head;
    
    while( temp )
    {
        if( temp->x == i )
        {
            found = true;
        }
        
        temp = temp->next;
    }
    // while the temp pointer is not null
    // if the node's value equal's i, return true
    // advance the pointer
    
    
    return found;
};

int LinkedList::insert( int i )
{
    // if full, nothing to do, return
    
// create our new node
    
    Node* newNode = new Node;
    newNode->x = i;
    
// now we need to find where the node goes
    
    
    
    // if the list is empty, hang it on head and return
    
    if( head == NULL )
    {
        // set head to new pointer
        head = newNode;
            // set next to null if you haven't yet
        newNode->next = NULL;
    }
    
    Node* prev = NULL, *p = head;
    
    // if not, does the new node go at the front?  Is it's value
    // less than the value of the head node?
    
    if( newNode->x < head->x )
    {
        newNode->next = head->next;
        head = newNode;
        return 0;
    }
    // set new node's next to head
    // set head to the new node, then return;
    
    while( p!= NULL && p->x < newNode->x )
    {
        prev = p;
        p = p->next;
    }
    // if we get this far, we have to find the insertion point.
    // set the trailer pointer to head and the lead pointer to
    // head->next and let's go looking
    
    if( p == NULL )
    {
        prev->next = newNode;
        newNode->next = NULL;
        return 0;
    }
    else
    {
        newNode->next = p;
        prev->next = newNode;
        return 0;
    }
    // keep advancing lead and trailer so long as the
    // lead pointer isn't set to NULL
    // and the value of the node it points to is less than the
    // new node's value
    
    // one the pointers stop moving...
    // set the new node's next to the lead pointer
    // set the trailer node's next to the new node and return
    
    return 0;
};

#endif
