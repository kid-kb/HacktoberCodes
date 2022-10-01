#include<algorithm>
#include<bitset>
#include<chrono>
#include<climits>
#include<cmath>
#include<cstring>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<unordered_set>
#include<sstream>
#include<stack>
#include<unordered_map>
#include<vector>
#define endl '\n'
#define ll long long
#define ull unsigned long long int
#define lower(str) transform(str.begin(),str.end(),str.begin(),::tolower);
#define upper(str) transform(str.begin(),str.end(),str.begin(),::toupper);
#define mod 1000000007
#define SORT(vec) sort(vec.begin(),vec.end());
#define eb emplace_back
#define pb push_back
#define csb __builtin_popcountll
#define ctz __builtin_ctzll
#define clz __builtin_clz
#define msb(n) (ll)(log2(n)) // 0 based
#define DIG(n) floor(log10(n))+1
#define OM ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define nl cout<<endl;
#define ptr(arr) for(auto i:arr)cout<<i<<" ";nl
#define ptr2(vec) for(auto i:vec){for(auto j: i){cout<<j<<" ";}nl}
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,n,a) for (int i=n;i>=a;i--)
#define mem(a,val) memset(a,val,sizeof(a))
#define INF INT_MAX
#define inf INT_MIN
using namespace std;

// cout<<fixed<<setprecision(10)<<endl;

ll gcd(ll a,ll b) { if (b == 0) return a; return gcd(b, a%b); }

ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}

ll fastpower(ll n,ll p,ll m){ if(p==0) return 1; ll t=fastpower(n,p/2,m); t=(t*t)%m; if(p&1)t=(t*n)%m; return t;}

ll modInverse(ll a, ll m) { return fastpower(a, m-2, m); }

void solve() {
   ll n,k;
   cin>>n;
   vector<pair<ll,ll> >v1,v2;
   ll sum=0,xsum=0,ysum=0;
   rep(i,0,n){
    ll a,b;
    cin>>a>>b;
    sum+=a*a;
    sum%=mod;
    sum+=b*b;
    sum%=mod;
    xsum+=a;
    ysum+=b;
    xsum%=mod;
    ysum%=mod;
    v1.push_back(make_pair(a,b));
   }
   cin>>k;
   rep(i,0,k){
    ll a,b;
    cin>>a>>b;
    v2.push_back(make_pair(a,b));
   }
   ll ans =0;
   for(pair<ll,ll> i:v2){
    // ll x = i.first*i.first*n;
    // x%=mod;
    // ll y = i.second*i.second*n;
    // y%=mod;
    // ll temp = x+y+sum;
    // temp%=mod;
    // cout<<temp<<" ";
    // temp=(temp+mod-((ll)2*i.first*xsum)%mod)%mod;
    // temp=(temp+mod-((ll)2*i.second*ysum)%mod)%mod;
    for(auto j:v1){
        ll temp = (i.second-j.second)*(i.second-j.second) + (i.first-j.first)*(i.first-j.first);
        ans+=temp;
        ans%=mod;
    }
    // cout<<temp<<endl;
   }
   cout<<ans<<endl;

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    OM
    ll tc;
    // tc=1;
    cin>>tc;
//    cin.ignore();
//    clock_t tStart = clock();
    
    rep(i,1,tc+1){
        cout<<"Case #"<<i<<": ";
        solve();
        // nl
    }
//    printf("Time Taken  %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


// a1 b1, a2 b2, a3 b3

// x1 y1, x2 y2, x3 y3



// x1-a1 2 + y1-b1 2 + x1-a2 2 + y1-b2 + x1 a3 y1 b3

// x1^2 + a1^2 -2x1a1 + y1^2+b1^2-2y1b1
// x1^2+ a2^2 -2x1a2 + y1^2+b2^2-2y1b1

// -2x1(a1+a2)


// 2 5


// 2 2...5 5

// 4+4  + 25+4    + 4 + 25 +25+25
// -2.2.2 - 2.5.2 - 2.2.5 -2.5.5



