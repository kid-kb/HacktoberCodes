// Code for regular Segment Tree to find the range sum and point updates.
// The description of each operation is as follows:
//  ->    1 i v: set the element with index i to v.
//  ->    2 l r: calculate the sum of elements with indices from l to r−1 (0≤l<r≤n).

#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define pb push_back
ll n,m;
vector<ll> ar,seg;
void build(ll pos,ll low,ll high)
{	if(low==high)
	{	seg[pos]=ar[low];
		return ;
	}
	ll mid=(low+high)/2;
	build(2*pos+1,low,mid);
	build(2*pos+2,mid+1,high);
	seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}
void update(ll pos,ll low,ll high,ll id,ll val)
{	if(low==high)
	{	seg[pos]=val;
		return ;
	}
	ll mid=(low+high)/2;
	if(id<=mid)	update(2*pos+1,low,mid,id,val);
	else	update(2*pos+2,mid+1,high,id,val);
	seg[pos]=seg[2*pos+1]+seg[2*pos+2];	
}
ll query(ll pos,ll low,ll high,ll st,ll end)
{	if(high<st || low>end)	return 0LL;
	if(low>=st && high<=end)	return seg[pos];
	ll mid,s1,s2;
	mid=(low+high)/2;
	s1=query(2*pos+1,low,mid,st,end);
	s2=query(2*pos+2,mid+1,high,st,end);
	return s1+s2;
}
int main()
{	cin>>n>>m;
	ar.resize(n);   // assining size of input array. 
	seg.resize(4*(n+5),0);  // assigning size of seg tree array.
	for(ll i=0;i<n;i++)	cin>>ar[i]; // input array initial elements/
	ll type,a,b;
	build(0,0,n-1); // building the initial segment tree.
	while(m--)
	{	cin>>type>>a>>b;
		if(type==1)		update(0,0,n-1,a,b);    // Point Update
		else	cout<<query(0,0,n-1,a,b-1)<<endl;   // Range Sum query
	}
}