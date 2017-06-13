#include "iostream"
#include "stack"

using namespace std;

//This structure is for representing an edge in our graph
struct Edg
 {
 	int source, destination, weight;
 }; 

struct Graph
{

	int V, E; //number of vertices and edges;
	Edg* edge;
};

// this structure represent a subset for union-find funtions
struct subset
{
	int parent;
	int rank;
};

// find root and make root as parent of current node
int find(struct subset subsets[], int i)
{
	
   
    if (subsets[i].parent != i)
    {
      subsets[i].parent = find(subsets, subsets[i].parent);
    }
 
return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    // Attach smaller rank tree under root of high
    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
    }
 
    // If ranks are same, then make one as root and
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edg[E];
    return graph;
}

// The main function for MST using Boruvka's algorithm
void boruvkaMST(struct Graph* graph)
{
    // Get data of given graph
    int V = graph->V, E = graph->E;
    Edg *edge = graph->edge;
    
    struct subset *subsets = new subset[V];
 
    // this array is to store index of the cheapest edge of
    int *cheapest = new int[V];
 
    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
        cheapest[v] = -1;
    }
 
    // Initially there are V different trees and weight is 0
    int numTrees = V;
    int MSTweight = 0;
 
    // Keep combining components (or sets) until all compnentes are not combined into single MST.
    while (numTrees > 1)
    {
        // Traverse through all edges and update cheapest of every component
        for (int i=0; i<E; i++)
        {
            // Find components of two corners of current edge
            int set1 = find(subsets, edge[i].source);
            int set2 = find(subsets, edge[i].destination);
 
            // If two corners of current edge belong to same set, ignore current edge
            if (set1 == set2)
                continue;
 
            // Else check if current edge is closer to previous cheapest edges of set1 and set2
            else
            {
               if (cheapest[set1] == -1 || edge[cheapest[set1]].weight > edge[i].weight)
               {
                 cheapest[set1] = i;
               }
 
               if (cheapest[set1] == -1 || edge[cheapest[set2]].weight > edge[i].weight)
               {
                 cheapest[set2] = i;
               }
            }
        }
 
        // now picked cheapest edges and adding them in to MST
        for (int i=0; i<V; i++)
        {
            if (cheapest[i] != -1)
            {
                int set1 = find(subsets, edge[cheapest[i]].source);
                int set2 = find(subsets, edge[cheapest[i]].destination);
 
                if (set1 == set2)
                {
                    continue;
                }

                MSTweight += edge[cheapest[i]].weight;
                cout<<" Edge "<<edge[cheapest[i]].source<<" to "<<edge[cheapest[i]].destination<<" added in MST"<<endl;
          
                // Union between sets so that we can decrese number of trees
                Union(subsets, set1, set2);
                numTrees--;
            }
        }
    }
 
 	cout<<"Total Weight of MST is : "<<MSTweight<<endl;
    
    return;
}

int main(int argc, char const *argv[])
{
    int V, E;
    
    cout<<"Enter the number of vertices : ";
    cin>>V;
    cout<<endl;

    cout<<"Enter the number of egdes : ";
    cin>>E;

    struct Graph* graph = createGraph(V, E);
 	int j =1;
 	for (int i = 0; i < E; ++i)
 	{	
 		
 		cout<<j<<" no. Source : ";
 		cin>> graph->edge[i].source;
 		
 		cout<<j<<" no. Destination : ";
 		cin>>graph->edge[i].destination;

 		cout<<"Weight : ";
 		cin>>graph->edge[i].weight;
 		cout<<endl;
 		j++;

 	}
 
    boruvkaMST(graph);
	return 0;
}