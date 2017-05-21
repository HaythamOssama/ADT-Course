//============================================================================
// Name        : LinkedListBasedQueue.cpp
// Author      : Haytham Osama
// Version     :
// Copyright   : Linked List Based Queue
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "LinkedListBasedQueue.h"
int main() {
	LinkedListBasedQueue<int> queue;

	if(queue.isEmpty()){
		cout << "Queue is Empty\n";
	}

	cout << "Enqueue function\n";
	for (int var = 0; var < 20; ++var) {
		if(! queue.enqueue(var)){
			cout << "Error at enqueue\n";
		}
	}

	if(!queue.isEmpty()){
		cout << "Queue isn't Empty\n";
	}
	int item;
	while(queue.dequeue(item)){
		cout << "\tDequeue : " << item << endl;
	}
	return 0;
}
