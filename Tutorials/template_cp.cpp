#include<bits/stdc++.h>
using namespace std;
// Declaration
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define MOD2 1e3+2
#define INF 1e18
#define PI 3.141592653589793238462
#define ld long double
#define ll long long
#define ull unsigned long long
// I/O
#define in(w) int w; cin>>w
#define out(w, n) cout<<w<<n
// Loops
#define rep(i,a,b) for (int i = a; i < b; i++)
#define rev(i,b,a) for (int i = b; i > a; i--)
#define forEach(a, b) for (auto &a : b)
// STL
#define SIZE(v) (int)v.size()
#define SIZEA(arr) (int)sizeof(arr)/sizeof(int)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pair<int, int>>
// Vectors
#define SORT(v) sort(v.begin(), v.end())
#define SORTREV(v) sort(v.begin(), v.end(), greater<int>())
#define REVERSE(v) reverse(v.begin(), v.end())
// Arrays
#define SORTA(arr, sz) sort(arr, arr + sz)
#define REVERSEA(arr, sz) reverse(arr, arr + sz)
// Debug
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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}




// Main Program
void solve(){
    in(n);
	
}

// Driver Program 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
    in(t);
    while(t--){
        solve();
    }
    return 0;
}