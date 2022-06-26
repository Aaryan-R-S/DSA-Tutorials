#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

// %% Declaration %%
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1e9+7
#define MOD1 998244353
#define NMAX_1D 1e5+3
#define NMAX_2D 1e3+9
#define INF 1e18
#define PI 3.141592653589793238462
#define ld long double
#define ll long long
#define ull unsigned long long
// -1e9 < int < 1e9
// -1e18 < long long int < 1e18

// %% I/O %%
#define in(w) ll w; cin>>w
#define inStr(w) string w; cin>>w
#define out(w) cout<<w<<"\n"
#define out_(w) cout<<w<<" "
void google(ll t) {cout << "Case #" << t << ": ";}

// %% Loops %%
#define rep(i,a,b) for (int i = a; i < b; i++)
#define rev(i,b,a) for (int i = b-1; i >= a; i--)
#define forEach(a, b) for (auto &a : b)

// %% STL %%
#define vl vector<ll>
#define vvl vector<vl>
#define vvvl vector<vvl>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define sz(v) (int)(v).size()
#define szArr(arr) (int)sizeof(arr)/sizeof(int)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ppb pop_back

// %% Utilities %%
#define ff first
#define ss second
#define cntSetBits __builtin_popcountll

// %% PBDS %%
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using muset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an array of size 3

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
/*--------------------------------------------------------------------------------------------------------------------------*/

// Main Program
void solve(int test_no){
    debug(test_no);
    in(N);
    in(K);
    vl a(N);
    vl b(N);
    
    ll max_e = 1000000000, min_e = 100000000;
    
    rep(i,0,N){
        a[i] = min_e + ( std::rand() % ( max_e - min_e + 1 ) );

        // [For Random Num]
        // rand_num = MIN + ( std::rand() % ( MAX - MIN + 1 ) );
    }
    rep(i,0,N){
        b[i] = min_e + ( std::rand() % ( max_e - min_e + 1 ) );
    }

    // // [For Shuffling]
    // auto rng = std::default_random_engine {};
    // std::shuffle(std::begin(a), std::end(a), rng);
    
    cout<<N<<endl;

    for (int i = 0; i < N; i++){
        cout<<a[i]<<" ";
    }cout<<endl;

    for (int i = 0; i < N; i++){
        cout<<b[i]<<" ";
    }cout<<endl;

    cout<<K<<endl;

    return;
}

// Driver Program 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif
    fastio();
    auto start_time = high_resolution_clock::now();
    in(t);
    // ll t = 1;    
    for(int i=1; i<=t; i++){
        solve(i);
    }
    auto stop_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop_time - start_time);
#ifndef ONLINE_JUDGE
        cerr << "Time: " << duration.count() / 1000 << "ms" << endl;
#endif
    return 0;
}