/******************************************************************************* 
 File:   main.cpp
 Author: Joya Gedeon.
 
 ********************************* main.cpp ************************************
 
 Program to test CircularDoublyLinkedList class.
 
 Created on October 30, 2021, 11:50 PM
*******************************************************************************/

#include <cstdlib>
#include "CircularDoublyLinkedList.h"
#include "DNode.h"
#include <iostream>
using namespace std;

/*
 Method Name: displayMenu.
 Functionality: Display the Menu of possible functionalities to the user.
                Takes an input integer and returns it.
 */
 

int displayMenu(){
    // user's input choice 
    int userChoice = 0;
    // Display of Menu.
    cout << "|**************************************************|" ;
    cout << "\n| \t\t\tMenu"
         << "\n|**************************************************|"
         << "\n| 1  -> Test if the list is empty."
         << "\n| 2  -> Get the number of nodes in the list."
         << "\n| 3  -> Insert a value at the beginning of the list."
         << "\n| 4  -> Insert a value at the end of the list."
         << "\n| 5  -> Insert a value at a certain position."
         << "\n| 6  -> Insert a value before another value."
         << "\n| 7  -> Delete the node with a certain value."
         << "\n| 8  -> Delete the node at a certain position."
         << "\n| 9  -> Delete node at the beginning of the list."
         << "\n| 10 -> Delete node at the end of the list."
         << "\n| 11 -> Display List."
         << "\n| 12 -> Exit.\n";
    cout << "|**************************************************|\n" ;   
    // Assign userChoice to a user's value.
    cin  >> userChoice;
    return userChoice;
}

