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
ostream& operator<<(ostream& os, vector<T> &V){
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

//区別できないボール/区別できない箱/制限なし 分割数
vector<vector<int>> partition(int n,int r){
    vector<vector<int>> P(n+1,vector<int>(r+1,0));
    REP(j,r+1) P[0][j]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=r;j++){
            P[i][j] = P[i][j-1];
            if (i-j>=0) P[i][j] += P[i-j][j];
            P[i][j]%=MOD;
        }
    }
    return P;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;

    vector<int> A(N),B(M);
    int a_sum,b_sum;
    REP(i,N)
        cin >> A[i], a_sum+=A[i];
    REP(j,M)
        cin >> B[j], b_sum+=B[j];

    vector<int> A_grouped,B_grouped; //同じキル数の人をまとめる
    int before=-1;
    for(auto a:A){
        if(a!=before) A_grouped.emplace_back(1);
        else A_grouped.back()+=1;
        before = a;
    }
    before = -1;
    for(auto b:B){
        if(b!=before) B_grouped.emplace_back(1);
        else B_grouped.back()+=1;
        before = b;
    }

    auto partition_tableA = partition(b_sum,N);
    auto partition_tableB = partition(a_sum,M);

    N = A_grouped.size();
    M = B_grouped.size();

    vector<vector<mint>> DP1(N+1,vector<mint>(b_sum+1)), DP2(M+1,vector<mint>(a_sum+1));
    // DP[i][j] := iまでの人(グループ)にjデス割り振る場合の数

    DP1[0][0] = 1;
    REP(i,N){
        REP(j,b_sum+1){
            REP(x,b_sum+1){
                if(x+j>b_sum) break;
                DP1[i+1][j+x] += DP1[i][j] * partition_tableA[x][A_grouped[i]];
            }
        }
    }
    DP2[0][0] = 1;
    REP(i,M){
        REP(j,a_sum+1){
            REP(x,a_sum+1){
                if(x+j>a_sum) break;
                DP2[i+1][j+x] += DP2[i][j] * partition_tableB[x][B_grouped[i]];
            }
        }
    }

    mint ans = DP1[N][b_sum];
    ans *= DP2[M][a_sum];
    cout << ans << bn;
}