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


// for 1 and p, we run djikistra for each nodes
// and for any common nodes we can just take sum of distances to reach to that node
// but it is n^2logn - heavy computation

// for a vertex once we start taking reversed edges there is no going back
// maintain a pair (u, x). u = node, x = node in normal graph or reversed graph
// for each edge in the graph
// connect (u, 0) -> (v, 0) same weight
// connect (v, 1) -> (u, 1) same weight
// connect each node (u, 0) -> (v, 0) with weight 0
// since there is no edge of type (u, 1) -> (x, 0)
// it can not come back if once it takes the path
// the graph has (n + 2m) edges and we need one djikistra from (1, 0) to (p, 1)


void solve(){
    int n, m;
    cin >> n >> m;
    vector<pii> adj[2*n + 1];
    for(int i = 0; i < m; ++i){
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].pb({y, w}); // normal
        adj[y + n].pb({x + n, w}); // reversed graph as u + n as node rep
    }

    for(int i = 1; i <= n; ++i){
        adj[i].pb({i + n, 0});
    }


    vi d(2*n + 1, INF);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0, 1});
    d[1] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        int val = pq.top().first;
        pq.pop();

        if(d[u] != val) continue;

        for(auto v: adj[u]){
            if(d[v.first] > d[u] + v.second){
                d[v.first] = d[u] + v.second;
                pq.push({d[v.first], v.first});
            }
        }
    }

    for(int i = 2; i <= n; ++i){
        if(d[i + n] == INF){
            cout<<"-1 ";
        }
        else{
            cout<<d[i + n]<<" ";
        }
    }
    cout<<endl;
                                                                 

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
 
