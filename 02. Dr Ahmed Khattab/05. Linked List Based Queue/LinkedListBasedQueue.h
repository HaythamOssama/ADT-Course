/*
 * LinkedBaseQueued.h
 *
 *  Created on: May 9, 2017
 *      Author: haytham
 */

#ifndef LINKEDLISTBASEDQUEUE_H_
#define LINKEDLISTBASEDQUEUE_H_

template <class queueElementType>
class LinkedListBasedQueue{
public:
	LinkedListBasedQueue();
	bool enqueue(const queueElementType &item);
	bool dequeue(queueElementType &item);
	bool frontItem(queueElementType &item);
	bool isEmpty();
	~LinkedListBasedQueue();
private:
	struct Node;
	typedef Node * Link;
	struct Node {
		queueElementType data;
		Link next;
	};
	Link front;
	Link rear;
};

template <class queueElementType>
LinkedListBasedQueue<queueElementType>::LinkedListBasedQueue(){
	front = 0;
	rear  = 0;
}

template <class queueElementType>
bool LinkedListBasedQueue<queueElementType>::enqueue(const queueElementType &item){

	Link addedNode = new Node;
	if(!addedNode){
		return false; // Heap is full
	}
	else{
		addedNode -> data = item;
		addedNode -> next = 0;
		if (!front) {
			front = addedNode;
		}
		else {
			rear->next = addedNode;
		}
		rear = addedNode;
		return true;
	}
}

template <class queueElementType>
bool LinkedListBasedQueue<queueElementType>::dequeue(queueElementType &item){
	if(!front){
		return false; // NO items in queue;
	}
	else{
		Link ptr = front;
		item = front -> data;
		front = front ->next;
		delete ptr;
		if(!front){
			rear = 0;
		}
		return true;
	}

}
template <class queueElementType>
bool LinkedListBasedQueue<queueElementType>::frontItem(queueElementType &item){
	if(!front){
		return false; // NO items in queue;
	}
	else{
		item = front ->data;
		return true;
	}
}

template <class queueElementType>
bool LinkedListBasedQueue<queueElementType>::isEmpty(){
	return bool(front == 0);
}

template <class queueElementType>
LinkedListBasedQueue<queueElementType>::~LinkedListBasedQueue(){
	queueElementType dummy;
	while(dequeue(dummy));
}

#endif
