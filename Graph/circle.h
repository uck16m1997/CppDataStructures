#pragma once
#include "digraph.h"

class Circle
{
public:
	Circle();
	void AddMember(vertex v);//tries to add a member in to the circle prints out if opertaion was succesiful or not
	void AddFriend(vertex v1, vertex v2);//tries to add a friend between two members prints out if opertaion was succesiful or not
	void Members();//prints out the members of the circle
	void NumOfMembers();//prints out the how many member are there in the circle
	void NumOfFriends();//prints out how many people added someone a friend in the circle
	void NameInCircle(vertex v);//prints out if the member given is in the circle or not
	void AllFriends(vertex v);//prints out all people name designated as his/her friend
	void OneWayFriends(vertex v1, vertex v2);//prints out if name1 designated name 2 as a friend or not
	void ReverseFriends(vertex v1, vertex v2);// prints out if name1 has been designated as a friend by name2 or not
	void RemoveFriend(vertex v1, vertex v2);// removes the friendship between two members prints out if operation was succesiful or not
	void FriendsofPerson(vertex v);//prints out how many people added name as a friend
	void RemoveMember(vertex v);//removes the member from circle prints out if opertaion was succesiful or not


private:
	Digraph graph;
};
