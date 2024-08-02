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


// we can set Z = 0 or 1 or 2
// stones with same color dont react
// but stones with different color and F(a, b) % 3 == Z will react

// construction : ?
// first find Ai mod 3
// let edge value will be f(u, v) == 0 or 1 or 2
// 0 if (0, 0)
// 1 if (0, 1) (2, 0)
// 2 if (1, 2) (1, 1) (2, 2)

// we want to divide graph into n/2 vertices such that
// edge between opposite colours != Z
// if Z == 0, two zeroes should always have same colour meaning zero cnt <= n/2

// now the remaining is z > n/2

// if Z == 1, all coloured same impossible
// if there are no 1 or 2 meaning zerocnt == n, we can colour equally

// now the remaining is z > n/2 && z != n && (one > 0 || two > 0)

// if Z == 2
// regardless cnt[1] == 0 or cnt[2] == 0
// cnt(two + zero) <= n/2 always true



void solve(){
    int n;
    cin >> n;

    vi v(n);
    in(v);

    vi c(3, 0);
    for(int i = 0; i < n; ++i){
        c[v[i] % 3]++;
    }

    if(c[0] <= n/2){
        int cnt = n/2 - c[0];
        cout<<"0"<<endl;
        for(int i = 0; i < n; ++i){
            if(v[i] % 3 == 0){
                cout<<"0";
            }
            else if(cnt){
                cout<<"0";
                cnt--;
            }
            else{
                cout<<"1";
            }
        }
        cout<<endl;
        return;
    }
    if(c[0] == n){
        cout<<"1"<<endl;

        for(int i = 0; i < n; ++i){
            if(i & 1){
                cout<<"0";
            }
            else cout<<"1";
        }
        cout<<endl;
        return;
    }
    if(c[1] + c[2] <= n/2){
        cout<<"2"<<endl;

        int cnt = n/2 - c[1] - c[2];
        for(int i = 0; i < n; ++i){
            if(v[i] % 3 == 0){
                if(cnt){
                    cout<<"1";
                    cnt--;
                }
                else cout<<"0";
            }
            else cout<<"1";
        }
        cout<<endl;
        return;
    }

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
 
