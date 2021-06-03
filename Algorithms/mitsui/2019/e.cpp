/*
　　　∫ ∫ ∫
　　　ノヽ
　　（＿　 ）
　（＿　　　 ）
（＿＿＿＿＿＿ ）
　ヽ(´･ω･)ﾉ　
　　 |　 /
　　 UU
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using P = pair<ll, ll>;
typedef vector<int> vi;
const int MOD = (int)1e9 + 7;
const ll INF = 1LL << 60;
const int inf = 1<<30;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = s; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
#define mp make_pair
template <typename T>
ostream& operator<<(ostream& os, vector<T> &V){
    int N = V.size();
    REP(i,N){
        os << V[i];
        if (i!=N-1) os << " ";
    }
    os << "\n";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, pair<T,T> const&P){
    os << P.first;
    os << " ";
    os << P.second;
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T> &S){
    auto it=S.begin();
    while(it!=S.end()){
        os << *it;
        os << " ";
        it++;
    }
    os << "\n";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, deque<T> &q){
    for(auto it=q.begin();it<q.end();it++){
        os<<*it;
        os<<" ";
    }
     os<<endl;
    return os;
}
//fixed<<setprecision(10)<<ans<<endl;
ll pow(int a,int b,int mod){
    vector<bool> bit;
    for(b=b;b>0;b>>=1){
        bit.push_back(b&1);
    }
    vector<ll> fac(bit.size()); fac[0] = a;
    ll res = 1;
    for(int i=1;i<bit.size();i++){
        fac[i] = (fac[i-1] * fac[i-1])%mod;
    }
    for(int i=0;i<bit.size();i++){
        if(bit[i]) res*=fac[i];
        res%=mod;
    }
    return res;
}


//mint
struct mint {
    ll x;
    mint(ll x=0):x((x+2*MOD)%MOD){}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime MOD
    mint inv() const {
        return pow(MOD-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};
ostream& operator<<(ostream& os, mint a){
    os << a.x;
    return os;
}

// vector<vector<vector<mint>>> memo(N,);
// map<pair<int,pair<int,pair<
map<tuple<int,int,int,int>, mint> memo;
vi A;
mint dfs(int index, int red, int green, int blue){
    cout << index << " " << red << " " << green << " " << blue << endl;
    if (index == -1){
        if(red==0&&green==0&&blue==0) return 1;
        else return 0;
    }
    if (memo.count(make_tuple(index,red,green,blue))!=0)
        return memo[make_tuple(index,red,green,blue)];

    mint res = 0;
    int a = A[index];
    if (red-1 == a || red==-1) res += dfs(index-1,a,green,blue);
    if (green-1 == a || green==-1) res += dfs(index-1,red,a,blue);
    if (blue-1 == a || blue==-1) res += dfs(index-1,red,green,a);
    memo[make_tuple(index,red,green,blue)] = res;
    return res;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    A.resize(N);
    REP(i,N) cin >> A[i];
    mint ans=dfs(N-1,-1,-1,-1);
    cout << ans << endl;
}