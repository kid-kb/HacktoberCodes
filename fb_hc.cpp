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
    string s;
    cin>>s;
    ll q;
    unordered_map<int,vector<int> >mp;
    vector<int>v(26,0);
    mp[-1]=v;
    rep(i,0,s.length()){
        v[s[i]-'a']++;
        mp[i]=v;
    }
    ll ans=0;
    cin>>q;
    rep(j,0,q){
        ll l,r;
        cin>>l>>r;
        l--;r--;
        if((r-l)&1)continue;
        vector<ll>temp;
        int ct=0;
        for(int i=0;i<26;i++){
            temp.push_back(mp[r][i]-mp[l-1][i]);
            if(temp[i]&1)ct++;
        }
        if(ct==1){
            for(int i=0;i<26;i++)if(temp[i]&1)temp[i]--;

            int f1=1,f2=1,x=(r-l)/2;
            vector<int>t1,t2;
            for(int i=0;i<26;i++){
                t1.push_back(mp[l+x-1][i]-mp[l-1][i]);
            }
            for(int i=0;i<26;i++){
                t2.push_back(mp[r][i]-mp[r-x][i]);
            }

            for(int i=0;i<26;i++){
                if(t1[i]!=temp[i]/2)f1=0;
                if(t2[i]!=temp[i]/2)f2=0;
            }

            if(f1 or f2){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}


void update(ll i,ll inc,vector <ll>& BIT) //inc is the value to be added
{
    while(i<BIT.size())
    {
        BIT[i] += inc ;
        i += (i&-i) ;
    }
}
ll query(ll ind,vector <ll>& BIT)
{
    ll sum = 0;
    while(ind>=1)
    {
        sum += BIT[ind] ;
        ind -= (ind&-ind) ;
    }
    return sum ;
}

void solve2(){
    cout<<"C";
    int n;
    cin>>n;
    int arr[n];
    vector <ll> BIT(n+1,0) ;
    cout<<"B";
    rep(i,0,n){
        cin>>arr[i];
        update(i,arr[i],BIT);
    }
    cout<<"A";
    ll q;
    cin >> q;
    while(q--)
    {
        // char z ;
        // cin >> z;
        ll x,y,z;
        cin >>z >> x >> y;
        if(z==2)
        {
            update(x,y-arr[x],BIT) ;
            arr[x] = y ;
        }
        else
            cout << query(y,BIT) - query(x,BIT) + arr[x] <<endl ;
    }
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
    cout<<"A";

    // rep(i,1,tc+1){
    //     cout<<"Case #"<<i<<": ";
    //     solve2();
    //     // nl
    // }
//    printf("Time Taken  %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}