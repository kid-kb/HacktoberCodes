#include<bits/stdc++.h>
#define ull unsigned long long
#define ll int64_t 
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
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI acos(-1) 
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define CY cout << "YES\n"
#define CN cout << "NO\n"
#define print(x) for(auto it:x) cout<<it<<' '; cout<<"\n";
#define DECIMAL cout<<setiosflags(ios::fixed)<<setiosflags(ios::showpoint);

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

class segmentTree{
	public:
		vector<int>tree;
		vector<int>arr;
		int n;
		int defValue;
		segmentTree(){;}
		segmentTree(vector<int>arr1){
			n = arr1.size();
			defValue = INT_MAX; // for min query
			// defValue = INT_MIN; 
			// above for max query
			//defValue = 0; 
			// above for sum query
			tree.resize(4*n);
			arr = arr1;
			build(0,0,n-1);
		}
		int solve(int x,int y){
			return min(x,y);
			// return max(x,y);
			// return x + y;
		}
		void build(int node,int start,int end){
			if(start > end)	
				return ;
			if(start==end){
				tree[node] = arr[start]; // leaf node
				return ;
			}
			int mid = (start + end)/2;
			build(2*node+1,start,mid);
			build(2*node+2,mid+1,end);
			tree[node] = solve(tree[2*node+1],tree[2*node+2]);
		}
		// ind(index) should be zero based
		void solveUpdate(int node,int start,int end,int ind,int val){
			if(start > end)
				return ;
			if(start==end){
				arr[ind] = val;
				tree[node] = val;
				return ;
			}
			int mid = (start+end)/2;
			if(ind>=start&&ind<=mid)
				solveUpdate(2*node+1,start,mid,ind,val);
			else
				solveUpdate(2*node+2,mid+1,end,ind,val);
			tree[node] = solve(tree[2*node+1],tree[2*node+2]);
		}
		void update(int ind,int val){
			solveUpdate(0,0,n-1,ind,val);
		}
		int solveQuery(int node,int start,int end,int l,int r){
			if(l>end||r<start)
				return defValue;
			if(start>=l&&end<=r)
				return tree[node];
			int mid = (start+end)/2;
			int ans1 = solveQuery(2*node+1,start,mid,l,r);
			int ans2 = solveQuery(2*node+2,mid+1,end,l,r);
			return solve(ans1,ans2);
		}
		int query(int l,int r){
			return solveQuery(0,0,n-1,l,r);
		}
};

int main()
{
	FAST_IO ;
	int i,j,k,n;
	return 0;
}

/*
If u haven't come up with an approach yet ,skip this one
  Try this when feeling stuck -
  1. Int overflow, array bounds
  2. Special cases (n=1?)
  3. Prove your approach to yourself(mathematical induction,counter-intuitive or stronger test cases)
  4. Calm down and don't look at standings and stop thinking about rating and think about the question
  5. Just do it! 
*/ 

//Benq's advice - 
/* 
	And following advices are must for me -
	* do something instead of nothing and stay organized
	* WRITE STUFF DOWN 
*/

//#define _GLIBCXX_DEBUG 
// It will convert WA verdict to runtime error if that error is caused due to out of bound excess , declare it at the top
//#pragma GCC optimize "trapv" 
// It will convert WA to runtime error if WA was caused due to int overflow error,declare it anywhere
