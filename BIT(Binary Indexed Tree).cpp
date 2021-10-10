#include<bits/stdc++.h>
#define ull unsigned long long
#define ll int64_t 
#define f(i,s,e) for(i=s;i<e;++i)
#define endl << "\n"
#define sp << " "
#define INF INFINITY
#define mset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI acos(-1) 
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define CY cout << "YES\n"
#define CN cout << "NO\n"
#define print(x) for(auto it:x) cout<<it<<' '; cout<<"\n";
#define DECIMAL cout<<setiosflags(ios::fixed)<<setiosflags(ios::showpoint);

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

class BIT{
    public:
        vector<int>tree;
        int n;
        BIT(){;}
        BIT(vector<int>arr){
            int i;
            n = arr.size();
            tree.resize(n+1); // 1-based indexing for tree
            tree[0] = 0;
            for(i=1;i<=n;i++)
                tree[i] = 0;
            for(i=0;i<n;i++)
                add(i+1,arr[i]); // constructs BIT
        }
        // Following function updates the whole tree, where update is of type 
        // increment kth index in array by x
        void add(int k, int x){
            while (k <= n){
                tree[k] += x;
                k += k&-k;
            }
        }
        // Following function finds the sum in the range of [1,k]
        int sum(int k){
            int s = 0;
            while (k >= 1){
                s += tree[k];
                k -= k&-k;
            }
            return s;
        }
        int query(int l,int r){
            return sum(r) - sum(l-1);
        }
};

int main()
{
    FAST_IO ;
    int i,j,k,n;
    cin >> n;
    vector<int>arr(n);
    f(i,0,n)
        cin >> arr[i];
    BIT b1(arr);
    int q;
    cin >> q;
    while(q--){
        cin >> i >> j >> k;
        if(i==1){
            b1.add(j,k-arr[j-1]);
            arr[j-1] = k;
        } // update query
        else
            cout << b1.query(j,k) sp;
    }
    cout endl;
    return 0;
}

/*
If u haven't come up with an approach yet ,skip this one
  Try this when feeling stuck -
  1. Int overflow, array bounds
  2. Special cases (n=1?)
  3. Prove your approach to yourself(mathematical induction,counter-intuitive or stronger test cases)
  4. Calm down and don't look at standings and stop thinking about rating and think about the question
  5. Just do it! 
*/ 

//Benq's advice - 
/* 
    And following advices are must for me -
    * do something instead of nothing and stay organized
    * WRITE STUFF DOWN 
*/

//#define _GLIBCXX_DEBUG 
// It will convert WA verdict to runtime error if that error is caused due to out of bound excess , declare it at the top
//#pragma GCC optimize "trapv" 
// It will convert WA to runtime error if WA was caused due to int overflow error,declare it anywhere
