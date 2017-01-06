#include "iostream"
#include "stdio.h"
#include "vector"
#include "map"
#include "queue"
#define MAX 1000
#define WHITE 1
#define GRAY 2
#define BLACK 3

using namespace std;

vector< int >graph[MAX];
vector< int >parent(MAX), color(MAX);
map< int,int >discoveryTime, finishedTime;
int total_time;

void DFS(int n);
void DFSVisit(int u);

int main()
{
	int numVertex, numEdge, i, j, x, y;
	cout<<"Enter the number of Vertex and Edge";
	scanf("%d%d", &numVertex, &numEdge);

	// Here the vertex will be from 1 to numVertex
	cout<<"Enter the and Edges between Vertexs : ";
	for(i = 0; i < numEdge; i++)
	{	

		scanf("%d%d", &x, &y);
		graph[x].push_back(y);
	}

	DFS(numVertex);
	map<int,int> :: iterator it;
	for(it = finishedTime.begin(); it != finishedTime.end(); it++)
	{
		printf("%d %d\n", it->first, it->second);

	}

	return 0;
}

void DFS(int n)
{
	int i, j, u;
	for(i = 1; i <= n; i++)
	{
		parent[i] = 0;
		color[i] = WHITE;
	}
	total_time = 0;
	for(i = 1; i <= n; i++)
	{
		u = i;
		if(color[u] == WHITE)
			DFSVisit(u);
	}

}

void DFSVisit(int u)
{
	int siz, i, j, v;
	total_time = total_time + 1;
	color[u] = GRAY;
	discoveryTime[u] = total_time;

	siz = graph[u].size();
	for(i = 0; i < siz; i++)
	{
		v = graph[u][i];
		if(color[v] == WHITE)
		{
			parent[v] = u;
			DFSVisit(v);
		}
	}

	total_time = total_time + 1;
	finishedTime[u] = total_time;
	color[u] = BLACK;
}
