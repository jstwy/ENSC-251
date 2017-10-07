/**
 * @file lab4.cpp
 * @author Diane Wolf
 * @Date   10/6/2017
 * @version 1.0
 * @section DESCRIPTION
 * This program was intended to demonstrate creating a linked list using a 
 * class as the data type for the nodes. Implementation was unsuccessful, so
 * much of the original provided code remains intact. Additions to the code 
 * are functions for manipulating the linked list.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Diane Wolf ____      _____October 6, 2017______________
//
// ____ dawolf | 301305135 ______
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    Node *link;
};

// assign NodePtr to signify a pointer of type Node
typedef Node* NodePtr;

void printList(NodePtr listHead);
// Precondition: The linked list is not empty.
// Postcondition: The name stored in each node is printed to the consold in
//                the order that they appear in the list.
void insertNode(NodePtr nodeToInsertAfter, string nameToInsert);
// Precondition: The linked list is not empty.
// Postcondition: A new node containing a name is inserted after an existing
//                node.
NodePtr getNodePointer(NodePtr listHead, string nameToFind);
// Precondition: The linked list in not empty and the name exists in the list.
// Postcondition: The pointer pointing to the specified name is returned. If
//                the name is found to not exist, function returns NULL.
NodePtr getPrevioutNodePointer(NodePtr listHead, string nameToFind);
// Precondition: The node is not the head node and the name exists.
// Postcondition: The pointer to the node preceding the one in question is
//                returned.
void deleteNode(NodePtr listHead, string nameToDelete);
// Precondition: The name exists in the list.
// Postcondition: The node containing the specified name is deleted.
void obliterateNodes(NodePtr listHead);
// Precondition: The list is not empty.
// Postcondition: All nodes in the list are deleted.

int main()
{
    // pointers and variables   
    NodePtr listPtr;        // pointer to head node
    NodePtr tempPtr;        // temporary pointer for node manipulation
    NodePtr jamesPtr;       // pointer to a specific node
    string name1;           // name in first node
    name1 = "Emily";
    string name2;           // name in second node
    name2 = "James";
    string name3;           // name in third node
    name3 = "Joules";
    string insertedName;    // name to be inserted between nodes
    insertedName = "Joshua";

    // setting nodes
    /*
     * This section of code was derived in large part from the Lab 4
     * specifications document.
     * 
     * Copyright H. H. Tsang, Fall 2017. All rights reserved.
     *
     */
    listPtr = new Node;         // new node
    listPtr->name = name1;      // first node named Emily
    tempPtr = new Node;         // second node created
    tempPtr->name = name2;      // second node named James
    listPtr->link = tempPtr;    // first node points to second node
    tempPtr->link = new Node;   // second node points to new node
    tempPtr = tempPtr->link;    // tempPtr points to next node 
    tempPtr->name = name3;      // third node named Joules
    tempPtr->link = NULL;       // third node points to null

    // part (a): print out the list in order
	cout << ".........................................." << endl;
	cout << "(a) All names in the list in order:" << endl;
    printList(listPtr);
	cout << ".........................................." << endl;

    // part (b): insert a new node between nodes; print the updated list
	cout << "(b) Insertion of \"Joshua\" after \"James\":" << endl;
    jamesPtr = getNodePointer(listPtr, name2);
	insertNode(jamesPtr, insertedName);
	printList(listPtr);
	cout << ".........................................." << endl;

    // part (c): delete a node and print the resulting list
	cout << "(c) Deletion of \"Joules\":" << endl;
	deleteNode(listPtr, name3);
	printList(listPtr);
	cout << ".........................................." << endl;

    // part (d): delete all of the nodes in the list
	cout << "(d) Deleting all nodes..." << endl;
	obliterateNodes(listPtr);
	cout << "All nodes deleted." << endl;
	cout << ".........................................." << endl;

    return 0;
}

/**
 * @brief This function prints the contents of a linked list in order.
 *
 * @param listHead is the head node of the list that is to be printed
 * @return void; prints list to console
 *
 */
