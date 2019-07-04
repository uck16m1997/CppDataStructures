#pragma once
#include <vector>
#include <list>
#include <string>
using namespace std;

typedef string vertex;
typedef int edge;

class Digraph
{
public:
	Digraph();//constructor
	bool AddVertex(vertex v);//adds vertex into the directed graph
	bool AddEdge(vertex v1, vertex v2);//adds edge between the vertexes given if they are in the graph
	bool RemoveEdge(vertex v1, vertex v2);// removes the edge between the vertexes given if there are the vertexes and a edge
	bool FindEdge(vertex v1, vertex v2);// finds if there is an edge between two vertexes 
	bool FindVertex(vertex v);// finds if there is a vertex in the graph
	int NumOfVertex();// returns the number of vertexes in the graph
	int NumOfEdge();//returns the number of edges in the graph
	vector<vertex> Vertices();//returns the vertexes in a vector
	vector<vertex>  Successors(vertex v);//returns the successors of a vertex
	int  Predecessors(vertex v);//returns the predecessors of a vertex
	bool RemoveVertex(vertex v);
private:
	vector<vertex> vertices;
	list<vector<edge>> edges;
};