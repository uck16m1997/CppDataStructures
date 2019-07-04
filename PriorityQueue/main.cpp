#include <iostream>
#include <cstdlib>
#include <ctime>
#include "CallCenter.h"
using namespace std;

Call CallGenerator(int arrt);// takes arrival time as an input calculates the random variables and and creates a call object and returns it
void Inputs(int& sL, double& aR);// takes the inputs necesarry for the main function from terminal and assigns them to variables referenced from main
bool CallExists(double aR);// calculates the random possiblity of call existing if call exists returns true and false otherwise
void Caller();/*creates a callcenter object after that runs a loop for the duration of simulation and if a call exists adds it to call and updates call for every iteration
			  after simualtopn duration is over than continues to run the simulation untill there are no calls left in the call center*/

int main(void) {
	srand(time(NULL));
	Caller();

}

void Caller() {
	CallCenter cCenter;
	int simLength=0;
	double aRate;
	Inputs(simLength,aRate);
	int i;
	for (i = 0; i < simLength; i++) {
		if (CallExists(aRate)) {
			Call c = CallGenerator(i);
			cCenter.AcceptCall(c);
		}
		cCenter.UpdateCenter();
		if (i % 5 == 0) { cCenter.DisplayStatus(); }
	}
	while (!cCenter.CenterDone()) {
		
		cCenter.UpdateCenter();
		if (i % 5 == 0) { cCenter.DisplayStatus(); }
		i++;
	}
	cCenter.DisplayResults();
}

void Inputs(int& sL, double& aR) {
	cout << "Enter simulation length and call arrival rate ";
	cin >> sL >> aR;
}

bool CallExists(double aR) {
	aR *= 10;
	if (rand() % 10 <= aR) {
		return true;
	}
	else { return false; }
}

Call CallGenerator( int arrt) {
	int pr;
	int anst;
	int pRand = rand() % 10;
	if (pRand == 9) {pr = 1;}
	else if (pRand < 6) { pr = 3; }
	else { pr = 2; }
	int aRand = rand() % 5 + 3;
	anst = aRand;

	Call ret(arrt, pr, anst);
	return ret;
}
