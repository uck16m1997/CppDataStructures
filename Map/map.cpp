#include "map.h"
#include <iostream>
#include <cassert>
using namespace std;

Map::Map(){
	length = 0;
	head = nullptr;
}

Map::~Map(){
	cout << "Destructor Called" << endl;
	while (length > 0) {
		remove((head->data).first);
	}
}

Map::Map(const Map & copy)
{
	length = 0;
	head = nullptr;
	cout << "Copy Constructor Called" << endl;
	Node* curPtr = copy.head;
	while (curPtr!=nullptr) {
		ElementType e;
		e.first = (curPtr->data).first;
		e.second = new string(*((curPtr->data).second));
		this->add(e);
		curPtr = curPtr->next;
	}
}

Map&  Map::operator=(const Map & copy)
{
	cout << "Assignment Operator Called" << endl;
	if (this != &copy) {
		while (length > 0) {
			remove((head->data).first);
		}
		Node* curPtr = copy.head;
		while (curPtr != nullptr) {
			ElementType e;
			e.first = (curPtr->data).first;
			e.second = new string(*((curPtr->data).second));
			this->add(e);
			curPtr = curPtr->next;
		}
	}
	return *this;
}


bool Map::empty() const
{
	if (length == 0) { return true; }
	return false;
}

int Map::size() const
{
	return length;
}



bool Map::add(ElementType element)
{
	if (head == nullptr || (element.first < (head->data).first)) {
		Node* nod = new Node();
		nod->next = head;
		nod->data = element;
		head = nod;
		length++;
		return true;
	}
	Node* curPtr=head;
	Node* prevNode = head;
	while (curPtr!=nullptr) {
		if (element.first == (curPtr->data).first) {
			return false;
		}
		else if (element.first < (curPtr->data).first) {
			Node* nod = new Node();
			nod->next = curPtr;
			nod->data = element;
			prevNode->next = nod;
			length++;
			return true;
		}
		prevNode = curPtr;
		curPtr = curPtr->next;
	}
	Node* nod = new Node();
	nod->next = nullptr;
	nod->data = element;
	prevNode->next = nod;
	length++;
	return true;
	
}

bool Map::find(KeyType key) const
{
	Node* curPtr = head;
	while (curPtr != nullptr) {
		if (key == (curPtr->data).first) {
			return true;
		}
		curPtr = curPtr->next;
	}
	return false;
}

ValueType Map::retrieve(KeyType key) const
{
	Node* curPtr = head;
	while (curPtr != nullptr) {
		if (key == (curPtr->data).first) {
			return (curPtr->data).second;
		}
		curPtr = curPtr->next;
	}
	return nullptr;
}

bool Map::remove(KeyType key)
{
	assert(head != nullptr);
	if (key == (head->data).first) {
		Node* delNode = head;
		head = head->next;
		delete (delNode->data).second;
		delete delNode;
		length--;
		return true;
	}
	Node* curPtr = head;
	Node* prevNode = curPtr;
	while (curPtr != nullptr) {
		if (key == (curPtr->data).first) {
			prevNode->next = curPtr->next;
			delete (curPtr->data).second;
			delete curPtr;
			length--;
			return true;
		}
		prevNode = curPtr;
		curPtr = curPtr->next;
	}
	return false;
}