int main() {

    /************************ VARIABLE DECLARATION ****************************/
                          /* By Alphabetic Order */
    // Declaration of the 3 lists origin, even, odd.
      CircularDoublyLinkedList origin, even, odd;
    // insertChoice: User's choice of node's data for insertion.
    // positionNode: User's choice of position for node's data insertion.
      ElementType insertChoice, positionNode;
    // userChoice: User's choice from the menu.
    // nodePosition: User's choice of position insertion.
      int userChoice, nodePosition;
    // tempPtr: Pointer to list origin.
      NodePtr tempPtr;
    /**************************************************************************/
        
       
    /********************** Origin List Manipulation **************************/   
    cout << "|**************************************************|\n";
    cout << "| Please choose a number to execute the operation  |\n"; 
    cout << "|**************************************************|\n\n";
    // userChoice assigned to value.
    userChoice = displayMenu();
    cout << endl;
    
    // Execution according to user choice.
    do {
        // Input integer is out of range
        if (userChoice > 12 || userChoice < 1){
            cout << "Number out of range.(Must be between 0 and 12).\n"
                 << endl;
            cout << "|**************************************************|\n" ;
            cout << "| Please choose a number to execute the operation  |\n" ; 
            cout << "|**************************************************|\n\n";
            userChoice = displayMenu();
            cout << endl;
        }
        // Input integer is between 1 and 12 inclusive
        else{ 
            if (userChoice <= 12 && userChoice >= 1){ 
                // In-range case's possible functionality.
                switch(userChoice){
                    // Case 1: Checks if list empty or not.
                    case 1:
                        if(origin.isEmpty())
                            cout << "Empty List.\n";
                        else
                            cout <<"Non-Empty List.\n";
                        break;

                    // Case 2: Returns the number of nodes in the List.
                    case 2: 
                        cout << "List contains " << origin.size() << " nodes."
                             << endl;
                        break;

                    // Case 3: Inserts data at the beginning of the list.
                    case 3: 
                        cout << "Enter a data for the node to be inserted:" 
                             << endl;
                        cin  >> insertChoice;
                        origin.insertAtBeginning(insertChoice);
                        cout << origin;
                        cout << endl;
                        break;

                    // Case 4: Inserts data at the end of the list.
                    case 4:
                        cout << "Enter a data for the node to be inserted:" 
                             << endl;
                        cin  >> insertChoice;
                        origin.insertAtEnd(insertChoice);
                        cout << origin;
                        cout << endl;
                        break;

                    // Case 5: Inserts data at a specific position of the list.    
                    case 5: 
                        cout << "Enter a data for the node to be inserted:"
                             << endl;
                        cin  >> insertChoice;
                        cout << "Enter the position desired:" << endl;
                        cin  >> nodePosition;
                        origin.insertAtPos(insertChoice, nodePosition);
                        cout << origin;
                        cout << endl;
                        break;

                    // Case 6: Insert a value before another value.
                    case 6: 
                        cout << "Enter node value to be inserted";
                        cin  >> insertChoice;
                        cout << "Then insert the node you wish to add before it."
                             << endl;
                        cin  >> positionNode;
                        origin.insertMBeforeN(insertChoice, positionNode);
                        cout << origin;
                        cout << endl;
                        break;

                    // Case 7: Delete the node with a certain value.
                    case 7:
                        cout << "Enter the value of the node to wish to delete." 
                             << endl;
                        cin  >> insertChoice;
                        origin.deleteN(insertChoice);
                        cout << origin;
                        cout << endl;
                        break;

                    // Case 8: Delete the node at a certain position.
                    case 8: 
                        cout << "Enter the position of the node to be deleted." 
                             << endl;
                        cin  >> nodePosition;
                        origin.deleteAtPos(nodePosition);
                        cout << origin;
                        cout << endl;
                        break;

                    // Case 9: Delete node at the beginning of the list. 
                    case 9:
                        origin.deleteAtBeginning();
                        cout << "The first node has been deleted." << endl;
                        cout << origin;
                        cout << endl;
                        break;

                    // Case 10: Delete node at the end of the list.   
                    case 10:
                        origin.deleteAtEnd();
                        cout << "The last node has been deleted." << endl;
                        cout << origin;
                        cout << endl;
                        break;

                    // Case 11: Display List.
                    case 11:
                        cout << "The list contains: " << endl;
                        cout << origin;
                        cout << endl;
                        break; 

                    // Case 12: Exit List.
                    case 12: 
                        cout << "case 12";
                        break;

                    // Default case: Number chosen NOT between 0 and 12.
                    default:
                        cout << "Number out of range.(Between 0 and 12).\n"
                             << endl;
                        break;        
                 }

                // Menu Display 
                cout << "|*************************************************|\n";
                cout << "| Please choose a number to execute the operation |\n"; 
                cout << "|*************************************************|\n"
                     << "\n";
                userChoice = displayMenu();
                cout << endl;
            }
        }
        // Condition to stay in loop
    } while(userChoice != 12);
    /**************************************************************************/
 
    
    /******************* Origin/Odd/Even List Manipulation ********************/  
    
    // >>>> This is not an effective way to do it.
    // >>>> Values most likely NOT inputted by user. 
    origin.insertAtEnd(100000);
    origin.insertAtBeginning(700);
    origin.insertAtBeginning(600);
     
    tempPtr = origin.searchFirstOccurence(100000);
    //cout << origin;
    NodePtr pointer;
    
    tempPtr = tempPtr->getNext();
    
    // since we added two values 
    while((origin.size() - 2 ) != 0 && tempPtr != NULL){
        pointer = origin.cutN(tempPtr->getPrevious()->getData());
        
        if(pointer->getData() % 2 == 0){
            even.insertAtBeginning(pointer->getData());
            pointer = pointer->getNext();
        }
        
        // Move odd data to odd list
        else{
            odd.insertAtBeginning(pointer->getData());
            pointer = pointer->getNext();
        }
    }
    // Deleted values added
    while (!origin.isEmpty()) {
        origin.deleteAtEnd();
    }
    even.deleteN(100000);
    
    // FINAL DISPLAY OF ALL LISTS
    cout << "ORIGIN: " << origin; // Display list Origin using output operator.
    cout << "\n" << endl;
    cout << "ODD: " << odd;    // Display list Odd using output operator.
    cout << "\n" << endl;
    cout << "EVEN: "<< even;   // Display list Even using output operator.
    /**************************************************************************/
    
    return 0;
}

