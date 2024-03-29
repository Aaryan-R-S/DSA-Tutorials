#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

// %% Declaration %%
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define NMAX_1D 1e5+3
#define NMAX_2D 1e3+9
#define INF 1e18
#define PI 3.141592653589793238462
#define EPS 1e-6
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
#define outArr(w,st,en) rep(i,st,en){ out_(w[i]);} out("");
void google(ll t) {cout << "Case #" << t << ": ";}

// %% Loops %%
#define rep(i,a,b) for (int i = a; i < b; i++)
#define rev(i,b,a) for (int i = b-1; i >= a; i--)
#define forEach(a, b) for (auto &a : b)

// %% STL %%
#define vb vector<bool>
#define vvb vector<vb>
#define vl vector<ll>
#define vvl vector<vl>
#define vvvl vector<vvl>
#define pll pair<ll, ll>
#define vll vector<pll>
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
#define pow(a,n) pow(a,n)+0.5
#define powl(a,n) powl(a,n)+0.5

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

ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b (using extended euclid gcd)
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}   // for prime b (using fermat little theorem)
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

pair<vl, vl> calcFactNInvFact(ll N){
    vl fact(N+1); 
    vl invFact(N+1); 
    fact[0] = 1;
    for(int i=1;i<=N;i++){
        fact[i] = mod_mul(i, fact[i-1], MOD);
    }
    invFact[N] = expo(fact[N],MOD-2,MOD);
    for(int i = N-1; i>=0;i--){
        invFact[i] = mod_mul(i+1, invFact[i+1], MOD);
    }
    return {fact, invFact};
}
ll combination(ll n, ll r, ll m, vl &fact, vl &ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
 
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
vl sieve1(int n){vl vect(n+1, 0); vect[0] = -1; vect[1] = -1; for (int i = 2; i <= n; i++){if (vect[i] == 0) {vect[i] = i; for (int j = 2 * i; j <= n; j += i){vect[j] = i;}}}return vect;}
ll phi(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
/*--------------------------------------------------------------------------------------------------------------------------*/

// %% Helper funcs %%
#define vp vector<Point>
#define vvp vector<vp>

struct Point{
    int type;  // 0, 1 ,2 -> none, golden, silver
    int score;
    Point(){
        type = 0;
        score = 0;
    }
};

#define vs vector<string>
map<pll, vs> dirToTileIdMap;

// 0,1,2,3 -> up, right, down, left

void setDirToTileIdMap(){
    dirToTileIdMap[{0,1}] = dirToTileIdMap[{1,0}] = {"9", "B", "D", "F"};
    dirToTileIdMap[{0,2}] = dirToTileIdMap[{2,0}] = {"C", "D", "E", "F"};
    dirToTileIdMap[{0,3}] = dirToTileIdMap[{3,0}] = {"A", "B", "E", "F"};
    dirToTileIdMap[{1,2}] = dirToTileIdMap[{2,1}] = {"5", "7", "D", "F"};
    dirToTileIdMap[{1,3}] = dirToTileIdMap[{3,1}] = {"3", "7", "B", "F"};
    dirToTileIdMap[{2,3}] = dirToTileIdMap[{3,2}] = {"6", "7", "E", "F"};
}

map<string, int> tileIdToCountMap;
map<string, int> tileIdToCostMap;

void setTileIdToCountMap(){
    tileIdToCountMap["3"] = 0;
    tileIdToCountMap["5"] = 0;
    tileIdToCountMap["6"] = 0;
    tileIdToCountMap["7"] = 0;
    tileIdToCountMap["9"] = 0;
    tileIdToCountMap["A"] = 0;
    tileIdToCountMap["B"] = 0;
    tileIdToCountMap["C"] = 0;
    tileIdToCountMap["D"] = 0;
    tileIdToCountMap["E"] = 0;
    tileIdToCountMap["F"] = 0;

    tileIdToCostMap["3"] = 0;
    tileIdToCostMap["5"] = 0;
    tileIdToCostMap["6"] = 0;
    tileIdToCostMap["7"] = 0;
    tileIdToCostMap["9"] = 0;
    tileIdToCostMap["A"] = 0;
    tileIdToCostMap["B"] = 0;
    tileIdToCostMap["C"] = 0;
    tileIdToCostMap["D"] = 0;
    tileIdToCostMap["E"] = 0;
    tileIdToCostMap["F"] = 0;
}

struct Tile{
    int type; // 3,5,6,7,9,A,B,C,D,E,F
    int x, y;
};

vector<Tile> tilePlaced;

struct Grid{
    int rows;
    int cols;
    vvp mat;
    Grid(int r, int c) {
        rows = r;
        cols = c;
        mat = vvp(rows, vp(cols, Point()));
    }
};

// -> GREEDY, TWO POINTER
// -> BINARY SEARCH
// -> DYNAMIC PROGRAMMING
// -> COMPLEX DATA STRUCTURES OR ALGORITHM

// %% Main Program %%
// #define inpTC true
#define inpTC false
void solve(int test_no){
    debug(test_no);

    setDirToTileIdMap();
    setTileIdToCountMap();

    in(cols);
    in(rows); 
    Grid grid(rows, cols);

    in(g_points); in(s_points);
    in(total_tiles);

    rep(i,0,g_points){
        in(y);
        in(x); 
        grid.mat[x][y].type = 1;
    }

    rep(i,0,s_points){
        in(y); 
        in(x); 
        in(score);
        grid.mat[x][y].type = 2;
        grid.mat[x][y].score = score;
    }

    rep(i,0,total_tiles){
        inStr(tile_id);
        in(cost); in(num_tiles);
        tileIdToCountMap[tile_id] = num_tiles; 
        tileIdToCostMap[tile_id] = cost;
    }

    // print grid.mat
    rep(i,0,rows){
        rep(j,0,cols){
            out_(grid.mat[i][j].type);
        }
        out("");
    }

    tilePlaced.clear();

    // print tiles with type and coordinates
    for(auto it: tilePlaced){
        out_(it.type);
        out_(it.y);
        out(it.x);
    }

    return;
}

// %% Driver Program %% 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif
    fastio();
    auto start_time = high_resolution_clock::now();
    ll t;
    if(inpTC){ cin>>t; } else { t = 1; }  
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