/**
 * @file partA.cpp
 * @author Diane Wolf
 * @Date   10/18/2017
 * @version 1.0
 * @section DESCRIPTION
 * [HW2] [Part A] [main program]
 * This program simulates customer arrivals at a venue using a class called
 * Queue.
 * [Option 1] adds a customer to the queue
 * [Option 2] serves the customer at the front of the queue, displaying the
 *            estimated wait time for the next customer after 3 customers have
 *            been successfully served
 * [Option 3] deletes all queue nodes and terminates the program
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
#include <ctime>
using namespace std;
using namespace queuespace;

int getNewRecordIndex(int& currentIndexPos);
//[precondition] A new wait time is ready to be added to calculate estimated
//               wait time.
//[postcondition] The latest wait time is added to the stampRecord array. If
//                there are already three entries, they are replaced by new
//                ones in order.

int main()
{
    Queue q;                        // the queue object
    char next;                      // char for storing user input
    int positionIncrementer;        // running total of customers
    positionIncrementer = 0;
    long seconds;                   // time used in time stamp
    seconds = 0;
    long timeDifference;            // time waited before being served
    timeDifference = 0;
    int stampRecord[3] = {0,0,0};   // array of 3 latest wait times
    int avgWaitTime;                // avg of the times in stampRecord
    avgWaitTime = 0;
    int recordIndex;                // index tracker for stampRecord
    recordIndex = 0;
	int customersServed;            // tracker for number of tickets removed
	customersServed = 0;

	cout << "The line is empty." << endl; // queue is empty on startup
    do
    {
    // promt user for command
        cout << "Enter '1' to simulate a customer's arrival, "
             << "'2' to help the customer, "
             << "or '3' to quit." << endl;
    // get user input and process
        cin.get(next);
        while (next != '\n')
        {
        // add new ticket to queue for option 1
            if (next == '1')
            {
            // generate time stamp
                seconds = static_cast<long>(time(NULL));
            // increase running total of customers
                positionIncrementer++;
            // create new ticket (add new node)
                q.add(positionIncrementer,seconds);
                cout << "Customer " << positionIncrementer
                     << " entered the queue at time " << seconds
                     << ".";
            }
        // process and remove ticket for option 2
            else if (next == '2')
            {
            // alert user if queue is empty
				if (q.empty())
				{
					cout << "The line is empty.";
				}
			// process ticket
				else
				{
				// calculate wait time
				    seconds = static_cast<long>(time(NULL));
			        timeDifference = seconds - q.getFrontStamp();
			    // print time and wait time
				    cout << "Customer " << q.getFrontPos()
					     << " is being helped at time " << seconds
						 << ". Wait time=" << timeDifference
					     << " seconds.";
			    // add wait time to stampRecord & add to served tickets total
					stampRecord[getNewRecordIndex(recordIndex)] = 
					                                           timeDifference;
					customersServed++;
                // simply remove ticket if less than 3 total customers served
					if (customersServed < 3)
					{
						q.remove();
					}
				// calculate estimated wait time and remove ticket
					else
					{
						avgWaitTime = (stampRecord[0]
							                + stampRecord[1]
								            + stampRecord[2]) / 3;
						q.remove();
					// print generic wait time message if queue now empty
						if (q.empty())
						{
							cout << "\nThe estimated wait time for the next"
								 << " customer is " << avgWaitTime
								 << " seconds.";
						}
					// print specific message if queue is occupied
						else
						{
							cout << "\nThe estimated wait time for customer "
								 << q.getFrontPos()
								 << " is " << avgWaitTime
								 << " seconds.";
						}
					}
				}
            }
        // clean queue before exiting for option 3
            else if (next == '3')
            {
                while (!q.empty())
                {
                    q.remove();
                }
                return 1;
            }
        // print error message for invalid input (anything other than 1/2/3)
            else
            {
                cout << "Invalid command; please try again.";
                break;
            }
            cin.get(next);
        }
        cout << endl;
    } while (next != '3');

    return 0;
}

 /**
 * @brief This function helps stampRecord retain the latest 3 wait times.
 *
 * @param last occupied index (recordIndex by reference)
 * @return index to store latest wait time
 *
 */
int getNewRecordIndex(int& currentIndexPos)
{
	int temp;                   // temporary int to hold index
	temp = currentIndexPos;
// if stampRecord already hold three values, reset index to first container
    if (currentIndexPos == 2)
    {
		currentIndexPos = 0;
        return temp;
    }
// return index 0 or 1 or 2 for stampRecord
    else
    {
        return currentIndexPos++;
    }
}