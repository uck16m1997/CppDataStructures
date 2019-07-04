#include "CallCenter.h"
#include <iostream>

CallCenter::CallCenter() { 
	numOfAnsCalls = 0; 
	totalTime = -1;
	waitTime = 0;
	waitP1 = 0;
	waitP2 = 0;
	waitP3 = 0;
	numOfP1 = 0;
	numOfP2 = 0;
	numOfP3 = 0;
	openTime = 0;
	curCall.SetPriority(-1);
}

void CallCenter::AcceptCall(Call c){
	pQueue.Enqueue(c);
}

void CallCenter::UpdateCenter(){
	totalTime++;
	if (curCall.GetPriority() == -1 && (!pQueue.IsEmpty())) {
		curCall =pQueue.Pop();
		openTime = totalTime;
		waitTime += totalTime - curCall.GetArrTime();
		if (curCall.GetPriority() == 1) {
			numOfP1++;
			waitP1 += totalTime - curCall.GetArrTime();
		}
		else if (curCall.GetPriority() == 2) {
			numOfP2++;
			waitP2 += totalTime - curCall.GetArrTime();
		}
		else if (curCall.GetPriority() == 3) {
			numOfP3++;
			waitP3 += totalTime - curCall.GetArrTime();
		}
	}
	if (curCall.GetPriority() != -1) {
		int TimeTaken = totalTime - openTime;
		if (TimeTaken == curCall.GetAnsTime()) {
			numOfAnsCalls++;
			curCall.SetPriority(-1);
		}
	}
}
	

bool CallCenter::CenterDone()
{
	if (pQueue.IsEmpty() && curCall.GetPriority() == -1) {
		return true;
	}
	return false;
}

void CallCenter::DisplayResults()
{
	cout << "Total number of calls entered and answered " << numOfAnsCalls << endl;
	cout << "Total time taken to answer the calls " << totalTime << endl;
	cout << "Average wait time for a call to be answered " << waitTime/numOfAnsCalls << endl;
	if (numOfP1 != 0) {
		cout << "Average wait time for a Priority 1 call to be answered " << waitP1 / numOfP1 << endl;
	}
	if (numOfP2 != 0) {
		cout << "Average wait time for a Priority 2 call to be answered " << waitP2 / numOfP2 << endl;
	}
	if (numOfP3 != 0) {
		cout << "Average wait time for a Priority 3 call to be answered " << waitP3 / numOfP3 << endl;
	}
}

void CallCenter::DisplayStatus()
{
	cout << totalTime << " minutes has passed" << endl;
	cout << pQueue.GetLength() << " calls are left in the waiting list" << endl;
	cout << numOfAnsCalls << " calls have been completed" << endl;
}
