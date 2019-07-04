#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;


void reader(set<string>& s);
void comparator(set<string>&);
void remover(set<string>& s);

int main(void) {

	clock_t time;
	time = clock();

	set<string> s;
	reader(s);
	
	cout << "Size of the set is " << s.size() << endl;
	
	comparator(s);
	remover(s);

	
	cout << "Size of the set after remove is " << s.size() << endl;
	
	time = clock() - time;
	float seconds = (float)time / CLOCKS_PER_SEC;

	cout << "Time taken from ordered set is " << seconds << endl;


}

void reader(set<string>& s) {
	cout << "Enter the name of the file: " << endl;
	string filename;
	cin >> filename;
	ifstream file;
	string line;
	file.open(filename);
	while (file >> line) {
		s.insert(line);
	}

	file.close();

}

void comparator(set<string>& s) {
	int bad = 0;
	int good = 0;
	cout << "Enter the name of the file: " << endl;
	string filename;
	cin >> filename;
	ifstream file;
	string line;
	file.open(filename);
	while (file >> line) {
		set<string>::iterator it = s.find(line);
		if (it != s.end()) {
			bad++;
		}
		else {
			good++;
		}
	}

	cout << "Number of bad IPS " << bad << endl;
	cout << "Number of good IPS " << good << endl;

	file.close();
}

void remover(set<string>& s) {
	int bad = 0;
	cout << "Enter the name of the file: " << endl;
	string filename;
	cin >> filename;
	ifstream file;
	string line;
	file.open(filename);
	while (file >> line) {
		auto it = (s.find(line));
		if (it != s.end()) {
			bad++;
			s.erase(line);
		}
	}
	cout << "Number of removed IPS " << bad << endl;

	file.close();
}