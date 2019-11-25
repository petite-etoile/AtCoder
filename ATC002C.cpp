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
int solve(vector<int>& P, int N){
    vector<vector<int>> dp(N,vector<int>(N)); //dp[i][j]:=i,j区間の期待値最小
    REP(i,N)REP(j,N) if(i<j) dp[i][j]=(int)(1<<30);
    debug(dp)
    /*
    区間[s,t]をiで分割する  
    dp[s,t] = min(dp[s,i] + dp[i+1,t]) + Σ[s,t](P[])
    */
    vector<int> cumsum(N+1,0);
    REP(i,N) cumsum[i+1]=cumsum[i]+P[i];
    for(int i=1;i<N;i++){
        for(int left=0;left < N-i;left++){
            int right = left + i;
            for(int k = 0;k < i;k++){
                int mid = left + k;
                chmin(dp[left][right], dp[left][mid]+dp[mid+1][right]);
            }
            dp[left][right] += cumsum[right+1]-cumsum[left];
        }
    }
    int res = dp[0][N-1];
    return res;
}
//fixed<<setprecision(10)<<ans<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> W(N);
    REP(i,N) cin >> W[i];

    int ans=solve(W,N);


    cout << ans << endl;
}