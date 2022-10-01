#include<bits/stdc++.h>

using namespace std;

int main(){

    int s=0;
    int d=0;
    int n,a,b;
    int val=0;
    cin>>n;
  int x;
    vector<int> vec;
    for(int i=0;i<n;i++)
      {
        cin>>x;
        vec.push_back(x);
        }
    vector<int>::iterator it = vec.begin();
    vector<int>::iterator er = vec.end()-1; 
  //a =1;b=2;
    for(int i=0;i<n;i++){
         a = *it;
       b = *er;
    //    cout<<"I: "<<i<<endl;
    //    cout<<"A: "<<a<<endl;
    //    cout<<"B "<<b<<endl;
         val = max(a,b);
         //cout<<"Val: "<<val<<endl;
         if(val == a)
          it++;
         else 
          er--; 
        //  cout<<"After first if:\nIt = "<<*it<<"\nEr = "<<*er<<endl; 
        //  cout<<"Value of I mod 0: "<<(i%0)<<endl;
        if(i%2 == 0){
            s +=val;
        } 
        else
          d +=val; 
       // cout<<"After second if: \nS= "<<s<<"\nD="<<d<<endl;  
    } 
    cout<<s<<" "<<d;



    return 0;
}