void printList(NodePtr listHead)
{
    // pointer
    NodePtr currentNode; // create new pointer to run through list
    currentNode = listHead; // have new poiter point to head node

    // print the name inside the node if the pointer is not pointing to NULL
	for (NodePtr i = currentNode; i != NULL; i = i->link)
    {
        cout << i->name << endl; // print name in node
    }
}

/**
 * @brief This function inserts a node inside a linked list.
 *
 * @param nodeToInsertAfter is the node after which a new node will be added
 * @param nameToInsert is the name that will be stored in the new node
 * @return void; the new node is inserted into the linked list
 *
 */
void insertNode(NodePtr nodeToInsertAfter, string nameToInsert)
{
	// pointer
	NodePtr tempPtr; // create a new node to store the new name
	tempPtr = new Node;

	// put the name in new node
	tempPtr->name = nameToInsert;

	// point the new node at the node it will precede
	tempPtr->link = nodeToInsertAfter->link;

	// point the preceding node to the new node
	nodeToInsertAfter->link = tempPtr;
}

/**
 * @brief This function finds the node of a name stored in a linked list.
 *
 * @param listHead is the head node of the list that is to be printed
 * @param nameToFind is the name that the function is looking for
 * @return currentNode; returns pointer to node containing name or NULL
 *
 */
NodePtr getNodePointer(NodePtr listHead, string nameToFind)
{
    // pointer
    NodePtr currentNode; // create new pointer to run through each list node
    currentNode = listHead; // have a new poiter point to head node
    
	// search for name while not at end of linked list
    while (currentNode->name != nameToFind && currentNode->link != NULL)
    {
        currentNode = currentNode->link; // point to the next node
    }
    if (currentNode->name == nameToFind)
    {
		return currentNode; // return the pointer of node
    }
    else
    {
        return NULL;
    }
}

/**
 * @brief This function finds the preceding node of a node in a linked list.
 *
 * @param listHead is the head node of the list that is to be printed
 * @param nameToFind is the name the function will find the previous node of
 * @return currentNode; returns pointer to node containing name
 *
 */
NodePtr getPrevioutNodePointer(NodePtr listHead, string nameToFind)
{
    // pointers and variables
    NodePtr currentNode; // create new pointer to run through list
    currentNode = listHead; // have new poiter point to head node
	NodePtr precedingNode; // pointer to find preceding node
	precedingNode = listHead; // point pointer to start of list
	int position; // tracks which node from head the target node is
	position = 0;
    
	// search for name while not at end of linked list, track position
    while (currentNode->name != nameToFind && currentNode->link != NULL)
    {
        currentNode = currentNode->link; // move to next node
		position++;
    }

	// search for node preceding target name node; return pointer
	for (int i = 0; i < (position - 1); i++)
	{
		precedingNode = precedingNode->link;
	}

	return precedingNode;
}

/**
 * @brief This function deletes a node in a linked list.
 *
 * @param listHead is the head node of the list containing the node
 * @param nameToDelete is the name of the node that the function will delete
 * @return void; node is deleted
 *
 */
void deleteNode(NodePtr listHead, string nameToDelete)
{
	// pointers
	NodePtr precedingNode; // node preceding node to be deleted
	precedingNode = getPrevioutNodePointer(listHead, nameToDelete);
	NodePtr nodeToDelete;
	nodeToDelete = getNodePointer(listHead, nameToDelete);

	// point preceding pointer to succeeding node
	precedingNode->link = nodeToDelete->link;

	// delete the node
	delete nodeToDelete;
}

/**
 * @brief This function deletes all nodes in a linked list.
 *
 * @param listHead is the head node of the list that is to be cleared of nodes
 * @return void; the nodes are deleted
 *
 */
void obliterateNodes(NodePtr listHead)
{
	// pointers
	NodePtr currentNode;
	currentNode = listHead;
	NodePtr nodeToDelete;

	// delete each node until NULL is reached
	while (currentNode->link != NULL)
	{
		nodeToDelete = currentNode; // set current node as node to delete
		currentNode = currentNode->link; // point current node to next node
		delete nodeToDelete; // delete what used to be the current node
	}
}