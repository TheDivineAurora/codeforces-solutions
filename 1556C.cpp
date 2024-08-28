#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
 
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
const int MOD = 1e9 + 7;
const int MAX_A = 2e6;
const int N = 2e5;
const int LN = 20;


// al
void solve(){
    int n;
    cin >> n;
    vi v(n);
    in(v);

    int ans = 0;
    // n^2 allowed, start segment at each even i, and check for all j > i
    for(int i = 0; i < n; i += 2){
        // now ith segment only has open brackets call it prefix
        // for the segment [i + 1, j], call it suffix
        // find what is net closed brackets for each j and it happens to be some ranges
        // if there are extra closed brackets, we can cater them using open brackets from prefix
        // for a suffix if we use x open brackets from prefix, you cannot use lesser for further suffixes
        int lb = 1, ub = v[i]; // allowed
        // how to find extra closed brackets?
        // represent closed brackets with +1 and open with -1
        // now each time sum > 0 there is a demand
        // and max catering demand for prefx is v[i]
        int sum = 0;
        for(int j = i + 1; j < n; ++j){
            int new_sum = sum + v[j] * (j & 1 ? 1 : -1);
            // the demand of closed brackets if u include j
            // is (sum, new_sum]
            // just find intersection with allowed 
            if(new_sum >= sum){
                // i cannot cater any less closed brackets. but higher or equal = yes
                int sxl = max(lb, sum + 1);
                int sxr = min(ub, new_sum);
                if(sxl <= sxr){
                    ans += sxr - sxl + 1;
                }
                lb = max(lb, new_sum); // fixing lower bound each time a higher amount of 
                // closed brackets are asked
            }   
            if(lb > ub) break;
            
            sum = new_sum;
        }
    }

    cout << ans << endl;

    
}

int32_t main() {   
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    int t = 1; 
    // cin>>t;
    for(int i = 1; i<=t; i++){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 