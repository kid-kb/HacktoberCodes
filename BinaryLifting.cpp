// Program to find Lowest Common Ancestor of two nodes in a tree.
// The first line of input will be the number of test cases. 
// Each test case will start with a number N the number of nodes in the tree. 
// Nodes are numbered from 1 to N. The next N lines each one will start with a number M the number 
// of child nodes of the Nth node, 0 <= M <= 999 followed by M numbers the child nodes of the Nth node. 
// The next line will be a number Q the number of queries you have to answer for the given tree T.
// The next Q lines each one will have two number v and w in which you have to find the LCA of v and w in T.

// Input will guarantee that there is only one root and no cycles.

#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define pb push_back
ll k,timer;
ll up[100005][32];
vector<ll> graph[100005];
ll intime[100005],outime[100005];
void dfs(ll v,ll par)
{	
	intime[v]=++timer;
	up[v][0]=par;
	for(ll i=1;i<=k;i++)
		up[v][i]=up[up[v][i-1]][i-1];
	for(auto j: graph[v])
	{	if(j!=par)
			dfs(j,v);
	}
	outime[v]=++timer;
}
bool isancestor(ll u,ll v)
{	if(intime[u]<=intime[v] && outime[u]>=outime[v])
		return 1;
	return 0;
}
ll LCA(ll u,ll v)
{	if(isancestor(u,v))	return u;	
	if(isancestor(v,u))	return v;
	for(ll i=k;i>=0;i--)
	{	if(!isancestor(up[u][i],v) && up[u][i])
			u=up[u][i];
	}
	return up[u][0];
}
int main()
{	ll t,n,a,x;
	cin>>t;
	for(ll test=1;test<=t;test++)
	{	cin>>n;
		timer=0;
		k=ceil(log2(n));
		memset(up,0,sizeof(up));
		for(ll i=1;i<=n;i++)
		{	cin>>a;
			while(a--)
			{	cin>>x;
				graph[i].pb(x);
			}
		}
		memset(intime,0,sizeof(intime));
		memset(outime,0,sizeof(outime));
		dfs(1,0);
		ll q,b;
		cin>>q;
		cout<<"Case "<<test<<":"<<endl;
		while(q--)
		{	cin>>a>>b;	
			cout<<LCA(a,b)<<endl;
		}
		for(ll i=1;i<=n;i++)
			graph[i].clear();
	}
}