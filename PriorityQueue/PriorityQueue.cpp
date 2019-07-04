#include "PriorityQueue.h"
#include <cassert>

PriorityQueue::PriorityQueue() { }

void PriorityQueue::Enqueue(ItemType c)
{
	int ins=0;
	while (ins<vectQueue.size()) {
		if (vectQueue.at(ins) < c) {
			break;
		}
		ins++;
	}
	if (ins == vectQueue.size()) {
		vectQueue.push_back(c);
	}
	else { vectQueue.insert(vectQueue.begin()+ins, c); }
}

ItemType PriorityQueue::Pop(){
	assert(vectQueue.size() >0);
	ItemType retVal = vectQueue.at(0);
	vectQueue.erase(vectQueue.begin());
	return retVal;
}

ItemType PriorityQueue::Peek()
{
	assert(vectQueue.size() >0);
	return vectQueue.at(0);
}

bool PriorityQueue::IsEmpty()
{
	if (vectQueue.size() == 0) { return true; }
	else{return false;}
}

int PriorityQueue::GetLength()
{
	return vectQueue.size();
}
