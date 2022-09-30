//------ © daxkofficial™ ------//
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;

 
#define ll long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define srt(x) sort((x).begin(), (x).end());
#define clr(x) memset(x, 0, sizeof(x));
#define mem(a,val) memset(a,val,sizeof(a));
#define trace(x) for(auto it:x) cout<<it<<' '; cout<<"\n";
#define sumv(x, w) for(auto it:x) w+=it;
#define traca(A, n) for(ll i=0; i<n; i++) cout<<A[i]<<' '; cout<<"\n";
#define pll pair<ll,ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vb vector<bool>
#define vc vector<char>
#define vpll vector<pll>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define cy cout<<"YES"<<"\n";
#define cn cout<<"NO"<<"\n";
#define nl cout<<"\n";
#define chk cout<<"*\n";

template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*-----------------------------Modular Arithmetic---------------------*/
inline ll add(ll x,ll y,ll mod){x+=y; if(x>=mod) return x-mod; return x;}
inline ll sub(ll x,ll y,ll mod){x-=y; if(x<0) return x+mod; return x;}
inline ll mul(ll x,ll y,ll mod){return (x*1ll*y)%mod;}
inline ll power(ll x,ll y,ll mod){ll ans=1; while(y){if(y&1) ans=mul(ans,x,mod); x=mul(x,x,mod); y>>=1;} return ans;}
inline ll inv(ll x,ll mod){return power(x,mod-2,mod);}
 
 
 
/*------------------------ Important Functions ----------------------------*/
 
ll gcd(ll a , ll b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
 
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
 
ll min(ll x, ll y, ll z) 
{ 
    return min(min(x, y), z); 
} 
 
ll max(ll x, ll y, ll z) 
{ 
    return max(max(x, y), z); 
} 
 
/*------------------------ Few More Functions ----------------------------*/
 
 
 
ll fastpower(ll n, ll p, ll m)
{
    if(p==0)
    return 1;
 
    ll t=fastpower(n, p/2, m);
    ll ans=(t*t)%m;
 
    if(p%2!=0)
    {
        ans=(ans* n%m)%m;
    }
    return ans;
}
 
 
 
ll factmod(ll n, ll p) {
    ll res = 1;
    while (n > 1) {
        res = (res * ((n/p) % 2 ?  p-1 : 1)) % p;
        for (ll i = 2; i <= n%p; ++i)
            res = (res * i) % p;
        n /= p;
    }
    return res % p;
}
 
ll largestPower(ll n, ll p) 
{ 
    ll x = 0; 
      while (n) { 
        n /= p; 
        x += n; 
    } 
    return x; 
} 
  
ll modFact(ll n, ll p) 
{ 
    if (n >= p) 
        return 0; 
    ll res = 1; 
    bool isPrime[n + 1]; 
    memset(isPrime, 1, sizeof(isPrime)); 
    for (ll i = 2; i * i <= n; i++) { 
        if (isPrime[i]) { 
            for (ll j = 2 * i; j <= n; j += i) 
                isPrime[j] = 0; 
        } 
    } 
      for (ll i = 2; i <= n; i++) { 
        if (isPrime[i]) { 
            ll k = largestPower(n, i); 
              res = (res * power(i, k, p)) % p; 
        } 
    } 
    return res; 
}
 
 
 
 
/*------------------------ Trouble begins here ----------------------------*/
 
unsigned long long power(unsigned long long x, 
                         ll y, ll p) 
{ 
    unsigned long long res = 1; // Initialize result 
  
    x = x % p; // Update x if it is more than or 
    // equal to p 
  
    while (y > 0) { 
        if (y & 1) 
            res = (res * x) % p; 
  
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % p; 
    } 
    return res; 
} 
unsigned long long modInverse(unsigned long long n, int p) 
{ 
    return power(n, p - 2, p); 
} 
unsigned long long nCrModPFermat(long long n, ll r, ll p) 
{ 
    if(r>n)
    return 0;
    // Base case 
    if (r == 0) 
        return 1; 
    unsigned long long fac[n + 1]; 
    fac[0] = 1; 
    for (int i = 1; i <= n; i++) 
        fac[i] = (fac[i - 1] * i) % p; 
  
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
}
 
// unordered_set<ll> prime;
// void sieve(ll n)
// {    bool bakh[n+1];memset(bakh, true, sizeof(bakh));
//     for (ll p=2; p*p<=n; p++)
//     {    if (bakh[p] == true)
//         {    for (ll i=p*p; i<=n; i += p)    bakh[i] = false; } }
//       for (ll p=2; p<=n; p++)    if (bakh[p])
//           prime.insert(p);
// }
 
 
// vector<ll> fact;
// const ll N = 200001;
// ll ans[N];
 
 
 



void solve()
{
    ll n, i, j;
    cin>>n;
    
    
    nl

    return;
}
 
 
 
int main()
{
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
    fastio
 
    // SieveOfEratosthenes(1e6);
 
    // sieve(101);
    // trace(prime)
 
    ll tc=1, ttt=0;
    cin>>tc;
    
    // trace(Z)

    // ll mod = 1e9+7;
    // fact.clear();
    // fact.resize(300001, 1);
    // for(int i=2; i<=300000; i++)
    // {
    //     fact[i]=fact[i-1]*i;
    //     fact[i]%=mod;
    // }
    // trace(fact)
 
    // for(int i=2; i<=1e6; i++)
    // {
    //     if(prime[i])
    //     P.push_back(i);
    // }
    while(tc--)
    {
        // ttt++;
        // cout<<"Case #"<<ttt<<": ";
        //chk
        
        solve();
    }
 
    return 0;
}
/*          
            
                            ❤️❤️❤️❤️❤️❤️❤️❤️❤️          
 
                                ♥  ♥       ♥  ♥
                               ♥     ♥   ♥     ♥
                               ♥       ♥       ♥
                                ♥             ♥
                                 ♥           ♥
                                   ♥       ♥
                                     ♥   ♥
                                       ♥
 
 
*/