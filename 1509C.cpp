#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
// using namespace __gnu_pbds;
 
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// A.order_of_key() *A.find_by_order()
#define endl "\n"
#define int long long
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define in(v) for(int i = 0; i<v.size(); i++) cin>>v[i];
#define out(v) for(int i = 0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
#define popcount(num) __builtin_popcount(num)
typedef vector<int> vi;
typedef pair<int,int> pii;
const int INF = 1e18;
const int MOD = 998244353;
const int MAX_A = 2e6;
const int N = 1e5;
const int LN = 20;

void solve(){
    int n;
    cin >> n;
    vi v(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
    }

    sort(all(v));
    
    // lets start at some element
    // call the pointers l = i, r = i
    // each time you can expand to the left or to the right
    // after expanding you add v[r] - v[l] to your answer
    // after n - 1 expands, you will have l = 1, r = n
    // now realize the fact that if l, r = (1, n)
    // what do you wish previous state was?
    // (2, n) or (1, n - 1)
    // if you do something like

    // [1, i) and (i, n], like removing a element not in ends
    // it wil not help us man, max - min still remains v[n] - v[1]
    
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for(int len = 2; len <= n; ++len){
        for(int l = 1; l + len - 1 <= n; ++l){
            int r = l + len - 1;
            // formed after expanding to left
            dp[l][r] = dp[l + 1][r] + (n - len + 1) * (v[l + 1] - v[l]); 
            // expand to right
            dp[l][r] = min(dp[l][r], dp[l][r - 1] + (n - len + 1) * (v[r] - v[r - 1])); 
        }
    }    

    cout << dp[1][n] << endl;
}  


int32_t main() {   
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    int t = 1; 
    // cin >> t;
    for(int i = 1; i<=t; i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}