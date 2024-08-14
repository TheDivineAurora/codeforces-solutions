#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
 
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
const int MOD = 1e9 + 7;
const int N = 3e5;
const int LN = 20;

// the question gave us n permuations of m length m <= 10 , n = 5e4
// product of permutations p * q = Rj = Qpj
// the order in which elements of q will be taken is decided by pj

// beauty of permutations is length of longest sequence from start which obey
// pi = i

// for every permutation ai
// i have to find maximum beauty among all permutations (ai * aj) j = 1 to n
// which means if ai is deciding order of elements taken in permutation aj
// what will be maximum beauty

// for ai, if Ax1 = 1, Ax2 = 2
// i will find how many permutations have a1 = x1
// then all those permutations are guaranteed answer = 1
// i will find how many of these pemutations have a2 = x2
// all these will have answer of 2

// since ans <= 10
// i wll take use of prefix sums for each length

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m + 1, 0));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> v[i][j];
		}
		v[i][m] = i;
	}
 
	sort(all(v), [&](vi A, vi B){
		for(int i = 0; i < m + 1; ++i){
			if(A[i] != B[i]){
				return A[i] < B[i];
			}
		}
	});
 
	int bit[n + 1][m + 1];
	memset(bit, 0, sizeof(bit));
 
	vi x(m + 1);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			x[v[i][j]] = j + 1;
		}
 
		int l = 0, r = n - 1;
		for(int num = 1; num <= m; ++num){
			int lo = l, hi = r;
			int ans = -1;
			while(lo <= hi){
				int mid = (lo + hi)/2;
				if(v[mid][num - 1] == x[num]){
					ans = mid;
					hi = mid - 1;
				}
				else if(v[mid][num - 1] < x[num]){
					lo = mid + 1;
				}
				else{
					hi = mid - 1;
				}
			}
			if(ans == -1) break;
			l = ans;
 
			lo = l, hi = r;
			ans = -1;
			while(lo <= hi){
				int mid = (lo + hi)/2;
				if(v[mid][num - 1] == x[num]){
					ans = mid;
					lo = mid + 1;
				}
				else if(v[mid][num - 1] < x[num]){
					lo = mid + 1;
				}
				else{
					hi = mid - 1;
				}
			}
			if(ans == -1) break;
			r = ans;
 
			bit[l][num]++;
			bit[r + 1][num]--;
		}
	}
 
	vi ans(n);
	for(int i = 0; i < n; ++i){
		if(i){
			for(int j = 1; j <= m; ++j){
				bit[i][j] += bit[i - 1][j];
			}
		}
 
		int msb = 0;
		for(int j = 1; j <= m; ++j){
			if(bit[i][j]) msb = j;
		}
		ans[v[i][m]] = msb;
	}
 
	out(ans);
 


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
 
