#include<bits/stdc++.h>
#define debi cerr<<"Hey sparky\n"
#define pb push_back
#define ll long long 
using namespace std;

int main(){
	/*
	*it is converting a number into its binary representation 
	int a;
	cin >> a;
	int max_bits = (int)log2(a);
	for(int i = max_bits ; i >=0;--i){
		if(a&(1ll<<i))
			cout<<1;
		else
			cout<<0;
	}*/
	
	//iterating over all subets in complexity -> o(2^n * n)
	int n;
	cin >> n;
	vector<int> v;
	for(int i =0 ; i<n;i++){
		int temp;
		cin >>temp;
		v.pb(temp);
	}
	for(int mask = 0;mask < (1<<n) ;++mask){
		for(int i =0 ; i<n;i++){
			if((1<<i)& mask){
				cout<<v[i]<<" ";
			}
		}
		cout<<"\n";
	}
	debi;
	return 0;
}
