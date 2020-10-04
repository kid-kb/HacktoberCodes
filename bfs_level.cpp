#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define f(i,s,e) for(int i=s;i<e;++i)
#define endl << "\n"
#define sp << " "
#define INF INFINITY
#define mset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define crap ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.14159265358979323846264338327950288419716939937510
#define pb(a) push_back(a)
using namespace std;
void bfs(vector <vector <long int> > adj,long int n,long int node,vector <long int>&level)
{
	queue <long int> q;
	vector <bool> visited(n,false);
	q.push(node);
	visited[node]=true;
//	cout<<node sp;
	long int j = node;
	level[node]=1;
	while(!q.empty())
	{
		j=q.front();
		f(i,0,adj[j].size())
		{
			if(!visited[adj[j][i]])
			{
				q.push(adj[j][i]);
				visited[adj[j][i]]=true;
				level[adj[j][i]] = level[j] + 1;
//				cout<<adj[j][i] sp;
			}
		}
		q.pop();
	}
}
int main()
{
	long int n,m;
	cin >> n ;
	m = n-1;
	vector <vector <long int> > adj(n);
	f(i,0,m)
	{
		long int u,v;
		cin >> u >> v;
		u--;v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	long int x,count=0;
	cin >> x;
	vector <long int> level(n,0);
	bfs(adj,n,0,level);
	f(i,0,n)
		if(level[i]==x)
			count++;
	cout << count endl;
	return 0;
}
