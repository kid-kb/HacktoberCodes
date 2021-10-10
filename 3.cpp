#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
class compare{
    public:
    bool operator()(vector<ll> a, vector<ll> b){
        if(a[1]<=1)
        return true;
        if(b[1]<=1)
        return false;
        return true;
    }
};

int main(){
    
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
   int t,t1=1;
   cin>>t;
   while(t--){
       
       ll n, m;
       cin>>n>>m;
       vector<ll> a(m), ans(m,0);
       unordered_map<ll,priority_queue<vector<ll>,vector<vector<ll>>,compare>> ma;
       for(int i=0;i<m;++i)
       cin>>a[i],ma[a[i]].push({i,ans[i]});
       
       for(int i=0;i<n;++i){
           unordered_map<ll,priority_queue<vector<ll>,vector<vector<ll>>,compare>> mp;
           vector<ll> x(m),y(m,0);
           set<ll> s;
           for(int j=0;j<m;++j)
           s.insert(j);
           
           for(int j=0;j<m;++j){
               cin>>x[j];
               if(ma[x[j]].size()!=0){
                   mp[x[j]].push(ma[x[j]].top());
                   vector<ll> vec=ma[x[j]].top();
                   s.erase(vec[0]);
                   y[vec[0]]=1;
                   ma[x[j]].pop();
               }
           }
           for(int j=0;j<m;++j){
               if(y[j]==0){
                   ll val=*s.begin();
                   mp[x[j]].push({val,++ans[val]});
                   s.erase(val);
               }
           }
           ma=mp;
       }
       
       ll Ans=0;
       for(int i=0;i<m;++i){
        //    cout<<ans[i]<<" ";
           if(ans[i]>1ll)
           Ans+=ans[i]-1ll;
       }
       
       cout<<"Case #"<<t1++<<": "<<Ans<<endl;
   }
   
   return 0;
}