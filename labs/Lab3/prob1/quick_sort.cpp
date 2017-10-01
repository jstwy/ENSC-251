/**
 * @file quick_sort.cpp
 * @author Diane Wolf
 * @Date   9/28/2017
 * @version 1.0
 * @section DESCRIPTION
 * This program uses the quick sort algorithm to sort through a list of 
 * numbers. It has been debugged and fixed.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Diane Wolf ____      _____September 28, 2017______________
//
// ____ dawolf | 301305135 ______

/*quick sort algorithm */ 

//Read Quick Sort Algorithm from wikipedia
/*
The code is close but it has some errors so it is not doing 
what it is supposed to do. Read the Quick Sort Algorithm 
and debug the code to print the correct output.

Also write the code for reading the numbers from the file "input.txt" 
provided in the folder "prob2" 
NOTE:- DO NOT hardcode the size of the file . Create a constant variable 
max_length = 200, which will be the maximum size of the file.
//---------------------------------------------------------------
NOTE: DO NOT ADD ANY COUT STATEMENTS IN THE FINAL SUBMISSION 
OF THE CODE. ALSO, DO NOT MODIFY THE SEQUENCE OF THE INPUT, OR 
CHANGE THE INPUT 
//---------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <fstream>		// for reading files
using namespace std; 

void print_array(int array[], int low, int hi) 
{ 
	cout<< "quick sort partition steps: "; 
	for (int j=low; j<=hi;j++) 
		cout <<" "<< array[j]; 
	cout << endl;
}//end of print_array

int partition(int& arr[], int low, int hi)
{
	int pivot = arr[hi];
	int i = low;
	
	for (int j = low; j<hi; j++)
	{
		if (arr[j] <= pivot)
		{
			swap(arr, i, j);
			i++;
		}
	}
	print_array(arr, low, hi);
	swap(arr, i, hi);
	return i;
}
	
void swap(int& arr[], int i, int j)
{
	int temp; // temporary container for swapped value
	temp = 0;
	
	temp = arr[i];
	
	arr[i] = arr[j];
	arr[j] = temp;
	
	return;
}
		
void quick_sort(int& arr[], int low, int high) 
{ 
	int pivot;
	
	if (low < high)
	{
		pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot-1);
		quick_sort(arr, pivot+1, high);
	}
	
	return;
}
	
	int main() 
	{ 
		int const_length; // max values to be read from file
		const_length = 200;
		int size; // for checking size of data
		size = 0;
		int dataArray[const_length];
		
		// read input.txt, store values in the array
		ifstream file;
		file.open("input.txt");
		while (file >> dataArray[size])
		{
			if (size > const_length)
			{
				file.close();
				return 1;
			}
			else
			{
				size++;	
			}
		}
		file.close();
			
		print_array(dataArray, 0, size);
		quick_sort(dataArray, 0, size); 
		print_array(dataArray, 0, size);
		
		return 0;
	}//end of main