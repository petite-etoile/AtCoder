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
#pragma region macro
#include <bits/stdc++.h>
typedef long long int64;
using namespace std;
using P = pair<int64, int64>;
typedef vector<int> vi;
const int MOD = (int)1e9 + 7;
const int64 INF = 1LL << 62;
const int inf = 1<<30;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = s; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
#define mp make_pair
#define bn '\n'
template <typename T>
ostream& operator<<(ostream& os, const vector<T> &V){
    int N = V.size();
    REP(i,N){
        os << V[i];
        if(i!=N-1) os << " ";
    }
    os << "\n";
    return os;
}
template <typename T,typename S>
ostream& operator<<(ostream& os, pair<T,S> const&P){
    os << "(";
    os << P.first;
    os << " , ";
    os << P.second;
    os << ")";
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
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
#pragma endregion
//fixed<<setprecision(10)<<ans<<endl;

int64 pow(int a,int b,int mod){
    vector<bool> bit;
    for(b=b;b>0;b>>=1){
        bit.push_back(b&1);
    }
    vector<int64> fac(bit.size()); fac[0] = a;
    int64 res = 1;
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
    int64 x;
    mint(int64 x=0):x((x+2*MOD)%MOD){}
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
    mint pow(int64 t) const {
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

vector<vector<int>> edge;

vector<int64> dp;
vector<int64> ans;
int64 M;
int64 dfs(int v, int pre){
    for(auto to:edge[v]){
        if(to==pre) continue;
        dp[v]*=dfs(to,v)+1;
        dp[v]%=M;
    }
    return dp[v];
}

void dfs_with_rerooting(int v, int pre, int64 pre_val){
    debug(mp(v, mp(pre,pre_val)))
    for(auto to:edge[v]){
        if(to==pre) ans[v] *= pre_val+1;
        else ans[v] *= dp[to]+1;
        ans[v]%=M;
    }

    //accumulate product
    vector<int64> left(edge[v].size(),1),right(edge[v].size(),1);
    REP(i,edge[v].size()){
        auto to = edge[v][i];
        if(i) left[i] = left[i-1];
        left[i] *= dp[to] + 1;
        left[i] %= M;
    }

    for(int i=edge[v].size()-1; i>=0; i--){
        auto to = edge[v][i];
        if(i<edge[v].size()-1) right[i] = right[i+1];
        right[i] *= dp[to] + 1;
        right[i] %= M;
    }

    //rerooting
    REP(i,edge[v].size()){
        auto to = edge[v][i];
        auto tmp = dp[v];
        if(to!=pre){
            int64 val = 1;
            if(i) val *= left[i-1];
            if(i<edge[v].size()-1) val *= right[i+1];
            val %= M;
            dp[v] = val;
            dfs_with_rerooting(to,v,val);
        }
        dp[v] = tmp;
    }
    
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N >> M;
    dp.assign(N,1);
    edge.resize(N);
    ans.assign(N,1);
    int a,b;
    REP(i,N-1){
        cin >> a >> b;
        edge[--a].emplace_back(--b);
        edge[b].emplace_back(a);
    }
    dfs(0,-1);
    dfs_with_rerooting(0,-1,-1);


    for(auto a:ans){
        cout << a << bn;
    }
}   