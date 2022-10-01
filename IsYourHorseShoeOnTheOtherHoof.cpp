#include<bits/stdc++.h>

using namespace std;
int main(){
   int a;
   unordered_map<int,int>mp;
   unordered_map<int,int>::iterator itr;
   for(int i=0;i<4;i++)
   {
       cin>>a;
       if(mp.find(a) == mp.end()){
           mp.insert({a,1});
       }
       else
         mp[a]++;
   }
   int count =0;
   for(auto itr = mp.begin();itr != mp.end(); itr++){
       if(itr->second > 1){
           count += itr->second -1;
       }
   }
   cout<<count;




    return 0;
}