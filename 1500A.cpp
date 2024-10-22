#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
const int MOD = 998244353;
const int MAX_A = 2500000;
const int N = 1e5;
const int LN = 20;


// lets say two elements x, y have more then 1 occurence
// we can  x + y = x + y

// now only one element x has more than 3 occurence
// we can x + x = x + x

// now only one element x has more then 1 occurence
// x + smth = x + smth is invalid
// x + x = smth1 + smth2 is valid. we can check for it in decent tc
// if we dont find find anything, we will find no solution for x + x = smth1 + smth2


// finally we remain with solving for x1 + y1 = x2 + y2 all are distinct valued elements
// remove duplicates from array
// just run an n^2 loop and mark indices {i, j} for the sum v[i] + v[j]
// now closely observe that if a sum is repeating. marked[sum] = {x1, y1}
// current x2, y2 such that v[x2] + v[y2] = sum
// the thing is it is only possible if (x1 < x2 < y2 < y1)
// since all elements in array are distinct
// first we mark n - 1 sum then n - 2 sums, n - 3 sums
// if n <= 5000 ok n^2 good
// otherwise  n > 5000
// after ~4000 iterations total no of unique sums found >= 10 * 1e6, total uniue sums = 2.5 * 1e6
// thru pigeonhole, under 4000 iterations we can find a repeating sum
// thats why run min(n, 4000) iterations


vector<vector<int>> occ(MAX_A + 1);
vector<pii> vis(2*MAX_A + 1, {-1, -1});

void solve(){
    int n;
    cin >> n;
    vi v(n);
    in(v);

    vi a, indices;
    for(int i = 0; i < n; ++i){
        if(occ[v[i]].empty()){
            a.pb(v[i]);
            indices.pb(i);
        }
        occ[v[i]].pb(i);
    }

    int prev = -1;
    // finding two elements x, y with occ >= 2
    for(int i = 1; i <= MAX_A; ++i){
        if(occ[i].size() >= 2){
            if(prev == -1) prev = i;
            else{
                cout << "YES" << endl;
                cout << occ[prev][0] + 1 << " " << occ[i][0] + 1 << " ";
                cout << occ[prev][1] + 1 << " " << occ[i][1] + 1 << endl;
                return; 
            }
        }
    }

    // if exactly one element has >= 2 occ
    if(prev != -1){
        int x1 = occ[prev].back();
        occ[prev].pop_back();

        int x2 = occ[prev].back();
        occ[prev].pop_back();

        int sum = prev + prev;

        // x + x = 2*x. now find solutions for 2*x
        for(int j = 1; j < sum; ++j){
            if(j > MAX_A) continue;
            if(sum - j > MAX_A) continue;

            if(j == sum - j){
                if(occ[j].size() >= 2){
                    cout << "YES" << endl;
                    cout << x1 + 1 << " " << x2 + 1 << " ";
                    cout << occ[j][0] + 1 << " " << occ[j][1] + 1 << endl;
                    return;
                }
            }
            else{
                if(occ[j].size() >= 1 && occ[sum - j].size() >= 1){
                    cout << "YES" << endl;
                    cout << x1 + 1 << " " << x2 + 1 << " ";
                    cout << occ[j][0] + 1 << " " << occ[sum - j][0] + 1 << endl;
                    return;
                }
            }
        }
    }

    int sz = a.size();
    int iter = min(sz, 4000LL);
    for(int i = 0; i < iter; ++i){
        for(int j = i + 1; j < sz; ++j){
            int sum = a[i] + a[j];
            if(vis[sum].first == -1){
                vis[sum] = {indices[i], indices[j]};
            }
            else{
                cout << "YES" << endl;
                cout << vis[sum].first + 1 << " " << vis[sum].second + 1 << " ";
                cout << indices[i] + 1 << " " << indices[j] + 1 << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}  


int32_t main() {   
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    int t = 1; 
    // cin >> t;
    for(int i = 1; i<=t; i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}