#include "Call.h"

Call::Call(){
	arrivalTime = 0;
	priority = 0;
	answerTime = 0;
}

Call::Call(int arrT, int p, int ansT)
{
	arrivalTime = arrT;
	priority = p;
	answerTime = ansT;
}

int Call::GetPriority() const
{
	return priority;
}

int Call::GetArrTime() const
{
	return arrivalTime;
}

int Call::GetAnsTime() const
{
	return answerTime;
}

void Call::SetPriority(int p)
{
	priority = p;
}

bool Call::operator>(Call obj){
	if (this->priority > obj.GetPriority()) { return false; }
	else { return true; }
}

bool Call::operator<(Call obj){
	if (this->priority < obj.GetPriority()) { return false; }
	else { return true; }
}

bool Call::operator==(Call obj){
	if (this->priority == obj.GetPriority()) { return true; }
	else { return false; }
}

bool Call::operator!=(Call obj){
	if (this->priority != obj.GetPriority()) { return true; }
	else { return false; }
}

bool Call::operator>=(Call obj){
	if (this->priority < obj.GetPriority() || this->priority == obj.GetPriority()) { return true; }
	else { return false; }
}

bool Call::operator<=(Call obj)
{
	if (this->priority > obj.GetPriority() || this->priority == obj.GetPriority()) {
		return true;
	}
	else { return false; }
}


