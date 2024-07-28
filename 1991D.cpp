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

// there is no scope of ideas in implementation
// so the only scope is graph building or coloring. and generalizing.
// lets build graph in (i, j) i < j manner for each j
// all primes are odd except 2
// to get odd primes, a number x has to be xor'ed with opposite parity numbers and some of those
// will give us odd primes
// to get the result prime as 2, only possible case is x and x - 2. 
// since lower bound is already 4 and x and x - 4 dont have an edge
// keep repeating for each newly added node
// nodes 3,4,5,6 should all have unique colours , is that so?
// 
// the answer for n = 6 is 4
// so lower bound is already 4 for n >= 6
// 

vi ans = {1,2,2,3,3};
void solve(){
    int n;
    cin >> n;
    if(n <= 5){
        cout<<1 + n/2<<endl;
        for(int i = 0; i < n; ++i){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    cout<<"4"<<endl;
    for(int i = 1; i <= n; ++i){
        cout<<(i - 1) % 4 + 1<<" ";
    }
    cout<<endl;
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
 