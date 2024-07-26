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
const int MOD = 998244353;
const int N = 1e5;
const int LN = 20;


void solve(){
    int n, m;
    cin >> n >> m;
    vi a(n);
    in(a);
    for(int i = 1; i < n; ++i){
        if(a[i - 1] % a[i] != 0){
            cout<<"0"<<endl;
            return;
        }
    }

    vector<int> d;

    int c = a[0];
    for(int i = 2; i * i <= c; ++i){
        if(c % i == 0){
            int cnt = 0;
            while(c % i == 0){
                c /= i;
                cnt++;
            }
            d.pb(i);
        }
    }
    if(c != 1) d.pb(c);

    vi b(n);
    b[0] = 1;
    for(int i = 1; i < n; ++i){
        int y = a[i - 1]/a[i];
        int M = m/a[i];
        int tot = 0;

        vi f;
        for(auto p : d){
            if(y % p == 0){
                f.pb(p);
            }
        }
        
        int sz = f.size();
        for(int mask = 1; mask < (1 << sz); ++mask){
            int prod = 1;
            int cnt = 0;

            for(int bit = 0; bit < sz; ++bit){
                if(mask & (1 << bit)){
                    prod *= f[bit];
                    cnt++;
                }
            }

            if(cnt & 1){
                tot += M/prod;
            }
            else{
                tot -= M/prod;
            }
        }
        b[i] = M - tot;
    }
    int ans = 1;
    for(int i = 0; i < n; ++i){
        ans = (ans * b[i]) % MOD;
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
 
