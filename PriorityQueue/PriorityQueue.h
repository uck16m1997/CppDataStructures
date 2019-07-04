#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Call.h"
#include <vector>
using namespace std;

typedef Call ItemType;

class PriorityQueue
{
public:
	PriorityQueue();//constructor assigns data members to initial values
	void Enqueue(ItemType c);// adds the element to its proper position in the queue
	ItemType Pop();// removes the first element in the queue and returns it
	ItemType Peek();// returns the first element in the queue
	bool IsEmpty();// returns true if queue is empty else returns false
	int GetLength();// returns size of the vector


private:
	vector<Call> vectQueue;
};
#endif 