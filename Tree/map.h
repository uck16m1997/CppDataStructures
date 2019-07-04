#pragma once
#include "mapInterface.h"

class Node {
public:
	Node * lNode;
	Node* rNode;
	ElementType data;
};

class Map : MapInterface
{
public:
	Map();//constructor
	~Map();//destructor
	Map(const Map &obj);// copy assignment 
	Map& operator=(const Map& obj);//copy assignment operator
	void recCopy(Node* n);// copies elements recursively called mainly by copy operators
	void displayAll() const;//displays all item by calling recursive inorder function
	int height() const;//calculates the height by calling recursive recHeight function
	int recHeight(Node* n) const;// calculates the height recursively by dividing the map from left and right till comes to nullptr when going up adds 1;
	void inOrder(Node* n) const;// goes through each element from smallest to biggest by keys recursively
	//interface methods
	bool empty() const;//if Size equals to 0 returns true else returns false
	int size() const;//returns Size (number of items)
	bool add(ElementType element);//adds element in to the map if succesiful returns true else returns false
	bool find(KeyType key) const;//if element with the key found returns true else returns false
	ValueType retrieve(KeyType key) const;// returns the value of the element with given key
	bool remove(KeyType key);// removes the element with given key
private:
	int Size;
	Node* root;
};
