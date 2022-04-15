/******************************************************************************* 
 File:   CircularDoublyLinkedList.cpp
 Author: Joya Gedeon.
  
 ************************ CircularDoublyLinkedList.cpp *************************
 
 This File implements CircularDoublyLinkedList member functions.
  
 Created on October 30, 2021, 12:13  AM 
*******************************************************************************/
 
#ifndef CIRCULARDOUBLYLINKEDLIST_CPP
#define CIRCULARDOUBLYLINKEDLIST_CPP

#include "CircularDoublyLinkedList.h"
#include "DNode.h"
#include <cassert>

using namespace std;

//***** Definition of class constructor
CircularDoublyLinkedList::CircularDoublyLinkedList(){
    // Default values for Data members
    myFirst = NULL;
    mySize  = 0;
}

//***** Definition of class copy constructor   
CircularDoublyLinkedList::CircularDoublyLinkedList
                        (const CircularDoublyLinkedList& original){
    // Copying original's size to this object.
    mySize = original.mySize;
    // Declaring a new pointer, pointing to original's first node.
    NodePtr origPtr = original.myFirst;

    // Deep copy of original's node list.
    while(origPtr != NULL){
        // Calling insertAtEnd method to insert temp's data to this object.
        insertAtEnd(origPtr->getData());
        // Changing tempPtr's pointing to the next node.
        origPtr = origPtr->getNext();
    }
    // tempPtr is now pointing to NULL
    origPtr = origPtr->getNext();
    delete origPtr;
}

//***** Definition of class destructor
CircularDoublyLinkedList::~CircularDoublyLinkedList(){
    NodePtr tempPtr;
    // while there is still nodes in the list
    while(myFirst->getNext() != myFirst){
        tempPtr = myFirst;
        myFirst = myFirst->getNext();
        delete tempPtr;
    }
    myFirst = NULL;
    delete myFirst;
}

//***** Definition of class clear()
void CircularDoublyLinkedList::clear (){
    if(myFirst != NULL){
        NodePtr tempPtr;
        while(myFirst->getNext() != myFirst){
            tempPtr = myFirst;
            myFirst = myFirst->getNext();
            delete tempPtr;
            mySize--;
        }
    }
    myFirst = NULL;  
}

//***** Definition of class empty()
bool CircularDoublyLinkedList::isEmpty() const{
    // if it is equal to 0, then list empty, else not empty.
    return mySize == 0;
}

//***** Definition of class size()
int CircularDoublyLinkedList::size() const{
    // return mySize value as the size of the list
    return mySize;
}

//***** Definition of class searchFirstOccurence()
NodePtr CircularDoublyLinkedList::searchFirstOccurence(ElementType n){
    // Checking that list is not empty
    assert(!isEmpty());
    // Assigning a pointer to myFirst.
    NodePtr locPtr = myFirst;
    // Checking if first node's data is equal to n
    if(locPtr->getData() == n)
        return locPtr;
    else {
        // checking if n existing in the middle
        while(locPtr->getNext()->getData() != n)
            locPtr = locPtr->getNext();
         // Case where it doesn't exist
        if(locPtr == myFirst)
            locPtr = NULL;
        else
            // Case it does exist.
            locPtr = locPtr->getNext();
    }
    return locPtr;  
}

//***** Definition of class insertAtBeginning()
void CircularDoublyLinkedList::insertAtBeginning(ElementType n){
    NodePtr newNode = new DNode(n);
    // Case where the list doesn't have any node yet.
    if (isEmpty()){
        myFirst = newNode;
        myFirst->setNext(newNode);
        myFirst->setPrevious(newNode);   
    }
    // List isn't empty.
    else{
         myFirst->getPrevious()->setNext(newNode);
         newNode->setPrevious(myFirst->getPrevious());
         myFirst->setPrevious(newNode);
         newNode->setNext(myFirst);
         myFirst = newNode;      
    }
    mySize++;
}

//***** Definition of class insertAtEnd()
void CircularDoublyLinkedList::insertAtEnd(ElementType n){
    NodePtr newNode = new DNode(n);
    // Case where the list doesn't have any node yet.
    if(isEmpty()){
        myFirst = newNode;
        myFirst->setNext(newNode);
        myFirst->setPrevious(newNode);
    }
    else{
        // List isn't empty.
        NodePtr tempPtr = myFirst;
        myFirst->getPrevious()->setNext(newNode);
        newNode->setPrevious(myFirst->getPrevious());
        newNode->setNext(myFirst);
        myFirst->setPrevious(newNode);
    }
    mySize++;
}

//***** Definition of class insertAtPos()
void CircularDoublyLinkedList::insertAtPos(ElementType n, int pos){
    // Checking list isn't empty.
    assert(!isEmpty());                                                     
    NodePtr newNode = new DNode(n);
    NodePtr posPtr = myFirst;
    
    // Case where input position out of range
    if (pos < 0 || pos >= mySize)
        cerr << "InsertAtPos_Error: ***Position Out Of Boundaries*** ";
    else {
        // position at beginning
        if (pos == 0)
            insertAtBeginning(n);
        else 
            // position at end
            if (pos == mySize)
                insertAtEnd(n);
        else {
            // position at the middle
            for(int i = 1; i < pos - 1; i++)
                posPtr = posPtr->getNext();
            
            newNode->setNext(posPtr->getNext());
            posPtr->getNext()->setPrevious(newNode);
            posPtr->setNext(newNode);
            newNode->setPrevious(posPtr);
        }
        mySize++;
    }   
}

