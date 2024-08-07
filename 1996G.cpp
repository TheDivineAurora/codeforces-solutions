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


// if i fix which edge to remove
// then the removal of remaining edges in each case becomes trivial

// how?
// for all intervals enveloping us they should be connected by path through nth edge
// and ones which are not enveloping us cannot take path through nth edge
// they will be directly connected , ie for interval (a, b) just take all edges a, a + 1 ... b - 1

// we can maintain intervals starting l <= i and ending i + 1 <= r
// using two pointers 

// and we can deal with not enveloping case using prefix sums..

vi adj[N + 10], radj[N + 10], pos[N + 10];

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; ++i){
        adj[i].clear();
        radj[i].clear();
    }

    for(int i = 0; i <= m; ++i){
        pos[i].clear();
    }

    vi pre(n + 1);
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);

        adj[x].pb(y);
        radj[y].pb(x);

        pre[x]++;
        pre[y]--;
    }

    for(int i = 1; i <= n; ++i){
        pre[i] += pre[i - 1];   // no of intervals covering ith edge
        pos[pre[i]].pb(i);
    }

    multiset<int> lt, rt;
    int ans = n;

    for(int i = 1; i <= n; ++i){
        // adding intervals starting at i
        for(auto x : adj[i]){
            rt.insert(x);
            lt.insert(i);
        }

        //removing intervals ending at i
        for(auto x : radj[i]){
            if(lt.find(x) != lt.end()) lt.erase(lt.find(x));
            if(rt.find(i) != rt.end()) rt.erase(rt.find(i));
        }

        int l = 1, r = n + 1;

        if(!lt.empty()) l = *lt.rbegin();
        if(!rt.empty()) r = *rt.begin();

        int cnt = pre[i]; // no of intervals covering ith edge

        // // now we want no of edges which are coverered by only 'cnt'
        // // no of intervals or edges with sum = cnt
        // // because they get reduced to zero after removal of intervals
        int idx1 = lower_bound(pos[pre[i]].begin(), pos[pre[i]].end(), l) - pos[pre[i]].begin();
        int idx2 = upper_bound(pos[pre[i]].begin(), pos[pre[i]].end(), r - 1) - pos[pre[i]].begin();

        ans = min(ans, n - (idx2 - idx1));
    }

    cout<<ans<<endl;

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
 
