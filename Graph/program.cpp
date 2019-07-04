#include "circle.h"
#include <iostream>
using namespace std;

void filler(Circle& c);
void loop(Circle& c);
char condition(int option, Circle& c);

int main(void) {
	Circle c;
	filler(c);
	loop(c);
}

void filler(Circle& c) {
	c.AddMember("Jack");
	c.AddMember("Jill");
	c.AddMember("James");
	c.AddFriend("Jack", "Jill");
	c.AddFriend("Jill", "Jack");
	c.AddFriend("James", "Jill");
	c.AddFriend("James", "Jack");
	c.AddFriend("Jack", "James");
}

void loop(Circle& c) {

	int option = 0;
	char quit = 'n';

	while (quit != 'y') {
		cout << "Type 1 for learning who are the members of the circle of friends?" << endl;
		cout << "Type 2 for learning how many people belong to the circle of friends?" << endl;
		cout << "Type 3 for learning how many friendships are part of the circle of friends?" << endl;
		cout << "Type 4 for learning is name a member of the circle of friends?" << endl;
		cout << "Type 5 for learning who has name designated as a friend?" << endl;
		cout << "Type 6 for learning has name1 designated name2 as a friend?" << endl;
		cout << "Type 7 for learning has name1 been designated by name2 as a friend?" << endl;
		cout << "Type 8 to remove name1 as a designated friend of name2" << endl;
		cout << "Type 9 for learning how many people have designated name as a friend?" << endl;
		cout << "Type 10 to remove name as a member of the circle of friends" << endl;
		cout << "Type 11 to quit" << endl;

		cin >> option;
		quit=condition(option, c);
	}
}

char condition(int option,Circle& c) {
	char quit = 'n';
	string name1 = " ";
	string name2 = " ";

	if (option == 4 || option == 5 || option == 9 || option == 10) {
		cout << "Enter the name of the person: ";
		cin >> name1;
		if (option == 4) {
			c.NameInCircle(name1);
		}
		else if (option == 5) {
			c.AllFriends(name1);
		}
		else if (option == 10) {
			c.RemoveMember(name1);
		}
		else {
			c.FriendsofPerson(name1);
		}
	}
	else if (option == 6 || option == 7 || option == 8) {
		cout << "Enter the name1 and name2: ";
		cin >> name1 >> name2;
		if (option == 6) {
			c.OneWayFriends(name1, name2);
		}
		else if (option == 7) {
			c.ReverseFriends(name1, name2);
		}
		else {
			c.RemoveFriend(name1, name2);
		}
	}
	else if (option == 1) {
		c.Members();
	}
	else if (option == 2) {
		c.NumOfMembers();
	}
	else if (option == 3) {
		c.NumOfFriends();
	}
	else if (option == 11) {
		quit = 'y';
	}
	else {
		cout << "Selected option does not exist" << endl;
	}
	return quit;
}