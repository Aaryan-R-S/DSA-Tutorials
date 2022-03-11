#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;

#define ll          long long
#define vi          vector<int>
#define vll         vector<ll>
#define pll         pair<ll, ll>
#define pii         pair<int, int>
#define ld          long double
#define ff          first
#define ss          second
#define vs          vector<string>
#define vc          vector<char>
#define vpii        vector<pii>
#define vpll        vector<pll>
#define vb          vector<bool>
#define mp          make_pair
#define pb          push_back
#define ppb         pop_back
#define all(x)      x.begin(), x.end()
#define pqb         priority_queue <int>
#define pqs         priority_queue <int, vi, greater <int>>
#define ps(x, y)    fixed << setprecision(y) << x
#define mem0(arr)   memset(arr, 0, sizeof(arr))
#define mem1(arr)   memset(arr, -1, sizeof(arr))
#define endl        '\n'
#define yes         cout << "Yes" << endl
#define no          cout << "No" << endl

const ll INF       = 2e18;
const ll mod       = 1000000007;
const ll mod2      = 998244353;
const ld  PI        = 3.141592653589793238462;

template <typename T> void sort    (vector<T>& v) {std::sort(v.begin(),v.end());}
template <typename T> void sortbig (vector<T>& v) {std::sort(v.begin(),v.end(),greater<T>());}
template <typename T, typename Y> ostream& operator << (ostream& x, const pair<T,Y>& v) {x<<v.ff<<" "<<v.ss; return x;}
template <typename T, typename Y> ostream& operator << (ostream& x, const map<T, Y>& v) {for (auto it : v) x << it.ff << ": " << it.ss << endl; return x;}
template <typename T, typename Y> istream& operator >> (istream& x, pair<T,Y>& v) {x>>v.ff>>v.ss; return x;}
template <typename T> istream& operator >> (istream& x,vector<T>& v) {for(T& it:v) x>>it;return x;}
template <typename T> ostream& operator << (ostream& x,const vector<T>& v) {for(int i=0;i<(int)v.size();i++) x<<v[i]<<" ";return x;}
template <typename T> ostream& operator << (ostream& x,const set<T>& v) {for(auto it:v) x<<it<<" ";return x;}
template <typename T> ostream& operator << (ostream& x,const multiset<T>& v) {for(auto it:v) x<<it<<" ";return x;}
//template <typename T>
//using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef RAGH_A_VOID
#define debug(x) cerr << #x <<": "; print(x); cerr << endl;
#else
#define debug(x);
#endif

void print (int t)          {cerr << t;}
void print (ll t)           {cerr << t;}
void print (char t)         {cerr << t;}
void print (ld t)           {cerr << t;}
void print (double t)       {cerr << t;}
void print (const string& t){cerr << t;}