//***** Definition of class insertMBeforeN()
bool CircularDoublyLinkedList::insertMBeforeN(ElementType m, ElementType n){
    // Checking list isn't empty.
    assert(!isEmpty());
    NodePtr newNode = new DNode (m);
    NodePtr locPtr = myFirst;
    // Loop to stop before the node of data n
    while(locPtr->getNext()->getData() != n)
        locPtr =locPtr->getNext();
    // Case where node doesn't exist.
    if(locPtr->getNext() == myFirst){
        cerr << "InsertMBeforeN_Error: **** ELEMENT NOT FOUND ****";
        return false;
    }
    // Case where node exists.
    else {
        newNode->setNext(locPtr->getNext());
        locPtr->getNext()->setPrevious(newNode);
        locPtr->setNext(newNode);
        newNode->setPrevious(locPtr);
        mySize++;
    } 
    return true;
}

//***** Definition of class deleteAtBeginning()
void CircularDoublyLinkedList::deleteAtBeginning(){
    // Checking list isn't empty.
    assert(!isEmpty());
    // Case where there is only one node
    if (myFirst->getNext() == myFirst)
        myFirst = NULL;
    // Case where there's more than one node.
    else{
        NodePtr tempPtr = myFirst;
        myFirst->getNext()->setPrevious(myFirst->getPrevious());
        myFirst->getPrevious()->setNext(myFirst->getNext()->getNext());
        myFirst = myFirst->getNext();
        delete tempPtr;
    }
    mySize--;
}

//***** Definition of class deleteAtEnd()
void CircularDoublyLinkedList::deleteAtEnd() {
    // Checking list isn't empty.
    assert(!isEmpty());
    // Case where there is only one node
    if(myFirst->getNext() == myFirst)
        myFirst->setData(0);
    else{
        // Case where there's more than one node.
        NodePtr locPtr = myFirst;
        while(locPtr->getNext() != myFirst)
            locPtr = locPtr->getNext();
        (locPtr->getPrevious())->setNext(myFirst);
        myFirst->setPrevious(locPtr);
    }
    mySize--;
}

//***** Definition of class deleteAtPos()
bool CircularDoublyLinkedList::deleteAtPos(int pos) {
    // Checking list isn't empty.
    assert(!isEmpty());
    // Case where position out of range.
    if(pos < 0 || pos > mySize){
        cerr << "DeleteAtPos_Error: **** POSITION OUTOF BOUNDS ****"; 
        return false;
    }
    else {
        // Case where position at beginning.
        if (pos == 0){
            deleteAtBeginning();
            return true;
        }
        // Case where position at end.
        else if (pos == mySize){
                deleteAtEnd();
                return true;
        }
        // Case where position at the middle.
        else {
            NodePtr posPtr = myFirst;
            for(int i = 1; i < pos - 1; i++)
                posPtr = posPtr->getNext();
                
            NodePtr tempPtr = posPtr->getNext();
            
            posPtr->setNext(posPtr->getNext()->getNext());
            posPtr->getNext()->getNext()->setPrevious(posPtr);
            delete tempPtr;
            mySize--;
            return true;
        }
    }
}

//***** Definition of class deleteN()
bool CircularDoublyLinkedList::deleteN(ElementType n) {
    // Checking list isn't empty.
    assert(!isEmpty());
    NodePtr locPtr = myFirst;
    //Loop to stop before node holding as data n
    while (locPtr->getNext()->getData() != n)
        locPtr = locPtr->getNext();
    // Case where node doesn't exist.
    if (locPtr->getNext() == myFirst){
        cerr << "DeleteN_Error: **** ELEMENT NOT FOUND **** ";
        return false;
    }
    // Case where node existts.
    else{
        locPtr->setNext((locPtr->getNext())->getNext() );
        (locPtr->getNext())->setPrevious(locPtr);
        mySize--;
        return true;
    } 
}

//***** Definition of class cutN()
NodePtr CircularDoublyLinkedList::cutN(ElementType n) {
     // Checking list isn't empty.
    assert(!isEmpty());
    // Search for the node holding as data n
     NodePtr temp = searchFirstOccurence(n);
     // case where node doesn't exist.
     if (temp == NULL)
         return NULL;
     else {
         // case where node doesn't exist.
         NodePtr locPtr = temp;
         deleteN(temp->getData());
         return locPtr;
     }
}

//***** Definition of class display()
ostream& CircularDoublyLinkedList::display (ostream& output) const{
    //Empty list
    if (isEmpty())
        output << "Empty List";
    else {
        //List Not Empty
        NodePtr locPtr = myFirst;
        output << "The list is: "
               << locPtr->getData();
        locPtr = locPtr->getNext();
        for(int i = 1; i < size(); i++) {
            output <<  " -> " << locPtr->getData();
            locPtr = locPtr->getNext();
        }
        cout << " .\n";
    }
    return output;
}   

//***** Definition of class output operator
ostream& operator << (ostream& output, const CircularDoublyLinkedList& list){
    output<< endl;
    list.display (output);
    return output;
}

#endif /* CIRCULARDOUBLYLINKEDLIST_CPP */