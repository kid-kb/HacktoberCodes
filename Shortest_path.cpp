#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define f(i,s,e) for(long int i=s;i<e;++i)
#define endl << "\n"
#define sp << " "
#define INF INFINITY
#define mset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define crap ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.14159265358979323846264338327950288419716939937510
#define pb(a) push_back(a)
using namespace std;
// Shortest Path Algo
// https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/tutorial/
void dijkstra(vector < vector <pair <long int , long int> >  > adj,long int n,long int src)
{
	vector <bool> visited(n,false);
	multiset < pair <long int,long int> > s;
	vector <long int> dis(n,INF);
	dis[src] = 0 ;
	s.insert(make_pair(0,src));
	while(!s.empty())
	{
		auto it = s.begin();
		s.erase(s.begin());
		long int node = (*it).second;
		if(visited[node]) 
			continue;
		/* The above step has a great relevance in dropping down the time complexity , as if a node is 
			updated then so the connected nodes should be updated but here we are already going the shortest way
			, thnx to set. For ex - 1->2->3,1->2->4, meaning 2 paths to 4,here 4 will alreday be processed using shortest
				path and hence we drop down the complexity significantly */
		visited[node] = true ;
		f(i,0,(adj[node]).size())
		{
			if(dis[adj[node][i].first] > dis[node] + adj[node][i].second)
			{
				dis[adj[node][i].first] = dis[node] + adj[node][i].second;
				s.insert(make_pair(dis[adj[node][i].first],adj[node][i].first));	
			}		
		}
	}
	f(i,0,n)
		if(i!=src)
			cout << dis[i] sp;
}
void bellman_ford()
{
	long int n , m;
	cin >> n >> m;
	vector < vector <long int> > v(m);
	f(i,0,m)
	{
		long int a,b,wt;
		cin >> a  >> b >> wt;
		a--;b--;
		v[i].pb(a);
		v[i].pb(b);
		v[i].pb(wt);	
	}
	vector <long int> dis(n,INF);
	long int src = 0;
	dis[0] = 0; //Source
	f(i,0,n-1)
	{
		f(j,0,m)
			if(v[j].size()  &&	dis[v[j][1]] > v[j][2] + dis[v[j][0]])
				dis[v[j][1]] = v[j][2] + dis[v[j][0]];					
	}
	f(i,0,n)
		if(i!=src)
			cout << dis[i] sp;
}
int main()
{
	crap ;
	int t;
	cin>>t ;
	while(t--)
	{
		bellman_ford();
//		long int n,m;
//		cin >> n >> m;
//		vector < vector <pair <long int , long int> > > adj(n);
//		f(i,0,m)
//		{
//			long int a,b,wt;
//			cin >> a  >> b >> wt;
//			a--;b--;
//			adj[a].pb(make_pair(b,wt));
//		}
//		dijkstra(adj,n,0);
	}
	return 0;
}
/*
Bellman Ford's Algorithm:
Bellman Ford's algorithm is used to find the shortest paths from the source vertex to all other vertices in a weighted graph. 
It depends on the following concept: Shortest path contains at most  edges, because the shortest path couldn't have a cycle.

A very important application of Bellman Ford is to check if there is a negative cycle in the graph

Time Complexity of Bellman Ford algorithm is relatively high O(V.E), in case E=V^2,O(E^3) 

So why shortest path shouldn't have a cycle ?
There is no need to pass a vertex again, because the shortest path to all other vertices could be found without the need for a second visit for any vertices.

Algorithm Steps:

The outer loop traverses from  0 : n-1 .
Loop over all edges, check if the next node distance > current node distance + edge weight, in this case update the next node 
distance to "current node distance + edge weight".
This algorithm depends on the relaxation principle where the shortest distance for all vertices is gradually replaced by more 
accurate values until eventually reaching the optimum solution. In the beginning all vertices have a distance of "Infinity",
but only the distance of the source vertex = , then update all the connected vertices with the new distances (source vertex distance + edge weights), 
then apply the same concept for the new vertices with new distances and so on.


Dijkstra's Algorithm
Dijkstra's algorithm has many variants but the most common one is to find the shortest paths from the source vertex to all other vertices in the graph.

Time Complexity of Dijkstra's Algorithm is O(V^2) but with min-priority queue it drops down to O(V+ElogV).

Algorithm Steps:

Set all vertices distances = infinity except for the source vertex, set the source distance = 0 .
Push the source vertex in a min-priority queue in the form (distance , vertex), as the comparison in the min-priority queue will be according to vertices distances.
Pop the vertex with the minimum distance from the priority queue (at first the popped vertex = source).
Update the distances of the connected vertices to the popped vertex in case of "current vertex distance + edge weight < next vertex distance", then push the vertex
with the new distance to the priority queue.
If the popped vertex is visited before, just continue without using it.
Apply the same algorithm again until the priority queue is empty.


Floyd–Warshall's Algorithm
Floyd–Warshall's Algorithm is used to find the shortest paths between between all pairs of vertices in a graph,
 where each edge in the graph has a weight which is positive or negative. The biggest advantage of using this algorithm is that
  all the shortest distances between any  vertices could be calculated in O(V^3) where  is the number of vertices in a graph.

The Algorithm Steps:

For a graph with  N vertices:

Initialize the shortest paths between any 2 vertices with Infinity.
Find all pair shortest paths that use 0 intermediate vertices, then find the shortest paths that use  intermediate vertex and so on.. until using all N
 vertices as intermediate nodes.
Minimize the shortest paths between any 2 pairs in the previous operation.
For any 2 vertices  i,j one should actually minimize the distances between this pair using the first K nodes.

*/
