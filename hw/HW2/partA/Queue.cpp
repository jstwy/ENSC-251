/**
 * @file Queue.cpp
 * @author Diane Wolf
 * @Date   10/18/2017
 * @version 1.0
 * @section DESCRIPTION
 * [HW2] [Part A] [implementation]
 * This source file is the implementation for the class Queue.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
// Acknowledgments:
    /*
     * The basis of this program is derived from the class textbook,
     * "Problem Solving with C++, 9th Edition".
     * 
     * Copyright 2015 Pearson Education Inc./Walter Savitch.
     * All rights reserved.
     *
     */
//
// _____ Diane Wolf ____      _____October 18, 2017______________
//
// ____ dawolf | 301305135 ______
#include "Queue.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>
using namespace std;

namespace queuespace
{
/**
 * @brief This function is the default class constructor.
 *
 * @param nothing
 * @return nothing, prints program boot/startup to console
 *
 */
    Queue::Queue(): front(NULL), back(NULL)
    {}
 /**
 * @brief This function is the copy constructor.
 *
 * @param nothing
 * @return nothing, creates a new object based on the parameter object
 *
 */
    Queue::Queue(const Queue& aQueue)
    {
        if (aQueue.empty())
        {
            front = back = NULL;
        }
        else
        {
            QueueNodePtr temp_ptr_old = aQueue.front;
            // tempt_ptr_old moves through nodes, F to B of aQueue
            QueueNodePtr temp_ptr_new; // to create new nodes
            
            back = new QueueNode;
            back->position = temp_ptr_old->position;
            back->link = NULL;
            front = back;
            // 1st node created, filled with new pos; new added after this
            
            temp_ptr_old = temp_ptr_old->link;
            // now points to second node or NULL if no second node
            
            while (temp_ptr_old != NULL)
            {
                temp_ptr_new = new QueueNode;
                temp_ptr_new->position = temp_ptr_old->position;
                temp_ptr_new->startTime = temp_ptr_old->startTime;
                temp_ptr_new->link = NULL;
                back->link = temp_ptr_new;
                back = temp_ptr_new;
                temp_ptr_old = temp_ptr_old->link;
            }
        }
    }
 /**
 * @brief This function is class destructor.
 *
 * @param nothing
 * @return nothing, frees dynamic memory to the free store
 *
 */
    Queue::~Queue()
    {
        char next;
        while (! empty())
        {
            remove(); // remove calls delete
        }
    }
 /**
 * @brief This function indicates the status of the queue.
 *
 * @param nothing
 * @return bool, indicates whether queue (linked list) is empty or not
 *
 */
    bool Queue::empty() const
    {
        return (back == NULL); // front == NULL also valid
    }
 /**
 * @brief This function adds a new ticket (node) with queue position and
 *        time stamp.
 *
 * @param queue position and time stamp
 * @return nothing, creates node and stores data
 *
 */
    void Queue::add(char item, long ticketTime)
    {
        int intItem;
        intItem = item;
        
        if (empty())
        {
            front = new QueueNode;
            front->position = intItem;
            front->startTime = ticketTime;
            front->link = NULL;
            back = front;
        }
        else
        {
            QueueNodePtr temp_ptr;
            temp_ptr = new QueueNode;
            temp_ptr->position = intItem;
            temp_ptr->startTime = ticketTime;
            temp_ptr->link = NULL;
            back->link = temp_ptr;
            back = temp_ptr;
        }
    }
 /**
 * @brief This function returns the queue position of a customer.
 *
 * @param nothing
 * @return int of position in queue stored in ticket (node)
 *
 */
    int Queue::getFrontPos()
    {
        if (!empty())
		{
			return front->position;
		}
    }
 /**
 * @brief This function returns the time stamp of a ticket (node).
 *
 * @param nothing
 * @return long of time stamp stored in node
 *
 */
    long Queue::getFrontStamp()
    {
        return front->startTime;
    }
 /**
 * @brief This function removes nodes from the queue.
 *
 * @param nothing
 * @return nothing, deletes objects
 *
 */
    void Queue::remove()
    {
    // error message for removing NULL
        if (empty())
        {
            cout << "Error: Removing an item from an empty queue.\n";
        }
    // delete nodes until NULL is reached
        else
        {
            QueueNodePtr discard;
            discard = front;
            front = front->link;
        
            if (front == NULL)//last node removed
            {
                back = NULL;
            }

            delete discard;
        }
    }
}