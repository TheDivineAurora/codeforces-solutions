#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
 
using namespace std;
// using namespace __gnu_pbds;
 
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//A.order_of_key() *A.find_by_order()
#define endl "\n"
#define int long long
#define ld long double
#define pb push_back
#define rep(i,a,b) for(int i = a; i < b; i++)
#define all(x) x.begin(),x.end()
#define in(v) for(int i = 0; i<v.size(); i++) cin>>v[i];
#define out(v) for(int i = 0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
#define ret(v) cout<<v<<"\n"; return
#define popcount(num) __builtin_popcount(num)
typedef vector<int> vi;
typedef pair<int,int> pii;
const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e5;
const int LN = 20;


void solve(){
    int n;
    cin >> n;
    vi a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    // first of all if a[i] > 4
    // we can use 1 op to get rid of it
    // if not we want the upper and lower guys to share with us
    // that would mean one of the upper and lower guys have to be >2 and >4
    // instead of 3 2x2 blocks
    // we can simply use 3 ops to deal with 3 indiviual rows
    // understand that upper bound for ops in n rows is n
    int ans = 0;

    // whats the plan for a[i] < 4 ?
    // make cases for <=2 and > 2
    vi dp1(n + 1); // answer if we consider a[i] <= 2 regardless of what it is, if it is >2 
    // it wil be contributed by blocks lower than it
    vi dp(n + 1); // final answer
    for(int i = 1; i <= n; ++i){
        dp[i] = dp[i - 1] + (a[i] > 0);
        if(a[i] == 0 || a[i] > 4) {
            dp1[i] = INF;   // im getting a row operation sir, i wont have a allocation for you
            continue;
        }
        
        if(a[i - 1] > 4 || a[i - 1] == 0){
            dp1[i] = INF;   // if previously row operation, then dont put a 2x2 block on me
            continue;
        }

        if(a[i] <= 2 && a[i - 1] <= 2){ // simple
            dp[i] = min(dp[i], 1 + dp[i - 2]);
            dp1[i] = 1 + dp[i - 2];
        }
        if(a[i] <= 2 && a[i - 1] > 2){  // we use dp1 information of i - 2 and adjust 2 blocks [2 4 4 2] case
            dp[i] = min(dp[i], 2 + dp1[i - 2]);
            dp1[i] = 2 + dp1[i - 2];
        }
        if(a[i] > 2 && a[i - 1] <= 2){
            dp1[i] = 1 + dp[i - 2]; // clearly just do a row ops on me
        }
        if(a[i] > 2 && a[i - 1] > 2){
            dp[i] = min(dp[i], 2 + dp[i - 2]);
            dp1[i] = 2 + dp1[i - 2];   
        }
    }

    cout<<dp[n]<<endl;
}
 
int32_t main() {   
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    int t = 1; 
    cin>>t;
    for(int i = 1; i<=t; i++){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 
