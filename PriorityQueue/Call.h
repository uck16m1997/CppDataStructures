#ifndef CALL_H
#define CALL_H


class Call
{
public:
	Call();//constructor assigns data members to initial values
	Call(int arrT, int p, int ansT);// constructor assigns data members to given values
	int GetPriority() const;// returns priority
	int GetArrTime() const;// returns arrival time
	int GetAnsTime() const;//returns answer time
	void SetPriority(int p);// sets priority to given value
	bool operator>(Call obj);// returns true if priority is smaller than given object else returns false
	bool operator<(Call obj);// returns true if priority is bigger than given object else returns false
	bool operator==(Call obj);// returns true if priority is equal to given object else returns false
	bool operator!=(Call obj);// returns true if priority is not equal to given object else returns false
	bool operator>=(Call obj);// returns true if priority is smaller than or equals to given object else returns false
	bool operator<=(Call obj);// returns true if priority is bigger than or equals to given object else returns false


private:
	int arrivalTime;
	int priority;
	int answerTime;
};

#endif // 