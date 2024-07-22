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
const int MOD = 998244353;
const int N = 2e5;
const int LN = 20;


//lets take a smaller i such as 1 (there is proof why if you cannot start with 1, you can never construct graph - some lines below)
//to form edge with 1 and j
//a1 + aj >= c * j
//a1 >= c*j - aj
//we can sort A in this order(ascending)
//and start forming edges 
//now in this component all nodes with have same Ai (when forming edge consider sum of ais in compoent)
//so we will still consider 1 to contruct edges
//now if sum + a[j] < c*j
//all the next elements will also have he same condition
//if we werent able to form edge with (1, j1) => (a1 + aj1 < c * j1)
//if we werent able to form edge with (1, j2) => (a1 + aj2 < c * j2)
//using the above two equations => (aj1 + aj2 < c * (j1 + j2) - 2a1)
//to form edge between (j1, j2) => (aj1 + aj2 >= c * j1 * j2)
//using above condition => (c * (j1 + j2) - 2a1 > c * j1 * j2)
//but it is a known fact that j1 != 1 and j2 != 1 then (c * j1 * j2 >= c * (j1 + j2) )
//which proves us that we can never actually fullfill the requiremen to form edges between any
//two j1, j2 in the set which cant form edges with 1.

void solve(){
    int n, c;
    cin >> n >> c;

    vi a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    vi p(n + 1);
    iota(all(p), 0);

    sort(p.begin() + 1, p.end(), [&](int i, int j){
        return c * i - a[i] < c * j - a[j];
    });

    int sum = a[1];
    for(int i = 1; i <= n; ++i){
        if(p[i] == 1) continue;
        if(sum + a[p[i]] < c * p[i]){
            cout<<"No"<<endl;
            return;
        }
        sum += a[p[i]];
    }

    cout<<"Yes"<<endl;

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
 
