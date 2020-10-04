#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define f(i,s,e) for(i=s;i<e;++i)
#define endl << "\n"
#define sp << " "
#define INF INFINITY
#define mset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define crap ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.14159265358979323846264338327950288419716939937510
#define pb(a) push_back(a)
#define pf(a) push_front(a)
using namespace std;

#define N 1000
vector <ll> adj[N] ;
vector <bool> visited(N,false) ;
vector <ll> tsort ;

void topo_sort(ll node)
{
	visited[node] = true;
	ll i;
	f(i,0,adj[node].size())
	{
		if(!visited[adj[node][i]])
			topo_sort(adj[node][i]);
	}
	tsort.pb(node) ;
}

int main()
{
	crap;
//	int t;
//	cin>>t;
//	while(t--)
//	{
		ll i,j,k,n,m;
		cin >> n >> m;
		f(i,0,m)
		{
			ll x,y;
			cin >> x >> y;
			x--; y--;
			adj[x].pb(y);
		}
		f(i,0,n)
			sort(all(adj[i]) , greater <ll> () ); //For ensuring lexicographically smallest
		for(i = n- 1; i>=0 ; --i)
		{
			if(!visited[i])
				topo_sort(i);
		}
		for(i=tsort.size()-1;i>=0;--i)
			cout << tsort[i] + 1 sp;
		cout endl;
//	}
	return 0;
}
