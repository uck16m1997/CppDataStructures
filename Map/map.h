#pragma once
#include "mapInterface.h"

class Map: public MapInterface{
public:
	Map();// constructor
	~Map();//destructor 
	Map(const Map& copy);//copy constructor
	Map& operator=(const Map& copy);// assignment operator

	//interface methods
	bool empty() const;
	int size() const;
	bool add(ElementType element);
	bool find(KeyType key) const;
	ValueType retrieve(KeyType key) const;
	bool remove(KeyType key);


private:
	int length;
	class Node {
	public:
		Node * next;
		ElementType data;
	};
	Node* head;
};
