#include "iostream"
#include "cstdio"
#include "vector"
#include "queue"
#define MAX 10000

using namespace std;

vector< char >edge[MAX]; // This is adjacency list of vertexes
vector< int >cost[MAX]; // This is for weights of edges
queue< int >qu;
void BFS(int source, int n);
char disp(int n)
{
    char arr [5] = {'A','B','C','D','E'};
    char res;

    res = arr[n-1];
 return res;   
}
int main()
{
    int i, j, n, e;
    int x, y;
    cout<<"Enter the number of 'Nodes' and 'Edges' : ";
    cin>>n>>e;
   // scanf("%d%d", &n, &e);
    cout<<"Enter the Edges between your given Nodes : ";
    for(i = 0; i < e; i++)
    {
        cin>>x>>y;
        //scanf("%d%d", &x, &y);
        edge[x].push_back(y);
    }

    BFS(1,n);

    return 0;
}

void BFS(int source, int n)
{
    int visited[MAX] = {0}, distance[MAX] = {0}, u, sz, v, i;
    qu.push(source);
    visited[source] = 1;
    distance[source] = 0;
    while(!qu.empty())
    {
        u = qu.front();
        sz = edge[u].size();
        for(i = 0; i < sz; i++)
        {
            v = edge[u][i];
            if(visited[v] == 0)
            {
                distance[v] = distance[u] + 1;
                visited[v] = 1;
                qu.push(v);
            }
        }
        qu.pop();
    }

    for(i = 1; i <= n; i++)
    {
        cout<<"Distance between ";
        cout<<disp(source)<<" and "<<disp(i)<<" is : ";
        cout<<distance[i]<<endl;  
       // printf("%d and %d is %d\n", source, i, distance[i]);
    }
}
