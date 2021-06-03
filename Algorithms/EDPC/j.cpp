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
typedef long double ld;
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

int N;
ld dfs(int i, int j, int k, vector<vector<vector<ld>>>& dp){
    if(not (i or j or k)) return 0;
    if(dp[i][j][k]) return dp[i][j][k];

    ld res = (ld)N/(i+j+k);

    if(i) res += dfs(i-1,j+1,k,dp) * i/(i+j+k);
    if(j) res += dfs(i,j-1,k+1,dp) * j/(i+j+k);
    if(k) res += dfs(i,j,k-1,dp) * k/(i+j+k);
    dp[i][j][k] = res;
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    vector<vector<vector<ld>>> dp(N+1,vector<vector<ld>>(N+1,vector<ld>(N+1,0)));
    
    vector<int> cnt(4,0);
    int a;
    REP(i,N){
        cin >> a;
        cnt[a]++;
    }
    ld ans=dfs(cnt[3],cnt[2],cnt[1],dp);
    cout << fixed<<setprecision(10)<<ans<<endl;
}