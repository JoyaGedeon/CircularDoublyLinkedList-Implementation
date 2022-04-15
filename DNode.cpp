/******************************************************************************* 
 File:   DNode.h
 Author: Joya Gedeon.
 
 *********************************** DNode.cpp *********************************
 
 This File implements DNode member functions.
 
 Created on October 30, 2021, 11:40 AM
  
*******************************************************************************/
#include "DNode.h"

//***** Definition of class constructor
DNode::DNode(ElementType n){
    setData(n); // method setting data to n
    setPrevious(NULL); // method setting previous pointer to NULL
    setNext(NULL); // method setting previous next to NULL
}

//***** Definition of class setData()
void DNode::setData(ElementType n){
    // Setting data to n
    this->data = n;
}

//***** Definition of class setPrevious()
void DNode::setPrevious(DNode* previous){
    // Setting previous pointer to NULL
    this->previous = previous;
}

//***** Definition of class setNext()
void DNode::setNext(DNode* next){
    //Setting previous next to NULL
    this->next = next;
}

//***** Definition of class getData()
ElementType DNode::getData() const{
    // returns the node's data
    return data;
}

//***** Definition of class getPrevious()
DNode* DNode::getPrevious() const{
    // returns the node's previous 
    return previous;
}

//***** Definition of class getNext()
DNode* DNode::getNext() const{
    // returns the node's next
    return next;
}
