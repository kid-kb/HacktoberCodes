#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include<cmath>
#include<string>
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


signed main() {	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);	
	
	string s;
	cin >> s;
	s += '$';
	
	
	int n = s.size();
	
	vector<int> p(n) , c(n);
	
	
	//case -> k = 0
	
	vector<pair<char,int>> a(n);
	
	for(int i =0 ; i <n ;i++){
		a[i] = {s[i] , i};
	}	
	
	sort(all(a));
	
	for(int i = 0; i < n; i++){
		p[i] = a[i].second;
	}
	
	c[p[0]] = 0;
	for(int i = 1; i < n; i++){
		if(a[i].first  == a[i-1].first){
			c[p[i]] = c[p[i-1]];
		}
		else
			c[p[i]] = c[p[i-1]] + 1;
			
	}
	
	int k = 0;
	
	while((1<<k) < n){
		// transition from k -> k+1
		vector<pair<pair<int,int>,int>> new_a(n);
		
		for(int i =0 ; i < n; i++){
			new_a[i] = {{c[i] , c[(i+(1<<k))%n]} ,i};
		}
		
		//sort(all(new_a)); 
		
		radix_sort(new_a);
		
		for(int i = 0; i < n; i++){
			p[i] = new_a[i].second;
		}
		
		c[p[0]] = 0;
		for(int i = 1; i < n; i++){
			if(new_a[i].first  == new_a[i-1].first){
				c[p[i]] = c[p[i-1]];
			}
			else
				c[p[i]] = c[p[i-1]] + 1;
				
		}
		
		k++;
	}
	

	for(int i =0 ; i < n ; i++)
		cout<<p[i]<<" ";
	
	
	return 0;
}
