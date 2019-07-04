#ifndef CALLCENTER_H
#define CALLCENTER_H

#include "PriorityQueue.h"
class CallCenter
{
public:
	CallCenter();//constructor assigns variables to their initial values
	void AcceptCall(Call c);//ads the call to the waiting list

	void UpdateCenter();/*increments the time variable if there are no calls ongoin but there the waitlist 
						not empty takes the call from waitlist to an ongoing call and stores their wait time and 
						priority infos if there is an call ongoing then checks if the call equal to the answer time 
						if it is closes the call and increases the numberof calls answered*/

	bool CenterDone(); // returns true if there are no call in the waitlist or ongoing else returns false
	void DisplayResults();//displays the simulation results
	void DisplayStatus();//displays the current status of the simulation

private:
	PriorityQueue pQueue;
	Call curCall;
	int numOfAnsCalls;
	int totalTime;
	int waitTime;
	double waitP1;
	double waitP2;
	double waitP3;
	int numOfP1;
	int numOfP2;
	int numOfP3;
	int openTime;
};

#endif

