//sqrt decomposition(sum queries)
#include <bits/stdc++.h> 
#include<cmath>
#define pb push_back
#define ll long long
#define ull unsigned long long
#define deb(x) cerr<<#x<<" "<<x<<"\n"

using namespace std;
int n;
vector<int> b;
vector<int> a;
int len;

// query ranges are form 0 to n-1
int solve(int l, int r){
	int sum =0 ;
	for(int i = l ; i<=r ;){
		if(i%len == 0 && i+len-1 <=r){
			sum += b[i/len];
			i += len;
		}
		else{
			sum += a[i];
			++i;
		}
			
	}
	return sum;
}
//another way to anwer queries but it is more efficient this way as we are not doing so many divisions
int solve2(int l , int r){
	int c_l = l/len;
	int c_r = r/len;
	int ans = 0;
	if(c_l == c_r){
		for(int i= l;i<=r;i++){
			ans += a[i];
		}
	}
	else{
		
		for(int i = l,end = (c_l+1)*len-1;i<=end;i++){
			ans += a[i];
		}
		for(int i= c_l+1;i<=c_r-1;++i){
			ans += b[i];
		}
		for(int i=c_r*len;i<=r;++i){
			ans += a[i];
		}
	}
	return ans;
}

int main(){
	//fast;
	cin >> n;
	//plus 1 is important by the fact that sqrt(9) - > 3 and sqrt(15) -> 3 as it will be turncated so we need to store one additional element in each block more than sqrt(n)
	len = (int)sqrt(n+.0)+1;
	deb(len);
	b.resize(len);
	a.resize(n);
	for(int i =0 ; i<n;i++){
		cin >> a[i];
	}
	for(int i = 0 ; i< n;i++){
		b[i/len] += a[i];
	}
	
	//to check it looks
	// it generally contains property of blocks of size sqrt(n) 0 to s-1 i.e s=(sqrt(n))
	// the last block may contain fewer elements
	for(int i =0 ; i < len;i++){
		deb(b[i]);
	}
	
	//anwering queries
	int query;
	cin >> query;
	while(query -- ){
		int l , r;
		cin >> l >> r;
		cout<<solve2(l,r)<<"\n";	
	}
	
	return 0;
}

	
