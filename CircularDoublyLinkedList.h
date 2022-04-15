/******************************************************************************* 
 File:   CircularDoublyLinkedList.h
 Author: Joya Gedeon.
 
 ************************ CircularDoublyLinkedList.h ***************************
 
 This header file defines the data type CircularDoublyLinkedList.
 Operations are:
    Constructors: 
                CircularDoublyLinkedList:  no-arg constructor declaring
                                           an object of type 
                                           CircularDoublyLinkedList.    
                CircularDoublyLinkedList:  copy constructor copying a  
                                           CircularDoublyLinkedList object's
                                           data members.\
    Destructor: ~CircularDoublyLinkedList: deletes a list and its nodes.
    Methods:    clear: deletes a list's nodes without deleting list itself.
                isEmpty: checks if list is empty.
                size: returns the list's size.
                searchFirstOccurence: returns the occurrence of a certain data.
                cutN: returns NodePtr cut off.
                display: displays menu.
    Inserts Methods: 
                insertAtBeginnig: inserts a node at the beginning of list.
                insertAtEnd: inserts a node at the beginning of list.
                insertAtPos: inserts a node at a certain position in the list.
                insertMBeforeN: inserts a node at before another in the list
    Delete Methods:
                deleteAtBeginnig: deletes node at the beginning of list.
                deleteAtEnd: deletes node at the end of list.
                deleteAtPos: deletes a node at a certain position in the list.
                deleteN: deletes a specific node in list.
  
  Created on October 30, 2021, 11:55 AM
*******************************************************************************/
#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H

#include <iostream>
#include "DNode.h"

using namespace std;

// Declaring NodePtr a new data type as a pointer to a DNode.
typedef DNode* NodePtr;

class CircularDoublyLinkedList{
public:
/******** Function Members ********/
    
    /**/ /**/ /* Class Constructor */ /**/ /**/
    /*************************Class no-arg constructor**************************
    Construct a List object.

    Precondition:   None.          
    Post-Condition: An empty List object is constructed; 
                    mySize = 0.
                    data = n (ElementTYpe parameter data);
                    next = NULL;     (as a default value)
                    previous = NULL; (as a default value)
    ***************************************************************************/
    CircularDoublyLinkedList();
    
    /**************************Class copy constructor***************************
    Construct a copy to a CircularDoublyLinkedList object.

    Precondition:   None.          
    Post-Condition: A new CircularDoublyLinkedList object is declared.
    mySize, myFirst and the list's nodes are copied to the new object.                    
    ***************************************************************************/
    CircularDoublyLinkedList(const CircularDoublyLinkedList&);
    
    /**/ /**/ /* Class Methods */ /**/ /**/
    /*****************************Class destructor******************************
    Deletes all nodes and the list included.

    Precondition:   None.          
    Post-Condition: myFirst is NULL and the list is deleted.               
    ***************************************************************************/
    ~CircularDoublyLinkedList();

    /***************************Class clear method******************************
    Deletes the list's node without deleting the list.

    Precondition:   None.          
    Post-Condition: 
    ***************************************************************************/
    void clear ();
    
    /***************************Class Empty method******************************
    Checks if list is empty.

    Precondition:   None.          
    Post-Condition: Returns true if list is empty, false if it isn't.
    ***************************************************************************/
    bool isEmpty() const;
    
    /***************************Class size getter*******************************
    Gets the list's size.

    Precondition:   None.          
    Post-Condition: Returns mySize.
    ***************************************************************************/
    int size() const;
    
    /**************************Class first occurrence search********************
    Gets the first occurrence of a specific data.

    Precondition:   List should not be empty.       
    Post-Condition: Gets the first occurrence of a specific data.
                    Pointer returned either as NULL(data not found) or as 
                    itself (containing the wanted data).
    ***************************************************************************/
    NodePtr searchFirstOccurence(ElementType);
    
    /***********************Class insert at beginning method********************
    Gets the first occurrence of a specific data.

    Precondition:   None.      
    Post-Condition: ElementType value has been inserted into the beginning of 
                    the list.
    ***************************************************************************/
    void insertAtBeginning(ElementType);
    
    /*************************Class insert at end method************************
    Insert a value into the list at the beginning of the list.

    Precondition:   None.         
    Post-Condition: ElementType value has been inserted into the end of 
                    the list.
    ***************************************************************************/
    void insertAtEnd(ElementType);
    
    /*********************Class insert at a position method*********************
    Insert a value into the list at the given position of the list.

    Precondition:   Position should be between 0 and mySize. 
                    List should not be empty.         
    Post-Condition: Data has been inserted at required position in the list.
    ***************************************************************************/
    void insertAtPos(ElementType, int);
    
    /****************Class insert a node before another method******************
    Insert a value into the list before a certain node.

    Precondition:   Position should be between 0 and mySize. 
                    List should not be empty.     
    Post-Condition: Adds new node to list if selected node exist, else list is 
                    not altered.
    ***************************************************************************/
    bool insertMBeforeN(ElementType, ElementType);
    
    /**********************Class delete at beginning method*********************
    Remove a value from the list at the beginning.

    Precondition:   List should not be empty.     
    Post-Condition: Data has been deleted at the beginning of the list.
    ***************************************************************************/
    void deleteAtBeginning();
    
    /**********************Class delete at end method**********************
    Remove a value from the list at the end.

    Precondition:   List should not be empty.     
    Post-Condition: Data has been deleted at the end of the list.
    ***************************************************************************/
    void deleteAtEnd();
    
    /**********************Class delete at position method**********************
    Remove a value from the list at a certain position.

    Precondition:   Position should be between 0 and mySize.
                    List should not be empty.     
    Post-Condition: Data has been deleted at the selected position.
    ***************************************************************************/
    bool deleteAtPos(int pos);
    
    /*********************Class delete a specific node method*******************
    Remove a specific node from the list.

    Precondition:   List should not be empty.     
    Post-Condition: Node, if exists, is removed, if not doesn't alter the list.
    ***************************************************************************/
    bool deleteN(ElementType);
    
    /**************************Class cut node method****************************
    Remove a specific node from the list.

    Precondition:   List should not be empty.     
    Post-Condition: Node, if exists, is removed; if not, list isn't altered.
                    Pointer returned as NULL or as itself.
    ***************************************************************************/
    NodePtr cutN(ElementType);
    
    /**************************Class display method*****************************
    Displays the list.

    Precondition:   The ostream is open.   
    Post-Condition: The list represented by this List object has been inserted 
                    into output.
    ***************************************************************************/
    ostream& display (ostream&) const;
    
private:
/******** Data Members ********/
    DNode* myFirst; // The pointer of the list.
    int mySize;     // The current size of the list.
};

/******** Prototype of output operator ********/
ostream& operator << (ostream&, const CircularDoublyLinkedList&);

#endif /* CIRCULARDOUBLYLINKEDLIST_H */

