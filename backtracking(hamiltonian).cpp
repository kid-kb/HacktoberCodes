//          for undirected graph(all possible cycles)
#include<bits/stdc++.h>
using namespace std;

class Graph 
{
	vector<int> * adj;
	int v;
 public:
	Graph(int vert)
	{
		v = vert;
		adj = new vector<int> [vert+1];
	}
	void addEdge(int v1,int v2)
	{
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	int vertices()
	{
		return v;
	}
	bool areAdjacent(int vertex,int vertex2)
	{
		vector<int>:: iterator it;
		for(it=adj[vertex].begin();it!=adj[vertex].end();it++)
		{
			if((*it)==(vertex2))
			  return true;
		}
		return false;
	}
};

Graph g(5);

bool noRepeat(int result[],int index,int vertex)
{
	for(int i=1;i<index;i++)
	{
		if(result[i]==vertex)
		  return false;
	}
	return true;
}

void hamiltonian(int result[],int index,int vertex)
{
	if(index>(g.vertices()))
	{
		if(g.areAdjacent(result[1],result[g.vertices()]))
		{
			for(int i=1;i<=(g.vertices());i++)
			   cout<<result[i]<<" ";
			cout<<"\n";		
		}
		return;
	}
	if(vertex>(g.vertices()))
	  return;
	if(index==1 || g.areAdjacent(vertex,result[index-1])&&noRepeat(result,index,vertex))
	{
		result[index] = vertex;
		hamiltonian(result,index+1,1);
	}
	if(index!=1)
	   hamiltonian(result,index,vertex+1);
}

int main()
{
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(5,1);
	g.addEdge(1,3);
	g.addEdge(2,5);
	g.addEdge(2,4);
	int result[100];
	for(int i=1;i<=5;i++)
	  result[i] = 1;
	hamiltonian(result,1,1);
	return 0;
}
