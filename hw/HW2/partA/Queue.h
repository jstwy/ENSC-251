/**
 * @file Queue.h
 * @author Diane Wolf
 * @Date   10/18/2017
 * @version 1.0
 * @section DESCRIPTION
 * [HW2] [Part A] [interface]
 * This source file is the interface for the class Queue.
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
#ifndef QUEUE_H
#define QUEUE_H

namespace queuespace
{
// struct for storing ticket (node) data
    struct QueueNode
    {
        int position;       // position of customer in queue
        long startTime;     // time stamp of ticket generation
        QueueNode *link;    // pointer to next ticket
    };
    typedef QueueNode* QueueNodePtr;

    class Queue
    {
    public:
        Queue();
        //[precondition] none
        //[postcondition] a Queue object is created
        Queue(const Queue& aQueue);
        //[precondition] a Queue object already exists
        //[postcondition] a copy of the object is created
        ~Queue();
        //[precondition] a Queue object exists
        //[postcondition] the Queue object is deleted
        void add(char item, long ticketTime);
        //[precondition] a Queue object exists and ticket data is available
        //[postcondition] a node is created to store ticket data
        int getFrontPos();
        //[precondition] a node not pointing to NULL exists
        //[postcondition] the position data is returned
        long getFrontStamp();
        //[precondition] a node not pointing to NULL exists
        //[postcondition] the time stamp from ticket creation is returned
        void remove();
        // [precondition] a Queue object exists and it is not pointing at NULL
        // [postcondiiton] the topmost node is deleted
        bool empty() const;
        //[precondition] a Queue object exists
        //[postcondition] returns whether Queue is empty or not
    private:
        QueueNodePtr front; // points to the head of a linked list
                            // items removed at head
        QueueNodePtr back; // points to node at other end of linked list
                            // items added at back
    };
}

#endif