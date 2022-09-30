#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include<cmath>
#include<cstring>
#define pb push_back
#define ll long long
#define ull unsigned long long
#define deb(x) cerr<<#x<<" "<<x<<"\n"
#define debi cerr<<"hey sparky\n"
#define x first
#define y second
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define eps (double)1e-9
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;
using namespace __gnu_pbds; 
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pdbs;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
//void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
// look for  all edge cases
//search for a pattern

string se;
vector<int> lcp;

void radix_sort(vector<pair<pair<int,int> , int>> &a){
	int n = a.size();
	{
		vector<int> cnt(n);
		for(auto it : a){
			int val = it.x.y;
			cnt[val] +=1;
		}
		vector<pair<pair<int,int> , int>> new_a(n);
		
		vector<int> pos(n);
		
		pos[0] = 0;
		
		for(int i =1 ; i < n; i++){
			pos[i] = pos[i-1] + cnt[i-1];
		}
		
		for(auto it : a){
			int i = it.x.y;
			new_a[pos[i]] = it;
			pos[i] += 1;
		}
		
		a = new_a;
		//debug(new_a);
	}
	{
		vector<int> cnt(n);
		for(auto it : a){
			int val = it.x.x;
			//debug(val);
			cnt[val] +=1;
		}
		vector<pair<pair<int,int> , int>> new_a(n);
		
		vector<int> pos(n);
		
		pos[0] = 0;
		
		for(int i =1 ; i < n; i++){
			pos[i] = pos[i-1] + cnt[i-1];
		}
		
		for(auto it : a){
			int i = it.x.x;
			new_a[pos[i]] = it;
			pos[i] += 1;
		}
		
		a = new_a;
		//debug(new_a);
	}
	
}	


void buildlcp(string s){
	s += '$';
	int n =  s.size();
	
	vector<int> c(n),p(n); 
	{
		vector<pair<char,int>> a(n);
		for(int i =0 ; i < n; i++){
			a[i] = {s[i] , i};
		}
		sort(all(a));
		
		for(int i =0 ; i < n; i++){
			p[i] = a[i].y;
		}
		c[p[0]] = 0;
		
		for(int i = 1; i < n; i++){
			if(a[i].x == a[i-1].x)
				c[p[i]] = c[p[i-1]];
			else
				c[p[i]] = c[p[i-1]] + 1;
		}
	}
	
	
	{
		// k -> k+1 
		int k = 0;
		vector<pair<pair<int,int> , int>> a(n);
		
		while((1<<k) < n){
			for(int i = 0; i < n;i++){
				a[i] = {{c[i] , c[(i+(1<<k))%n]} ,i};
			}
			
			radix_sort(a);
			
			for(int i =0 ; i < n; i++){
				p[i] = a[i].y;
			}
			c[p[0]] = 0;
			
			for(int i = 1; i < n; i++){
				if(a[i].x == a[i-1].x)
					c[p[i]] = c[p[i-1]];
				else
					c[p[i]] = c[p[i-1]] + 1;
			}
			
			k = k +1;
		}
		
		
	}
	
	//debug("hi");
	for(int i = 0; i < n; i++){
		cout<<p[i]<<" ";
	}
	
	int k = 0;
	
	lcp.assign(n,0);
	for(int  i= 0 ; i < n-1; i++){
		int pos = c[i];
		//debug(pos);
		int j = p[pos-1];
		while(s[i+k] == s[j+k]){
			k++;
		}
		
		lcp[pos] = k;
		k = max(k-1 , (ll)0);

	}
	cout<<"\n";
	for(int i =1 ; i < n; i++){
		cout<<lcp[i]<<" ";
	}
	
	
	
	
}


signed main() {	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
		
	cin >> se;
	
	//debug("hi");
	buildlcp(se);
	
	//int n = se.size();
	
	
	
	
	
	return 0;
}
