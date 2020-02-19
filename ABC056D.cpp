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



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,K;
    cin >> N >> K;
    vector<int> A(N);
    REP(i,N) cin >> A[i];

    vector<vector<bool>> dp1(N,vector<bool>(K,false));
    vector<vector<bool>> dp2(N,vector<bool>(K,false));

    //左から
    dp1[0][0] = true;
    if(A[0]<K) dp1[0][A[0]] = true;
    REP(i,N-1){
        REP(k,K){
            if(dp1[i][k]) dp1[i+1][k] = true;
            if(dp1[i][k] && k+A[i+1]<K) dp1[i+1][k+A[i+1]] = true;
        }
    }
    
    //右から
    dp2[N-1][0] = true;
    if(A[N-1]<K) dp2[N-1][A[N-1]] = true;
    for(int i=N-2; i>=0; i--){
        REP(k,K){
            if(dp2[i+1][k]) dp2[i][k] = true;
            if(dp2[i+1][k] && k+A[i]<K) dp2[i][k+A[i]] = true;
        }
    }

    int ans=N;
    REP(i,N){
        if(A[i]>=K){ ans--; continue; }
        if(0<i && i<N-1){
            vector<int> cumsum(K+1,0);
            REP(k,K)
                cumsum[k+1] = cumsum[k] + dp1[i-1][k];
            // (K-A[i] <= 右で作れる数 + 左で作れる数 < K) になるものが一つでもあれば必要な数
            REP(k,K){
                if(dp2[i+1][k]){
                    if(cumsum[K-k] - cumsum[max(0,K-k-A[i]) ]){ ans--; break; }
                }
            }
        }else{
            if(i)
                for(int k=K-A[i]; k<K; k++){ 
                    if(dp1[i-1][k]){ ans--; break;}
                }
            else
                for(int k=K-A[i]; k<K; k++){
                    if(dp2[i+1][k]){ ans--; break;}
                }
        }
    }


    cout << ans << endl;
}