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
    #define out(v) for(int tt = 0; tt<v.size(); tt++) cout<<v[tt]<<" "; cout<<endl;
    #define popcount(num) __builtin_popcount(num)
    typedef vector<int> vi;
    typedef pair<int,int> pii;
    const int INF = 1e18;
    const int MOD = 1e9 + 7;
    const int MAX_A = 2e6;
    const int N = 1e7;
    const int LN = 20;

    // r == b always OBEY
    // consider r > b
    // using pigeonhole we can tell 
    // that atleast one multiple of b will occur in (k*r, (k + 1)*r)
    // now find the maximum multiples u can get in this range
    // that is if you start at the smallest such multiple of b so that b*m % r is least
    // no find no of multiples you can get from there
    void solve(){   
        int r, b, k;
        cin >> r >> b >> k;

        if(r == b){
            cout << "OBEY" << endl;
        }
        else{
            if(r < b) swap(r, b);

            int start = __gcd(r, b);
            int lo = 0, hi = 1e9;
            int ans = 0;
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(start + mid*b >= r){
                    hi = mid - 1;
                }
                else{
                    ans = mid;
                    lo = mid + 1;
                }
            }
            ans++;
            if(ans >= k){
                cout << "REBEL" << endl;
            }
            else{
                cout << "OBEY" << endl;
            }
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
