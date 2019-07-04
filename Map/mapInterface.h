//mapInterface.h

#ifndef MAP_INTERFACE_
#define MAP_INTERFACE_

/*
A Map is a value oriented container class that holds a collection of elements related to each other by membership.  Elements are key-value pairs.
*/

#include<utility>  //needed for the type: pair<T1, T2>
#include<string>
using namespace std;

typedef int KeyType; //KeyType must be comparable using the 
					 //relational operators
typedef string* ValueType;

typedef pair<KeyType, ValueType> ElementType;

class MapInterface {
public:

	virtual bool empty() const = 0;
	//input: none
	//output: returns true if the Map is empty; else false
	//side effects: none

	virtual int size() const = 0;
	//input: none
	//output: returns the number of elements in the Map
	//side effects: none

	virtual bool add(ElementType element) = 0;
	//input: an element (key and its associated value)
	//output: returns true if the key-value pair was 				     	//        added; else false(the key was found)
	//side effects: Map has one more element (if addition      		     	//              done)

	virtual bool find(KeyType key) const = 0;
	//input: a key
	//output: return true is an element with this key was 			//        found; else false
	//side effects: none

	virtual ValueType retrieve(KeyType key) const = 0;
	//input: a key
	//output: returns the value associated with key (a 			//        null pointer if the key was not found)
	//side effects: none

	virtual bool remove(KeyType key) = 0;
	//input: a key
	//output: returns true if item is removed;
	//        else false (key not found)
	//side effects: Map has one less element (if remove 			//              done)

};
#endif