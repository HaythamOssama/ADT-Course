//============================================================================
// Name        : Search.cpp
// Author      : Haytham Osama
// Version     :
// Copyright   : Search Algorithms
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <ctime>// include this header


int linearSearch(int a[], int n, int target);
int binarySearch(int a[], int n, int target);

int main() {
	int a[18] ={10,14,15,20,23,25,26,27,31,32,34,37,41,42,44,45,46,49};
	int target = 45;
	cout << "Linear Search:\n";

	int start_s=clock();
	cout << "\tFound : "<< target << " at : " <<  linearSearch(a,18,target) << endl;
	int stop_s=clock();
	cout << "\tTime taken: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

	cout << "\nBinary Search:\n";
	start_s=clock();
	cout << "\tFound : "<< target << " at : " << binarySearch(a,18,target) << endl;
	stop_s=clock();
	cout << "\tTime taken: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	/*
	 * Calculating the execution time isn't in our course
	 * It's for illustration only
	 */
	return 0;
}

int linearSearch(int a[], int n, int target){
	int i;
	for (i = 0; i < n; i++)
		if (a[i] == target) // key comparison
			return i;
	return -1; // use -1 to indicate failure
}

int binarySearch(int a[], int n, int target){
	// Precondition: array a is sorted in ascending order from a[0] to a[n-1]
	int first=0;
	int last = n - 1;
	int mid;
	while (first <= last) {
		mid = (first + last)/2;
		if (target == a[mid])
			return mid;
		else if (target < a[mid])
			last = mid -1;
		else // must be that target > a[mid]
			first = mid +1;
	}
	return -1; // use -1 to indicate item not found
}
