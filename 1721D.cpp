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

// for a bit B to be sit in f(a, b)
// come in decreasing order
// we want to make that bit set in all Ci
// so pair 1 with 0 or 0 with 1
// make a count of unset Bth bits (x1) and setBth bits(y1) in A
// find same for B, and we need to have x2 = y1 and x1 = y2

// now when it works we will arrange as such
// 0000111
// 1111000

// lets call intervals as [0, l), [l, n)
// now elements are only allowed to be arranged within the interval
// because we have a higher bit set in our answer
// for next bit, if all intervals satisfy the condition
// we can add it on our answer and add new intervals [0, l1), [l1, l2), [l2, n)
// if not just check for next bit
void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    in(a); in(b);

    vector<int> p = {n};
    int ans = 0;
    for(int bit = 29; bit >= 0; --bit){

        bool yes = true;
        sort(all(p));

        vi points;
        for(int i = 0; i < p.size(); ++i){
            int l = (i ? p[i - 1] : 0);
            int r = p[i];   // [l, r)

            int st = 0, ust = 0;
            for(int j = l; j < r; ++j){
                if(a[j] & (1 << bit)) st++;
                if(!(b[j] & (1 << bit))) ust++;
            }

            if(st != ust){
                yes = false;
                break;  // this interval cant be rearranged to get this bit , so skip bit
            }

            if(st != 0 || st != r - l){
                // A has set bits arranged to left
                sort(a.begin() + l, a.begin() + r, [&](int A,int B){
                    return (A & (1 << bit)) > (B & (1 << bit));
                });

                // B has unset bits arranged to left
                sort(b.begin() + l, b.begin() + r, [&](int A,int B){
                    return (A & (1 << bit)) < (B & (1 << bit));
                });
                points.pb(l + st);
            }
        }

        if(yes){
            ans += (1 << bit);
            for(auto x : points){
                p.pb(x);
            }
        }
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
 
