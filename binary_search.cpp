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
#define crap ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.14159265358979323846264338327950288419716939937510
#define pb(a) push_back(a)
#define pf(a) push_front(a)

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

bool bin_search(vector <ll>&arr,ll key)
{
	ll i,n,b;
	n = arr.size() ;
	i = -1;
	for(b=n;b>=1;b/=2)
		while(i+b < n && arr[i+b]<=key) i+=b ;
	if(arr[i]==key)
		return true ;
	return false ;
}

ll low_bound(vector <ll>&arr,ll key)
{
	ll i,n,b;
	n = arr.size() ;
	i = -1;
	for(b=n;b>=1;b/=2)
		while(i+b<n && arr[i+b]<key) i+=b ;
//	if(i+1<=n-1&&i+1>=0)
//		return arr[i+1] ;
	return i+1 ;
}

ll upp_bound(vector <ll>&arr,ll key)
{
	ll i,n,b;
	n = arr.size() ;
	i = -1;
	for(b=n;b>=1;b/=2)
		while(i+b<n && arr[i+b]<=key) i+=b ;
//	if(i+1<=n-1&&i+1>=0)
//		return arr[i+1] ;
	return i+1 ;
}

int main()
{
//	crap;
	ll i,j,k,n;
	cin >> n ;
	vector <ll> arr(n) ;
	f(i,0,n)
		cin >> arr[i] ;
	sort(all(arr)) ;
	ll q;
	cin >> q;
	cout << "ENTER THE ELEMENT TO LOOK FOR\n" ;
	while(q--)
	{
		cin >> j;
		cout << bin_search(arr,j) sp << low_bound(arr,j) sp << upp_bound(arr,j) endl ;
	}
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
