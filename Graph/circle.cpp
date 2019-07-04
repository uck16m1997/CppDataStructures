#include "circle.h"
#include <iostream>

Circle::Circle()
{
}


void Circle::AddMember(vertex v)
{
	if (graph.AddVertex(v)) {
		cout << v << " was added to the circle" << endl;
	}
	else {
		cout << v << " was not added to the circle" << endl;
	}

}

void Circle::AddFriend(vertex v1, vertex v2)
{
	if (graph.AddEdge(v1, v2)) {
		cout << v1 << " added " << v2 << " as a friend" << endl;
	}
	else {
		cout << v1 << " failed to add " << v2 << " as a friend" << endl;
	}
}

void Circle::Members()
{
	vector<vertex> v= graph.Vertices();
	cout << "Members of the circle are :" << endl;
	for (int i = 0; i <v.size(); i++) {
		cout << v.at(i) <<" "<< endl;
	}
}

void Circle::NumOfMembers()
{
	cout << "There are " << graph.NumOfVertex() << "  members in the circle" << endl;
}

void Circle::NumOfFriends()
{
	cout << "There are " << graph.NumOfEdge() << " friends in the circle" << endl;
}

void Circle::NameInCircle(vertex v)
{
	if (graph.FindVertex(v)) {
		cout << v << " is a member of the circle" << endl;
	 }
	else {
		cout << v << " is not a member of the circle" << endl;
	}
}

void Circle::AllFriends(vertex v)
{
	vector<vertex> v1= graph.Successors(v);
	cout << "Friends of " << v << " are:" << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) <<" "<< endl;
	}
}

void Circle::OneWayFriends(vertex v1, vertex v2)
{
	if (graph.FindEdge(v1, v2)) {
		cout << v1 << " designated " << v2 << " as a friend" << endl;
	}
	else {
		cout << v1 << " didn't designate " << v2 << " as a friend" << endl;
	}
}

void Circle::ReverseFriends(vertex v1, vertex v2)
{
	if (graph.FindEdge(v2, v1)) {
		cout << v1 << " has been designated by " << v2 << " as a friend" << endl;
	}
	else {
		cout << v1 << " hasn't been designated by " << v2 << " as a friend" << endl;
	}
}

void Circle::RemoveFriend(vertex v1, vertex v2)
{
	if (graph.RemoveEdge(v1, v2)) {
		cout << v1 << " removed their friendship with " << v2 << endl;
	}
	else {
		cout << v1 << " couldn't removed the friendship with " << v2 << endl;
	}
}

void Circle::FriendsofPerson(vertex v)
{
	cout << graph.Predecessors(v) << " people added " << v << " as a friend" << endl;
}

void Circle::RemoveMember(vertex v)
{
	if (graph.RemoveVertex(v)) {
		cout << v << " was removed from the circle" << endl;
	}
	else {
		cout << "faield to remove " << v << endl;
	}
}
