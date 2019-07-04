#include "map.h"
#include <iostream>
using namespace std;
Map::Map()
{
	Size = 0;
	root = nullptr;
}

Map::~Map()
{ 
	cout << "Destructor Called" << endl;
	while (Size>0) {
		remove(root->data.first);
	}
}

Map::Map(const Map & obj)
{
	Size = 0;
	root = nullptr;
	cout << "Copy Constructor Called" << endl;
	recCopy(obj.root);
}

Map & Map::operator=(const Map & obj)
{
	cout << "Copy Assignment Operator Called" << endl;
	while (Size>0) {
		remove(root->data.first);
	}
	Size = 0;
	root = nullptr;
	recCopy(obj.root);
	return *this;
}

void Map::recCopy(Node * n)
{
	if (n != nullptr) {
		ElementType e = make_pair(n->data.first,new string(*(n->data.second)));
		this->add(e);
		recCopy(n->lNode);
		recCopy(n->rNode);
	}
}

void Map::displayAll() const
{
	inOrder(root);
}

int Map::height() const
{
	if (Size <= 1) {
		return 0;
	}
	return recHeight(root)-1;
}

int Map::recHeight(Node * n) const
{
	int lHeight = 1;
	int rHeight = 1;
	if (n == nullptr) {
		return 0;
	}
	else {
		lHeight += recHeight(n->lNode);
		rHeight += recHeight(n->rNode);
	}
	if (lHeight > rHeight) {
		return lHeight;
	}
	else {
		return rHeight;
	}
}

void Map::inOrder(Node* n) const
{
	if (n != nullptr) {
		inOrder(n->lNode);
		cout << *(n->data.second) << endl;
		inOrder(n->rNode);
	}
}

bool Map::empty() const
{
	if (Size == 0) { return true; }
	else { return false; }
}

int Map::size() const
{
	return Size;
}



bool Map::add(ElementType element)
{
	Node* n = new Node;
	n->lNode = nullptr;
	n->rNode = nullptr;
	n->data = element;
	if (root == nullptr) {
		root = n;
		Size++;
		return true;
	}
	Node * cur = root;
	while(1){
		if (element.first == cur->data.first) {
			delete n;
			return false;
		}
		else if (element.first < cur->data.first) {
			if (cur->lNode == nullptr) {
				cur->lNode = n;
				Size++;
				return true;
			}
			else {
				cur = cur->lNode;
			}
		}
		else if (element.first > cur->data.first) {
			if (cur->rNode == nullptr) {
				cur->rNode = n;
				Size++;
				return true;
			}
			else {
				cur = cur->rNode;
			}
		}
	}
}

bool Map::find(KeyType key) const
{
	if (root!=nullptr) {
		Node* cur = root;
		while (1) {
			if (key == cur->data.first) {
				return true;
			}
			else if (key < cur->data.first) {
				if (cur->lNode == nullptr) {
					return false;
				}
				else {
					cur = cur->lNode;
				}
			}
			else if (key > cur->data.first) {
				if (cur->rNode == nullptr) {
					return false;
				}
				else {
					cur = cur->rNode;
				}
			}
		}
	}
}

ValueType Map::retrieve(KeyType key) const
{

	if (root != nullptr) {
		Node* cur = root;
		while (1) {
			if (key == cur->data.first) {
				return cur->data.second;
			}
			else if (key < cur->data.first) {
				if (cur->lNode == nullptr) {
					return nullptr;
				}
				else {
					cur = cur->lNode;
				}
			}
			else if (key > cur->data.first) {
				if (cur->rNode == nullptr) {
					return nullptr;
				}
				else {
					cur = cur->rNode;
				}
			}
		}
	}
}

bool Map::remove(KeyType key)
{
	if (root != nullptr) {
		Node* cur = root;
		Node* par = cur;
		while (1) {
			if (key == cur->data.first) {
				
				Node* lRight=cur->lNode;
				Node* rLeft = cur->rNode;
				if (lRight != nullptr) {
					Node* parLR = cur;
					while (lRight->rNode != nullptr) {
						parLR = lRight;
						lRight = lRight->rNode;
					}
					if (lRight->lNode != nullptr) {
						if (lRight == parLR->rNode) {
							parLR->rNode = lRight->lNode;
						}
						else {
							parLR->lNode = lRight->lNode;
						}
					}
					else {
						if (lRight == parLR->rNode) {
							parLR->rNode = nullptr;
						}
						else {
							parLR->lNode = nullptr;
						}
					}
					if (lRight != cur->lNode) {
						lRight->lNode = cur->lNode;
					}
					lRight->rNode = cur->rNode;
					if (cur == root) {
						root = lRight;
					}
					else if(cur==par->lNode){
						par->lNode = lRight;
					}
					else {
						par->rNode = lRight;
					}
					delete cur->data.second;
					delete cur;
				}
				else if (rLeft != nullptr) {
					Node* parRL = cur;
					while (rLeft->lNode != nullptr) {
						parRL = rLeft;
						rLeft = rLeft->lNode;
					}
					if (rLeft->rNode != nullptr) {
						if (rLeft==parRL->lNode) {
							parRL->lNode = rLeft->rNode;
						}
						else {
							parRL->rNode = rLeft->rNode;
						}
					}
					else {
						if (rLeft == parRL->lNode) {
							parRL->lNode = nullptr;
						}
						else {
							parRL->rNode = nullptr;
						}
					}
					if (rLeft != cur->rNode) {
						rLeft->rNode = cur->rNode; 					
					}
					rLeft->lNode = cur->lNode;
					root = rLeft;
					if (cur == root) {
						root = rLeft;
					}
					else if (cur == par->lNode) {
						par->lNode = rLeft;
					}
					else {
						par->rNode = rLeft;
					}
					delete cur->data.second;
					delete cur;
				}
				else {
					delete cur->data.second;
					delete cur;
				}
				
				Size--;
				return true;
			}
			else if (key < cur->data.first) {
				if (cur->lNode == nullptr) {
					return false;
				}
				else {
					par = cur;
					cur = cur->lNode;
				}
			}
			else if (key > cur->data.first) {
				if (cur->rNode == nullptr) {
					return false;
				}
				else {
					par = cur;
					cur = cur->rNode;
				}
			}
		}
	}
}
