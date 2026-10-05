/*
 * graph.h
 *
 *  Created on: Feb 12, 2019
 *      Author: mihir
 */

#pragma once

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

namespace
{
	const int MAXV = 1000; // max number of vertices
};

struct graph_edge
{
	graph_edge() : v(-1), weight(0), next(nullptr) {}
	graph_edge(int v_, int weight_) : v(v_), weight(weight_), next(nullptr) {}

	int v; // for an edge (x,y), v represents y in x's adjacency list
	int weight; // weight of the edge (x,y)
	graph_edge* next; // pointer to the next edge in x's adjacency list
};

class graph
{
public:
	using serialized_graph = vector<tuple<int, int, int>>;
	enum vertex_state {undiscovered = 0, discovered = 1, processed = 2};

	graph();
	graph(const serialized_graph& sg);

	void display() const;
	void bfs(int start);
	void init_bfs();
	void process_vertex_early(int x);
	void process_vertex_late(int x);
	void process_edge(int x, int y);

private:
	void insert_edge(int x, int y, int weight, bool directed);

	// adj_list are number 0 to N-1
	graph_edge* adj_list[MAXV]; // adjacency list for each edge
	int degree[MAXV]; // degree of each edge
	int num_vertices; // number of vertices in the graph
	int num_adj_list; // number of adj_list in the graph
	bool directed; // whether the graph is directed or not

	int parent[MAXV]; // array of parent vertex of each vertex in a BFS traversal
	vertex_state vstate[MAXV]; // current state of each vertex in a BFS traversal
};

graph::graph() : num_vertices(0), num_adj_list(0), directed(false)
{
	for (int i = 0; i < MAXV; ++i)
	{
		adj_list[i] = nullptr;
		degree[i] = 0;
	}
	init_bfs();
}

/*
 * serialized_graph is a serialized graph format used to express a graph
 * It is of the form -
 * v, e, d
 * x1, y1, w1,
 * x2, y2, w2 etc.
 * where,
 * v: num. vertices
 * e: num. adj_list
 * d: directed or not
 * (x1, y1, w1) is an edge from vertex x1 to vertex y1 with a weight w1
 */
graph::graph(const serialized_graph& sg)
{
	const auto& first_tup = sg.front();
	this->num_vertices = get<0>(first_tup);
	this->num_adj_list = get<1>(first_tup);
	this->directed = 1 == get<2>(first_tup);

	for (auto tup = sg.begin() + 1; tup != sg.end(); ++tup)
	{
		int x = get<0>(*tup);
		int y = get<1>(*tup);
		int wt = get<2>(*tup);
		insert_edge(x, y, wt, this->directed);
	}

	init_bfs();
}

void graph::insert_edge(int x, int y, int weight, bool directed)
{
	graph_edge* edge = new graph_edge(y, weight);
	edge->next = adj_list[x];
	adj_list[x] = edge;
	++degree[x];
	if (!directed) insert_edge(y, x, weight, true);
}

void graph::display() const
{
	cout << "Num. Vertices: " << num_vertices
		 << ", Num. adj_list: " << num_adj_list
		 << ", Directed: " << (directed ? "true" : "false") << "\n";

	for (int i = 0; i < num_vertices; ++i)
	{
		for (graph_edge* edge = adj_list[i]; edge != nullptr; edge = edge->next)
		{
			cout << "x[" << i << "],  y[" << edge->v << "],  w[" << edge->weight << "]\n";
		}
	}
}

void graph::init_bfs()
{
	for (int i = 0; i < MAXV; ++i)
	{
		parent[i] = -1;
		vstate[i] = undiscovered;
	}
}

void graph::bfs(int start)
{
	queue<int> bfsq;
	bfsq.push(start);
	vstate[start] = discovered;

	while (!bfsq.empty())
	{
		int x = bfsq.front();
		bfsq.pop();
		auto neighboring_edge = adj_list[x];
		process_vertex_early(x);
		vstate[x] = processed;
		while (neighboring_edge)
		{
			int y = neighboring_edge->v;
			if (vstate[y] != processed || directed)
			{
				process_edge(x, y);
			}

			if (vstate[y] == undiscovered)
			{
				vstate[y] = discovered;
				parent[y] = x;
				bfsq.push(y);
			}
			neighboring_edge = neighboring_edge->next;
		}
		process_vertex_late(x);
	}
}

void graph::process_vertex_early(int x)
{
	cout << "Processing vertex: " << x << "\n";
}

void graph::process_vertex_late(int x)
{
}

void graph::process_edge(int x, int y)
{
	cout << "Processing edge: " << x << " -> " << y << "\n";
}

void test_graph()
{
	using serialized_graph = graph::serialized_graph;
	serialized_graph sg = {{6, 5, 0}, {0, 1, 10}, {1, 2, 20}, {2, 3, 30}, {3, 4, 40}, {4, 5, 50}};
	graph g(sg);
	g.display();
	g.bfs(0);
}
