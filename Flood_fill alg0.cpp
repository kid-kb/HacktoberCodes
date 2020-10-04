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

//Flood Fill algorithm , For traversing a given matrix in O(N*M) complexity

#define N 50
#define M 50

bool DFS(int n,int m,int arr[N][M],int x,int y,vector< vector < bool > > &visited) //x and y representing source
{
	if(x==n-1&&y==m-1)
		return true;
	if(x<0||y<0)
		return false;
	if(x>=n||y>=m)
		return false;
	if(!arr[x][y])
		return false;
	if(visited[x][y])
		return false;
	visited[x][y] = true;
	if(DFS(n,m,arr,x-1,y,visited))
		return true;
	if(DFS(n,m,arr,x,y-1,visited))
		return true;
	if(DFS(n,m,arr,x+1,y,visited))
		return true;
	if(DFS(n,m,arr,x,y+1,visited))
		return true;
}

int main()
{
	crap ;
	int t;
	cin>>t ;
	int arr[N][M];
	while(t--)
	{
		int n,m,temp;
		cin >> n >> m;
		vector < vector <bool> > visited(n);
		f(i,0,n)
		{
			f(j,0,m)
			{
				cin >> temp;
				visited[i].pb(false);
				arr[i][j] = temp;
			}
		}
		if(DFS(n,m,arr,0,0,visited))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
