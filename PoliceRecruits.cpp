#include<bits/stdc++.h>

using namespace std;
int main(){
   int n;
   cin>>n;
   int arr[n];
   int c=0;
   int p=0;
   for(int i=0;i<n;i++){
       cin>>arr[i];
       if(arr[i] < 0)
       {
           if(p == 0)
            c += abs(arr[i]);
           else
            p -= abs(arr[i]); 
       }
       else{
           p += arr[i];
       }
       cout<<c;
   }




    return 0;
}
