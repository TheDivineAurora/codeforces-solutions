#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// A.order_of_key() *A.find_by_order()
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
 
// bs? 
// we can fix x and binary search for y
// because if k subarrays are found in [x, y] defo we can find in [x, y + 1]
// n^2.logn tho
//
// consider a case with elements in range [x, y] = 1 and outside range = -1
// now if the sum of the whole array >= k , i claim we can find k subarrays

// why?
// if sum = k at i = n , and sum = k - 1 at j
// that would mean subarray (j + 1, n) had sum = 1 means [x, y] is in majority
// we can repeat such construction k times because we have k'1s. 


// construction?


void solve(){
    int n, k;
    cin >> n >> k;
    vi v(n);
    in(v);

    vi pre(n + 1);
    for(auto x : v){
        pre[x]++;
    }

    for(int i = 1; i <= n; ++i){
        pre[i] += pre[i - 1];
    }

    int ax = 1, ay = INF;
    int mi = *min_element(all(v)), mx = *max_element(all(v));

    for(int x = mi; x <= mx; ++x){
        int l = x, r = mx; // y >= x

        int y = -1;
        while(l <= r){
            int mid = (l + r)/2;
            // bsing for [x, mid]
            if(2*(pre[mid] - pre[x - 1]) - n >= k){
                y = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        if(x <= y && (y - x) < (ay - ax)){
            ax = x, ay = y;
        }
    }

    vector<vector<int>> ans;
    int sum = 0, l = 0, rem = k;

    for(int i = 0; i < n; ++i){
        if(rem == 1){
            ans.pb({l, n - 1});
            break;
        }

        if(ax <= v[i] && v[i] <= ay){
            sum++;
        }
        else{
            sum--;
        }

        if(sum > 0){
            ans.pb({l, i});
            l = i + 1;
            sum = 0;
            rem--;
        }
    }

    cout<<ax<<" "<<ay<<endl;
    for(int i = 0; i < ans.size(); ++i){
        cout<<ans[i][0] + 1 << " " << ans[i][1] + 1 <<"\n";
    }
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
