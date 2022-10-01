#include<bits/stdc++.h>

using namespace std;
int main(){
    int a,b,c,d;
  vector<int>vec;
  cin>>a>>b>>c>>d;
  vec.push_back(a);
  vec.push_back(b);
  vec.push_back(c);
  vec.push_back(d);
  string x;
  int rem;
  cin>>x;
  map<int,int>mp;
  for(int i=0;i<x.length();i++)
  {
    rem = x[i] - '0';
    if(mp.find(rem) == mp.end())
       {
           mp.insert({rem,1});
       }
    else
        mp[rem]++;

  }
  // while(x > 0)
  // {
  //      rem = x%10;
  //      x /= 10;
  //      if(mp.find(rem) == mp.end())
  //      {
  //          mp.insert({rem,1});
  //      }
  //      else
  //       mp[rem]++;
  // }
  int sum=0;
  int i=0;
  map<int,int>::iterator itr = mp.find(1);
 
  if(itr != mp.end())
    {
      sum += (itr->second)*(vec[0]);
      //cout<<"val of 1: "<<itr->second<<" .Val of vec0: "<<vec[0]<<endl<<" .sum="<<sum<<endl;
    }  
  itr = mp.find(2);
  if(itr != mp.end())
   {
     sum += (itr->second)*(vec[1]);
     //cout<<"val of 1: "<<itr->second<<" .Val of vec1: "<<vec[1]<<endl<<" .sum="<<sum<<endl;
   } 
  itr = mp.find(3);
  if(itr != mp.end())
    {
      sum += (itr->second)*(vec[2]);
      //cout<<"val of 2: "<<itr->second<<" .Val of vec2: "<<vec[2]<<endl<<" .sum="<<sum<<endl;
    } 
  itr = mp.find(4);
  if(itr != mp.end())
   {
    sum += (itr->second)*(vec[3]);
     //cout<<"val of 3: "<<itr->second<<" .Val of vec3: "<<vec[3]<<endl<<" .sum="<<sum<<endl;
   } 
   
   cout<<sum;




    return 0;
}
