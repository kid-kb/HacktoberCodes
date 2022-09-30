//*********//
//kidddd kB//
//*********//
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<cwctype>
#include<cmath>
#include<map>
#include<cwchar>
#include<climits>
#include<unordered_map>
#include<cstring>
#include<iomanip>
#include<deque>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long int
#define lower(str) transform(str.begin(),str.end(),str.begin(),::tolower);
#define upper(str) transform(str.begin(),str.end(),str.begin(),::toupper);
#define mod 1000000007
#define SORT(vec) sort(vec.begin(),vec.end());
#define pb push_back
#define csb __builtin_popcount
#define msb(n) (ll)(log2(n))
#define kb ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define print(arr) for(auto i:arr)cout<<i<<" ";
#define print2(vec) for(auto i:vec){for(auto j: i){cout<<j<<" ";}cout<<endl;}
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

int dp[50][50]={0};
int lcs(string a,string b,int i,int j)
{
    if(i>=a.length() || j>=b.length())
        return 0;
    
    if(dp[i][j]!=0)
        return dp[i][j];
    
    if(a[i]==b[j])
        dp[i][j]=1+lcs(a,b,i+1,j+1);
    else
    {
        dp[i][j]=max(lcs(a,b,i,j+1),lcs(a,b,i+1,j));
    }
    return dp[i][j];
}
int main()
{
    string a,b;
    cin>>a>>b;
    
    cout<<lcs(a,b,0,0);
    return 0;
}


// No of way
