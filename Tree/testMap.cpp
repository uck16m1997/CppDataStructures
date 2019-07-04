#include <iostream>
#include "map.h"
#include <string>
using namespace std;

void CopyConstTest(Map m);

int main(void) {
	Map m;
	ElementType e1 = make_pair(10,new string("value with key 10"));
	m.add(e1);
	ElementType e2 = make_pair(20, new string("value with key 20"));
	m.add(e2);
	ElementType e3 = make_pair(5, new string("value with key 5"));
	m.add(e3);
	ElementType e4 = make_pair(4, new string("value with key 4"));
	ElementType e5 = make_pair(6, new string("value with key 6"));
	m.add(e4);
	m.add(e5);
	m.displayAll();
	cout << "Value 10 which is root is going to get removed"<<endl;
	m.remove(10);
	m.displayAll();

	if (m.find(5)) {
		cout << "Succesifully found element with key 5 in the map find function is working" << endl;
	}
	else {
		cout << "Find should have found the element with key 5 but it failed" << endl;
	}

	if (m.find(10)) {
		cout << "Find found 10 but it should have been removed remove was a failure" << endl;
	}
	else {
		cout << "Find didn't found 10 because it was removed remove works" << endl;
	}
	
	cout << "This map has " << m.size() << " elements with height " << m.height() << endl;

	cout << *(m.retrieve(20))<<endl;

	cout << "Calling function that will call copy constructor to map and add element with key 50 to copy" << endl;

	CopyConstTest(m);

	if (m.find(50)) {
		cout << "find found element with key 50 this means copy constructor was a failure" << endl;
	}
	else {
		cout << "element with key 50 was not added to the original map copy constructor worked" << endl;
	}

	cout << "Creating another map variable and assigning it to the original map value" << endl;
	Map map;
	map = m;

	cout << "Adding element with key 100 to the assigned map" << endl;

	ElementType e = make_pair(100, new string("value with key 100"));
	map.add(e);
	
	if (m.find(100)) {
		cout << "find found element with key 100 this means copy assignment was a failure" << endl;
	}
	else {
		cout << "element with key 50 was not added to the original map copy assignment worked" << endl;
	}
}

void CopyConstTest(Map m) {
	ElementType e = make_pair(50, new string("value with key 50"));
	m.add(e);
}
