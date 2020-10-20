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

vector<int> fin;

const int max_n = 3e5;


void build(string s){
	
	s += '$';
	int n = s.size();
	
	vector<int> c(n) , p(n);
	
	
	//k =0
	{
		vector<pair<char,int>> a(n);
		
		for(int i =0 ; i < n; i++){
			a[i] = {s[i] , i};
		}
		
		sort(all(a));
		
		for(int i =0 ; i < n; i++)p[i] = a[i].y;
		
		c[p[0]] = 0;
		
		for(int i =1 ;  i< n; i++){
			if(a[i].x == a[i-1].x){
				c[p[i]] = c[p[i-1]];
			}
			else{
				c[p[i]] = c[p[i-1]] + 1;
			}
		}
		
		
	}
	
	
	{
		//k -> k+1
		int k = 0;
		
		vector<pair<pair<int,int> , int>> a(n);
		
		while((1<<k) <n){
			
			for(int i =0 ; i< n; i++){
				a[i] = {{c[i] , c[(i+(1<<k))%n]} ,i};
			}
			
			sort(all(a));
			
			for(int i =0 ; i < n; i++)p[i] = a[i].y;
		
			c[p[0]] = 0;
			
			for(int i =1 ;  i< n; i++){
				if(a[i].x == a[i-1].x){
					c[p[i]] = c[p[i-1]];
				}
				else{
					c[p[i]] = c[p[i-1]] + 1;
				}
			}
			
			k = k + 1;
			
		}
		
		
	}
	
	fin = p;
	
}

signed main() {	
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
		
	cin >> se;
	
	
	int ko = se.size();
	build(se);
	
	//debug(fin);
	
	
	for(int i =0 ; i < max_n ; i++){
		se += '$';
	}
	
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		int l = 1 ;
		int r = ko;
		int ans = -1;
		bool exist = false;
		while(l <= r){
			int mid = l + (r-l)/2;
			int val = fin[mid];
			//debug(val ,n);
			
			int opt = s.compare(se.substr(val , n));
			//debug(se.substr(val , n) ,opt);
			//if(opt == 0){
				//ans = mid;
				//break;
			//}
			if(opt <= 0){
				ans = mid;
				if(opt == 0){
					exist = true;
				}
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		
		int ans2 = ans;
		if(exist){
			l = 1 , r = ko;
			while(l <= r){
				int mid = l + (r-l)/2;
				int val = fin[mid];
				//debug(val ,n);
				
				int opt = s.compare(se.substr(val , n));
				//debug(se.substr(val , n) ,opt);
				//if(opt == 0){
					//ans = mid;
					//break;
				//}
				if(opt < 0){
					r = mid - 1;
				}
				else{
					ans = mid;
					l = mid + 1;
				}
			}
			
		}
		
		if(exist == true){
			cout<<ans - ans2+1<<"\n";
		}
		else
			cout<<"0\n";
	}
	
	
	
	return 0;
}
