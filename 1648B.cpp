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
const int N = 1e5;
const int LN = 20;

// so if we set the multiplication factor 
// suppose it is x

// left number is a
// then b / a  = x is true if  a * x <= b <= a*x + a - 1
// we can bruteforce because possbilities of a
// = n/1 + n/2 + n/3 = log(n)

// since we are fixing x = a, no of y's will be simply
// no of elements in array a * x <= b <= a * x + a - 1
// for each a add up no of elements found

// in the array the no of selections for a will be no of elements >= a and say is Acnt
// so we have to make sure the sum of no of b's found thru bruteforce equals Acnt



void solve(){
    int n, c;
    cin >> n >> c;

    vi v(n);
    in(v);

    vi pre(c + 1);
    for(auto x : v){
        pre[x]++;
    }

    if(pre[1] == 0){
        cout<<"No"<<endl;
        return;
    }

    for(int i = 1; i <= c; ++i){
        pre[i] += pre[i - 1];
    }

    int cnt = 0;
    vi ans(c + 1, 0);
    for(int x = 1; x <= c; ++x){
        if(pre[x] == pre[x - 1]) continue;
        for(int a = 1; a <= c/x; ++a){
            ans[a] += pre[min(c, a*x + a - 1)] - pre[a*x - 1];
        }
    }

    for(int i = 0; i < v.size(); ++i){
        if(ans[v[i]] != pre[c] - pre[v[i] - 1]){
            cout<<"No"<<"\n";
            return;
        }
    }
    cout<<"Yes"<<"\n";

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
 
