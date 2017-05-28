/*
 * HashTable.h
 *
 *  Created on: May 19, 2017
 *      Author: haytham
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

const int MAX_TABLE = 10;

template < class tableKeyType, class tableDataType >
class HashTable{
public:
	HashTable();
	void insert(const tableKeyType & key,const tableDataType & data);
	bool lookup(const tableKeyType & key,tableDataType & data);
	bool deleteKey(const tableKeyType & key);
	void dump();

private:
	// PRIVATE VARIABLES
	struct Slot;
	typedef Slot * Link;
	struct Slot {
		tableKeyType key;
		tableDataType data;
		Link next;
	};
	Link Table[MAX_TABLE];

	// PRIVATE FUNCTIONS
	int hash(const tableKeyType & key);
	bool search(Link & slotPointer, const tableKeyType & target);
};

template < class tableKeyType, class tableDataType >
int HashTable <tableKeyType,tableDataType>::hash(const tableKeyType & key){
	return key % MAX_TABLE;
}

template < class tableKeyType, class tableDataType >
bool HashTable < tableKeyType, tableDataType >::search(Link & slotPointer, const tableKeyType &target){
	// search for target, starting at slotPointer
	for ( ; slotPointer; slotPointer = slotPointer -> next)
		if (slotPointer->key == target)
			return true;
	return false;
}

template < class tableKeyType, class tableDataType >
HashTable < tableKeyType, tableDataType >::HashTable(){
	int i;
	for (i = 0; i < MAX_TABLE; i++)
		Table[i] = 0;
}

template < class tableKeyType, class tableDataType >
void HashTable < tableKeyType, tableDataType >::insert(const tableKeyType & key, const tableDataType& data){
	int pos(hash(key)); // find a position to insert the item
	Link sp(Table[pos]);
	if (!search(sp, key)) { // key was not in the table
		// insert new item at beginning of list
		Link insertedSlot = new Slot;
		insertedSlot->key = key;
		insertedSlot->data = data;
		insertedSlot->next = Table[pos];
		Table[pos] = insertedSlot;
	}
	else // found old record -- update the data
		sp->data = data;
}

template < class tableKeyType, class tableDataType >
bool HashTable < tableKeyType, tableDataType >::lookup(const tableKeyType & key, tableDataType &data)
{
	int pos(hash(key));
	Link sp(Table[pos]);
	if (search(sp, key)){
		data = sp->data;
		return true;
	}
	else
		return false;
}

template < class tableKeyType, class tableDataType >
bool HashTable < tableKeyType, tableDataType >::deleteKey(const tableKeyType & key){
	// need to find pointer to item preceding the slot to delete
	int pos(hash(key));
	Link p;
	if (Table[pos] == 0)
		return false; // there's no list for this slot
	if (Table[pos]->key == key) { // special case, first item in chain
		Link deleteSlot(Table[pos]);
		Table[pos] = Table[pos]->next;
		delete deleteSlot;
		return true;
	}
	else{
		for (p = Table[pos]; p->next; p = p->next)
			if (p->next->key == key) {
				Link deleteSlot = p->next;
				p->next = p->next->next;
				delete deleteSlot;
				return true;
			}
		return false;
	}
}

template < class tableKeyType, class tableDataType >
void HashTable < tableKeyType, tableDataType >::dump(){
	int i;
	for (i = 0; i < MAX_TABLE; i++) {
		std::cout << "At index : " << i << '\t';
		Link p;
		for (p = Table[i]; p; p = p->next){
			std::cout << "Record : "<< p->key << '\t';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

#endif /* HASHTABLE_H_ */
