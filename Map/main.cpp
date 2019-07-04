#include "map.h"
#include <iostream>
using namespace std;

int main(void) {
	Map map;

	ElementType e1 = make_pair(1, new string("str1"));
	map.add(e1);

	Map copy = map;
	ElementType e2 = make_pair(0, new string("str2"));
	copy.add(e2);

	if (map.add(e1)) {
		cout << "add failed" << endl;
	}
	else {
		cout << "Add was a success" << endl;
	}

	if (map.find(0)) {
		cout << "Copy Failed"<<endl;
	}
	else { 
		cout << "Copy was a success" << endl; 
	}

	Map assigned;
	assigned = copy;

	if (assigned.find(0)) {
		assigned.remove(0);

		if (assigned.find(0)) {
			cout << "Remove failed" << endl;
		}
		else {
			cout << "Remove was a success" << endl;
		}
	}

	if (assigned.retrieve(1) == copy.retrieve(1)) {
		cout << "Assignment failed" << endl;
	}
	else {
		cout << "Assignment was a success" << endl;
	}

}