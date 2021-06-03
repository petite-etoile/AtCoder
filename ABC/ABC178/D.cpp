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
const int MOD = (int)1e9 + 7;
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
template <typename T,typename S,typename U>
ostream& operator<<(ostream& os, tuple<T,S,U> const& P){
    os << "(";
    os << get<0>(P);
    os << ", ";
    os << get<1>(P);
    os << ", ";
    os << get<2>(P);
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

class BigCombination{
private:
    const int MAX = 510'000;
public:
    mint fac[510000], inv[510000];
    BigCombination(){
        fac[0] = fac[1] = 1;
        for(int i=2; i<MAX; i++){
            fac[i] = fac[i-1] * i;
        }
        inv[MAX-1] = fac[MAX-1].inv();
        for(int i=MAX-1;i>0;i--){
            inv[i-1] = inv[i] * i;
        }
    }

    mint combination(int n,int r){
        if(n<r) return 0;
        if(n==r) return 1;
        return fac[n] * inv[r] * inv[n-r];
    }
    mint permutation(int n,int r){
        if (n < r) return 0;
        return fac[n] * inv[n-r];
    }
};

//写像12相 n個をkグループに
//区別できるボール/区別できる箱/制限なし r^n
mint ball_1(int n,int r){
    return pow(n,r,MOD);
}
//区別できるボール/区別できる箱/1個以下 rPn 
mint ball_2(int n,int r){
    BigCombination B;
    mint res = B.permutation(r,n);
    return res;
}
//区別できるボール/区別できる箱/1個以上 包除原理
mint ball_3(int n,int r){
    BigCombination B;
    mint res = 0;
    for(int i=0;i<r;i++){
        mint x = B.combination(r,i) * pow((r-i), n, MOD);
        if (i&1) x *= -1;
        res += x;
    }
    return res;
}
//区別できないボール/区別できる箱/制限なし 仕切りをどこに入れるか選ぶ (n+r-1)C(n)
mint ball_4(int n,int r){
    BigCombination B;
    return B.combination(n+r-1,n);
}
//区別できないボール/区別できる箱/1個以下 rCn
mint ball_5(int n,int r){
    BigCombination B;
    return B.combination(r,n);
}
//区別できないボール/区別できる箱/1個以上 n-1Cr-1(しきりを玉の間に)
mint ball_6(int n,int r){
    BigCombination B;
    return B.combination(n-1,r-1);
}
//区別できるボール/区別できない箱/制限なし ベル数 = S(N,i)の和(0<=i<=r)
// mint ball_7(int n,int r){
//     vector<vector<mint>> S(n+1,vector<mint>(r+1,0)); //S[i][j]:=i人を区別されないj個のグループに分ける場合の数
//     for(int i=0;i<=min(n,r);i++) S[i][i]=1;
//     for(int i=0;i<=n;i++) S[i][1]=1;
//     for(int i=2;i<=n;i++){
//         for(int j=2;j<=r;j++){
//             S[i][j] = S[i-1][j-1] + S[i-1][j] * j;
//         }
//     }
//     mint res = 0;
//     for(int j=0;j<=r;j++) res+=S[n][j];
//     return res;
// }
//区別できるボール/区別できない箱/制限なし ベル数 = S(N,i)の和(0<=i<=r) (O((N+K) log N) version)
//ところで、0かi個以上という制限にしたいなら、箱の数をfloor(r/i)にするテクがあるかもしれない
mint ball_7(int n,int r){
    vector<mint> memo(r+1);
    mint now = 1;
    for(int j=0; j<=r; j++){
        if(j) now /= -j;
        memo[j] = now;
        if(j) memo[j] += memo[j-1];
    }

    mint res = 0;
    now = 1;
    for(int i=0; i<=r; i++){
        if(i) now *= i;
        mint tmp = mint(i).pow(n) / now; //i^n / i!
        res += tmp * memo[r-i];
    }
    return res;
}
//区別できるボール/区別できない箱/1個以下
mint ball_8(int n,int r){
    return n<=r;
}
//区別できるボール/区別できない箱/1個以上 スターリング数 
mint ball_9(int n,int r){
    BigCombination B;
    mint res = 0;
    for(int i=0;i<r;i++){
        mint x = B.combination(r,i) * pow((r-i), n, MOD);
        if (i&1) x *= -1;
        res += x;
    }
    return res * B.inv[r]; //ball_3の 1/r!倍
}
//区別できないボール/区別できない箱/制限なし 分割数
mint ball_10(int n,int r){
    vector<vector<mint>> P(n+1,vector<mint>(r+1,0));
    REP(j,r+1) P[0][j]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=r;j++){
            P[i][j] = P[i][j-1]; //0を含む
            if (i-j>=0) P[i][j] += P[i-j][j]; //0を含まない
        }
    }
    return P[n][r];
}
//区別できないボール/区別できない箱/1個以下
mint ball_11(int n,int r){
    return n<=r;
}
//区別できないボール/区別できない箱/1個以上 分割数
mint ball_12(int n,int r){
    if (n-r<0) return 0;
    return ball_10(n-r,r);
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int S; cin >> S;
    mint ans=0;
    BigCombination B;
    for(int i=1;i<S;i++){
        int remain = S-3*i;
        if(remain < 0) break;
        int n = remain;
        int r = i;
        ans += B.combination(n+r-1,n);
    }
    cout << ans << endl;
}