template <class T, class V> void print(pair <T, V> p);
template <class T, class V> void print(map <T, V> v);
template <class T, class V> void print(pair <T, V> p) {cerr << "("; print(p.ff); cerr << ","; print(p.ss); cerr << ")";}
template <class T, class V> void print(map <T, V> v) {for (auto i : v) {print(i); cerr << " ";}}
template <class T> void print(vector <T> v);
template <class T> void print(set <T> v);
template <class T> void print(multiset <T> v);
template <class T> void print(vector <T> v)   {for (T i : v) {print(i); cerr << " ";}}
template <class T> void print(set <T> v)      {for (T i : v) {print(i); cerr << " ";}}
template <class T> void print(multiset <T> v) {for (T i : v) {print(i); cerr << " ";}}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
inline ll expo(ll a, ll b, ll mm) {ll res = 1; while (b > 0) {if (b & 1) res = (res * a) % mm; a = (a * a) % mm; b = b >> 1;} return res;}
inline ll invprime(ll a, ll b) {return expo(a, b - 2, b);} // for prime
inline ll mulmod(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll divmod(ll a, ll b, ll m) {a = a % m; b = b % m; return (mulmod(a, invprime(b, m), m) + m) % m;} // only works with prime
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x;}
inline ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll invnonprime(ll a, ll b) {ll arr[3]; if(gcd(a, b) != 1){return -1;} extendgcd(a, b, arr); if(arr[0] < 0){arr[0] += b;} return arr[0];} //for non prime b (-1 is not possible)
inline ll addmod(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
inline ll submod(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
inline ll sumOfDigits(ll n) {ll sum = 0; while(n) {sum += n % 10; n /= 10;} return sum;}
ll nCr(ll n, ll r) {ll p = 1, k =1; if(n-r>r) r = n-r; if(r == 0) return 1; while(r) {p *= n; k *= r; ll m = gcd(p, k); p /= m; k /= m; n--; r--;} return p;}
ll nCrmod(ll n, ll r, vll& fact, ll mm) {return divmod(fact[n], mulmod(fact[r], fact[n-r], mm), mm);}
vector<ll> sieve(ll n) {ll*arr = new ll[n + 1](); vll v; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {v.push_back(i); for (ll j = 2 * i; j <= n; j += i)arr[j] = 1;} delete[] arr; return v;}
vector<ll> makesieve(vll& arr, ll n) {vll v; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {v.push_back(i); for (ll j = 2 * i; j <= n; j += i)arr[j] = 1;} return v;}
void makefact(vll& arr, ll n, ll mm) { arr[0] = arr[1] = 1; for(ll i = 2; i <= n; i++) { arr[i] = arr[i - 1] * i; arr[i] %= mm;}}
inline void google(ll x) {cout << "Case #" << x << ": ";}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*--------------- vi -> vll, pii -> pll, vpii -> vpll, int -> ll --------------------------------------*/



ll stamina_i, stamina_max, number_of_turns, number_of_demons;

struct demon{
    ll stamina_consumed;
    ll recovery_time;
    ll stamina_recovered;
    ll n;
    ll id;
    vll fragments;
    vll sum_fragments;
};

vector<demon> arr_of_demon;

map<ll, demon> idx_to_demon;
ll global_sum = 0 ;

ll score(vector<ll>& arr){

    ll curr = stamina_i;
    ll turn = 0, idx = 0, score = 0;
    map<ll, ll> stamina_gain;
    
    while(turn < number_of_turns and idx < number_of_demons){
        curr += stamina_gain[turn];
        curr = min(curr, stamina_max);
        ll id = arr[idx];
        // cout<<curr<<" "<<id<<" "<<idx_to_demon[id].stamina_consumed<<" "<<idx_to_demon[id].n<<" "<<idx_to_demon[id].sum_fragments[min(idx_to_demon[id].n - 1, number_of_turns - turn - 1)]<<endl;
        if(curr >= idx_to_demon[id].stamina_consumed){
            curr -= idx_to_demon[id].stamina_consumed;
            stamina_gain[turn + idx_to_demon[id].recovery_time] += idx_to_demon[id].stamina_recovered;
            // for(int i = 0; i < min(idx_to_demon[id].n, number_of_turns - turn); i++){
            //     score += idx_to_demon[id].fragments[i];
            // }
            if(idx_to_demon[id].n>0){
                score += idx_to_demon[id].sum_fragments[min(idx_to_demon[id].n - 1, number_of_turns - turn - 1)];
            }
            idx++;
        }
        turn++;
    }

    return score;
}

bool comp(const demon& a, const demon& b){
    if(a.n==0){
        return false;
    }
    if(b.n==0){
        return true;
    }
    return 
    (a.sum_fragments[min(a.n-1, number_of_turns-1)]) / (a.stamina_consumed+1) * (a.stamina_recovered+1) / (a.recovery_time)
        >
    (b.sum_fragments[min(b.n-1, number_of_turns-1)]) / (b.stamina_consumed+1) * (b.stamina_recovered+1) / (b.recovery_time);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("00-example.txt", "r", stdin);
    // freopen("01-the-cloud-abyss.txt", "r", stdin);
    freopen("02-iot-island-of-terror.txt", "r", stdin);
    // freopen("03-etheryum.txt", "r", stdin);
    // freopen("04-the-desert-of-autonomous-machines.txt", "r", stdin);
    // freopen("05-androids-armageddon.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    clock_t t1, t2;
    t1 = clock();

    cin >> stamina_i >> stamina_max >> number_of_turns >> number_of_demons;

    for(int i = 0; i < number_of_demons; i++){
        ll sc, tr, sr, na;
        cin >> sc >> tr >> sr >> na;
        vll arr(na); cin >> arr;
        ll sum = 0;
        vll temp_arr;
        for(auto x: arr){
            sum += x;
            temp_arr.pb(sum);
        }
        demon temp; temp.id = i;
        temp.n = na, temp.stamina_consumed = sc, temp.stamina_recovered = sr;
        temp.recovery_time = tr; temp.fragments = arr; temp.sum_fragments = temp_arr;
        idx_to_demon[i] = temp; arr_of_demon.pb(temp);
        // if(idx_to_demon[i].sum_fragments.size() != idx_to_demon[i].fragments.size()){
        //     cout << i << "*" << endl; break;
        // }
        global_sum+=sum;
    }


    ll ans = 0;
    vll ans_arr;

    sort(arr_of_demon.begin(), arr_of_demon.end(), comp);

    for(auto x: arr_of_demon){
        ans_arr.pb(x.id);
    }

//    cerr << ans_arr.size() << endl;
    ans = score(ans_arr);

    cerr << ans << endl;
    cerr << global_sum << endl;
    for(auto x: ans_arr){
        cout << x << endl;
    }
















    return 0;
}