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
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
vector<vector<ll>> binary_knapsack(vector<int>& val,vector<int>& weight, int W){
    int N = val.size();
    vector<vector<ll>> dp(N,vector<ll>(W+1,0));
    REP(w,W+1){
        if(weight[0]<=w) dp[0][w] = val[0];
    }
    REP(i,N-1){
        REP(w,W+1){
            if(w>=weight[i+1]){
                dp[i+1][w] = dp[i][w-weight[i+1]]+val[i+1];
            }
            chmax(dp[i+1][w], dp[i][w]);
        }
    }
    return dp;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int W,N,K;
    cin >> W >> N >> K;
    vi A(N),B(N);
    REP(i,N) cin >> A[i] >> B[i];
    vector<vector<vi>> DP(N,vector<vi>(W+1,vi(K+1,0)));

    REP(i,N){
        REP(w,W+1){
            REP(k,K+1){
                if(i==0){
                    if(w>=A[i]){
                        if(k>0){
                            DP[i][w][k] = B[i];
                        }
                    }
                }else{
                    DP[i][w][k] = DP[i-1][w][k];
                    if(w>=A[i]){
                        if(k>0){
                            chmax(DP[i][w][k],DP[i-1][w-A[i]][k-1] + B[i]);
                        }
                    }
                }
            }
        }
    }
    int ans=DP[N-1][W][K];

    cout << ans << endl;
}