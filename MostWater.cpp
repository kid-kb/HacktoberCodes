#include<bits/stdc++.h>
using namespace std;

int most_water(int arr[],int n){
    int m=0;
    int i=0,j=n-1;
    while(i<j){
        m=max(m,(j-i)*min(arr[i],arr[j]));
        (arr[i]<arr[j])?i++:j--;
    }
    return m;
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cout<<most_water(arr,n)<<endl;
	}
	return 
