#include "digraph.h"
#include <algorithm>

using namespace std;
Digraph::Digraph()
{
	edges.resize(20);
	auto it = (edges.begin());
	for (int i = 0; i < 20; i++) {
		(*it).resize(20);
		advance(it, 1);
	}
}

bool Digraph::AddVertex(vertex v)
{
	auto it = find(vertices.begin(),vertices.end(),v);
	if (it != vertices.end()) {
		return false;
	}
	vertices.push_back(v);
	auto it2 = edges.begin();
	advance(it2,vertices.size() - 1);
	fill((*it2).begin(), (*it2).end(), 0);
	return true;
}

bool Digraph::AddEdge(vertex v1, vertex v2)
{
	auto it1 = find(vertices.begin(), vertices.end(), v1);
	auto it2 = find(vertices.begin(), vertices.end(), v2);
	if (it1 == vertices.end() || it2 == vertices.end()) {
		return false;
	}
	auto it3 = edges.begin();
	advance(it3, it1-vertices.begin());
	(*it3).at(it2 - vertices.begin()) = 1;
	return true;
}

bool Digraph::RemoveEdge(vertex v1, vertex v2)
{
	auto it1 = find(vertices.begin(), vertices.end(), v1);
	auto it2 = find(vertices.begin(), vertices.end(), v2);
	if (it1 == vertices.end() || it2 == vertices.end()) {
		return false;
	}
	auto it3 = edges.begin();
	advance(it3, it1 - vertices.begin());
	if ((*it3).at(it2 - vertices.begin()) == 1) {
		(*it3).at(it2 - vertices.begin()) = 0;
		return true;
	}
	else{ return false; }
}

bool Digraph::FindEdge(vertex v1, vertex v2)
{
	auto it1 = find(vertices.begin(), vertices.end(), v1);
	auto it2 = find(vertices.begin(), vertices.end(), v2);
	if (it1 == vertices.end() || it2 == vertices.end()) {
		return false;
	}
	auto it3 = edges.begin();
	advance(it3, it1 - vertices.begin());
	if ((*it3).at(it2 - vertices.begin()) == 1) {
		return true;
	}
	else { return false; }
}

bool Digraph::FindVertex(vertex v)
{
	auto it = find(vertices.begin(), vertices.end(), v);
	if (it == vertices.end()) {
		return false;
	}
	else{ return true; }
}

int Digraph::NumOfVertex()
{
	return vertices.size();
}

int Digraph::NumOfEdge()
{
	int tmp=0;
	auto it = (edges.begin());
	for (int i = 0; i < vertices.size(); i++) {
		for (int j = 0; j < vertices.size(); j++) {
			if ((*it).at(j) == 1) {
				tmp++;
			}
		}
		advance(it, 1);
	}
	return tmp;
}

vector<vertex> Digraph::Vertices()
{
	return vertices;
}

vector<vertex> Digraph::Successors(vertex v)
{
	auto it = find(vertices.begin(), vertices.end(), v);
	vector<vertex> ret;
	if (it == vertices.end()) {
		return ret;
	}
	auto it2 = (edges.begin());
	advance(it2, it-vertices.begin());
	for (int i = 0; i < vertices.size(); i++) {
		if ((*it2).at(i) == 1) {
			ret.push_back(vertices.at(i));
		}
	}
	return ret;
}

int Digraph::Predecessors(vertex v)
{
	int ret = 0;
	auto it = find(vertices.begin(), vertices.end(), v);
	if (it == vertices.end()) {
		return ret;
	}
	int ind = it - vertices.begin();
	auto it2 = (edges.begin());
	for (int i = 0; i < vertices.size(); i++) {
		if ((*it2).at(ind) == 1) {
			ret++;
		}
		advance(it2, 1);
	}
	return ret;
}

bool Digraph::RemoveVertex(vertex v)
{
	auto it = find(vertices.begin(), vertices.end(), v);
	if (it == vertices.end()) {
		return false;
	}
	int ind = it - vertices.begin();
	auto it2 = (edges.begin());
	for (int i = 0; i < vertices.size(); i++) {
		(*it2).erase((*it2).begin()+ind);
		(*it2).resize(20);
		advance(it2, 1);
	}
	vertices.erase(it);
	it2 = (edges.begin());
	advance(it2, ind);
	edges.erase(it2);
	edges.resize(20);
	it2 = (edges.begin());
	advance(it2, 19);
	(*it2).resize(20);
	return true;
}
