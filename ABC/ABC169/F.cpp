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
typedef vector<int> vi;
const int MOD = 998244353;
const int64 INF = 1LL << 62;
const int inf = 1<<30;
const char bn = '\n';
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = s; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
#define mp make_pair
template <typename T>
ostream& operator<<(ostream& os, const vector<T> &V){
    int N = V.size();
    REP(i,N){
        os << V[i];
        if (i!=N-1) os << " ";
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
template <typename T,typename S>
ostream& operator<<(ostream& os, map<T,S> const&M){
    for(auto e:M){
        os<<e;
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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N,S; cin >> N >> S;
    vector<int> A(N);
    REP(i,N){
        cin >> A[i];
    }
    vector<mint> DP(S+1,0);
    DP[0] = mint(2).pow(N);
    REP(i,N){
        for(int v=S; v>=0; v--){
            if(v+A[i]<=S) DP[v+A[i]] += DP[v]/2;
        }
    }
    cout << DP[S] << bn;

    // vector<vector<mint>> DP1(N,vector<mint>(max(S,*max_element(ALL(A)))+1));
    // auto DP2 = DP1;

    // DP1[0][0] = 1;
    // DP2[N-1][0] = 1;
    // REP(i,N){
    //     for(int v=S;v>=0;v--){
    //         if(i) DP1[i][v] = DP1[i-1][v];
    //         if(v+A[i]<=S) DP1[i][v+A[i]] += DP1[i][v];
            

    //         int idx = N-1-i;
    //         if(i) DP2[idx][v] = DP2[idx+1][v];
    //         if(v+A[idx]<=S) DP2[idx][v+A[idx]] += DP2[idx][v];
    //     }
    //     debug(DP2)
    // }

    // debug(DP1)
    // debug(DP2)

    // mint ans = 0;
    // REP(i,N){
    //     debug(i)
    //     if(i==0){
    //         if(S>=A[i])
    //             ans += DP2[i+1][S-A[i]];
    //         ans += DP2[i+1][S];
    //     }else if(i+1<N){
    //         REP(l,S+1){
    //             int r = S-l;
    //             if(r<0) continue;
    //             ans += DP1[i-1][l] * DP2[i+1][r];
    //             debug(mp(l,r))
    //             debug(mp(DP1[i-1][l], DP2[i+1][r]))
    //             r -= A[i];
    //             if(r<0) continue;
    //             ans += DP1[i-1][l] * DP2[i+1][r];
    //             debug(mp(DP1[i-1][l], DP2[i+1][r]))
    //         }
    //     }else{
    //         if(S>=A[i])
    //             ans += DP1[i-1][S-A[i]];
    //         ans += DP1[i-1][S];
    //     }
    //     debug(ans)
    // }
    // cout << ans << endl;
}