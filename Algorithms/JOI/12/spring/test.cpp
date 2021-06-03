// https://ei1333.github.io/luzhiled/
// http://beet-aizu.hatenablog.com/entry/2017/01/04/113233
// http://www.prefield.com/algorithm/
#include <bits/stdc++.h>
constexpr char bn = '\n';
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vd = vector<ld>;
using vs = vector<string>;
using vb = vector<bool>;
using vvl = vector<vector<ll>>;
using vvd = vector<vector<ld>>;
using vvs = vector<vector<string>>;
using vvb = vector<vector<bool>>;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;
using Graph = vector<vector<ll>>;
const ll INF = 1LL << 60;
void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
const ll tl= 1000000007;
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REREP(i, n) for (ll i = n; i >= 0; i--)
#define FOR(i, a, n) for (ll i = a; i < n; i++)
#define REFOR(i, n, a) for (ll i = n; i >= a; i--)
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<=b)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() ) //被り削除
#define debug cout << "line : " << __LINE__ << " debug" << endl;
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ind(...) long double __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define inc(...) char __VA_ARGS__; in(__VA_ARGS__)
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << endl;} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
template<typename T>void die(T x){out(x); exit(0);}
#define in1(A) REP(i,A.size()) in(A[i]);
#define in2(A,B) REP(i,A.size()) in(A[i],B[i]);
#define in3(s,t,u) REP(i,sz(s)){in(s[i] , t[i] , u[i]);}
#define in4(s,t,u,v) REP(i,sz(s)){in(s[i] , t[i] , u[i] , v[i]);}
#define each(x,v) for(auto& x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
struct Point{ ld x,y; };
ld dist(Point a, Point b){return sqrt(abs(a.x-b.x)*abs(a.x-b.x)+abs(a.y-b.y)*abs(a.y-b.y));} // ２点間の距離 
ll gcd(ll a, ll b) { return b != 0 ? gcd(b, a % b) : a; }
ll lcm(ll a,ll b){ return a / gcd(a,b) * b;} 
ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
   while (n > 0) {
      if (n & 1) res = res * a % mod;
      a = a * a % mod;
      n >>= 1;
  }
  return res;
}
ll fact(ll n){ if(n < 2) return 1; return (n * fact(n-1))%tl; } //階乗
inline ll updiv(ll a,ll b){ return (a + b - 1) / b; } //切り上げ
template<typename T,typename U>ll ceil(T a,U b){return (a + b - 1) / b;}
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
#define YES(n) ((n) ? "YES" : "NO"  )
#define Yes(n) ((n) ? "Yes" : "No"  )
#define yes(n) ((n) ? "yes" : "no"  )
//-------------------------------------------------------------------------------------------------
int main(){
    init();
    ll ans= 0;
    inl(n);
    vs A(n); in1(A);
    map<string,ll>T;
    REP(i,n){
        T[A[i]]++;
        if(T[A[i]]==2){
            out("No");
            return 0;
        }
        // cerr << "A";
        // cerr << (A[i-1][A[i].size()-1]) << endl;
        if(i!=0 && A[i-1][A[i].size()-1]!=A[i][0]){
                out("No");
            return 0;
        }
    }
    

    out("Yes");
}
