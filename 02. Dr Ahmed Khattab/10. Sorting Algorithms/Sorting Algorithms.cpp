//============================================================================
// Name        : Sorting.cpp
// Author      : Haytham Osama
// Version     :
// Copyright   : Sorting Algorithms
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// Selection Sorting functions
int maxSelect(int a[], int n);
void selectionSort(int a[], int n);

// Bubble Sorting functions
void bubbleSortPhase(int a[], int last);
void bubbleSort(int a[], int n);

// Improved Sorting function
void improvedBubbleSort(int a[], int n);

// Helping functions
void swapElements(int a[], int maxPos, int last);
void printArray(int a[],int size);

int main() {


	int a[20]={43,63,61,100,15,31,21,22,13,67,55,81,16,57,9,97,71,45,26,1};
	selectionSort(a,20);
	printArray(a,20);

	int a2[20]={43,63,61,100,15,31,21,22,13,67,55,81,16,57,9,97,71,45,26,1};
	bubbleSort(a2,20);
	printArray(a2,20);

	int a3[20]={43,63,61,100,15,31,21,22,13,67,55,81,16,57,9,97,71,45,26,1};
	improvedBubbleSort(a3,20);
	printArray(a3,20);
	return 0;
}

int maxSelect(int a[], int n)
{
	int maxPos(0), currentPos(1);
	while (currentPos < n) {
		// Invariant: a[maxPos] >= a[0] ... a[currentPos-1]
		if (a[currentPos] > a[maxPos])
			maxPos = currentPos;
		currentPos++;
	}
	return maxPos;
}
void selectionSort(int a[], int n)
{
	int last(n-1);
	int maxPos;
	while (last > 0) {
		// invariant: a[last+1] ... a[n-1] is sorted &&
		// everything in a[0] ... a[last] <= everything in a[last+1] ... a[n-1]
		maxPos = maxSelect(a, last+1); // last+1 is length from 0 to last
		swapElements(a, maxPos, last);
		last--;
	}
}

void bubbleSortPhase(int a[], int last)
{
	// Precondition: a is an array indexed from a[0] to a[last]
	// Move the largest element between a[0] and a[last] into a[last],
	// by swapping out of order pairs
	int pos;
	for (pos = 0; pos < last; pos++)
		if (a[pos] > a[pos+1]) {
			swapElements(a, pos, pos+1);
		}
	// Postconditions: a[0] ... a[last]
	// contain the same elements,
	// possibly reordered; a[last] >= a[0] ... a[last-1]
}

void bubbleSort(int a[], int n)
{ // Precondition: a is an array indexed from a[0] to a[n-1]
	int i;
	for (i = n - 1; i > 0; i--)
		bubbleSortPhase(a, i);
	// Postcondition: a is sorted
}

void improvedBubbleSort(int a[], int n)
{ // Precondition: a is an array indexed from a[0] to a[n-1]
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = n - 1; i > 0; i--){
			for (int pos = 0; pos < i; pos++)
				if (a[pos] > a[pos+1]){
					swapElements(a,pos, pos+1);
					sorted = false;
				}
		}

	} // Postcondition: a is sorted
}

void swapElements(int a[], int maxPos, int last){
	int temp = a[maxPos];
	a[maxPos] = a[last];
	a[last] = temp;
}
void printArray(int a[],int size){
	cout <<"\nSorted Array:\n";
	for(int i=0 ; i<size ; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
