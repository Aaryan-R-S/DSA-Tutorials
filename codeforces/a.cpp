#include<bits/stdc++.h>
using namespace std;
// %% Declaration %%
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1e9+7
#define MOD1 1e5+3
#define MOD2 1e3+9
#define INF 1e18
#define PI 3.141592653589793238462
#define ld long double
#define ll long long
#define ull unsigned long long
// -1e9 < int < 1e9
// -1e18 < long long int < 1e18
// %% I/O %%
#define in(w) int w; cin>>w
#define out(w, n) cout<<w<<n
// %% Loops %%
#define rep(i,a,b) for (int i = a; i < b; i++)
#define rev(i,b,a) for (int i = b; i > a; i--)
#define forEach(a, b) for (auto &a : b)
// %% STL %%
#define SIZE(v) (int)v.size()
#define SIZEA(arr) (int)sizeof(arr)/sizeof(int)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pair<int, int>>
// %% Vectors %%
#define SORT(v) sort(v.begin(), v.end())
#define SORTREV(v) sort(v.begin(), v.end(), greater<int>())
#define REVERSE(v) reverse(v.begin(), v.end())
// %% Arrays %%
#define SORTA(arr, sz) sort(arr, arr + sz)
#define REVERSEA(arr, sz) reverse(arr, arr + sz)
// %% Debug %%
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(string t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// %% PBDS %%
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template<class T> using muset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Main Program
void solve(){
    in(n);
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    
}

// Driver Program 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    in(t);
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}