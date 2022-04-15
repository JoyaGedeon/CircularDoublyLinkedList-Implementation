/******************************************************************************* 
 File:   DNode.h
 Author: Joya Gedeon.
 
 *********************************** DNode.h ***********************************
 
 This header file defines the data type node for creating nodes in lists.
 Basic operations are:
    Constructor: Declaring a node of a Circular Doubly Linked List       
    Setters:     setData: sets a node's data private member (ElementType).
                 setPrevious: sets a node's previous private member (pointer).
                 setNext: sets a node's next private member (pointer).
    Getters:     getData: returns Node's data;
                 getPrevious: returns Node's previous.
                 getNext: returns Node's next.
*******************************************************************************/
#ifndef DNODE_H
#define DNODE_H
#include <iostream>

// Declaring ElementType a new data type 
typedef int ElementType;

class DNode{
public: 
/******** Function Members ********/
    /**/ /**/ /* Class Constructor */ /**/ /**/
    /**************************Class arg constructor****************************
    Construct a node object.

    Precondition:   None.
    Post-Condition: An empty List object is constructed; 
                     data = n (ElementType parameter data);
                     next = NULL;     (as a default value)
                     previous = NULL; (as a default value)
    ***************************************************************************/
    DNode(ElementType n);
    
    /**/ /**/ /* Class Setters */ /**/ /**/
    /********************************SetData************************************
    Set the data member "data" of a node;

    Precondition:   None.
    Post-Condition: the node's data is now equal to the parameter data
    ***************************************************************************/
    void setData(ElementType n);
    
    /*****************************SetPrevious***********************************
    set the data member "previous" of a node;

    Precondition:   None.
    Post-Condition: the node's previous is now equal to the parameter previous
    ***************************************************************************/
    void setPrevious(DNode* previous);
    
    /*******************************SetNext*************************************
    Set the data member "next" of a node;

    Precondition:   None.
    Post-Condition: the node's next is now equal to the parameter next
    ***************************************************************************/
    void setNext(DNode* next);
    
    /**/ /**/ /* Class Getters */ /**/ /**/
    /*******************************getData*************************************
    Get the data member "data" of a node;

    Precondition:   None.
    Post-Condition: the node's data is returned.
    ***************************************************************************/
    ElementType getData() const;
    /******************************getPrevious**********************************
    Get the data member "previous" of a node;

    Precondition:   None.
    Post-Condition: the node's previous is returned.
    ***************************************************************************/
    DNode* getPrevious() const;
    
    /*******************************getNext*************************************
    Get the data member "next" of a node;

    Precondition:   None.
    Post-Condition: the node's next is returned.
    ***************************************************************************/
    DNode* getNext() const;
   
private:
/******** Data Members ********/     
    ElementType data; // the data part of a node
    DNode* previous;  // the previous part of a node
    DNode* next;      // the next part of a node
};

#endif /* DNODE_H */


