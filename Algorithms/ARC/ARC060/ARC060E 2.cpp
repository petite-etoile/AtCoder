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

//xから1日で行ける一番遠いホテル
int calc_next(int64 x, vector<int64> const& X){
    return (upper_bound(ALL(X), x) - X.begin()) - 1;
}

//to:iの1ステップ先, MAX_K:ステップ数の上界
vector<vector<int>> doubling(vector<int> const& to, int64 MAX_K){
    int J = 1;
    while(MAX_K>0){
        J++;
        MAX_K >>= 1;
    }

    size_t N = to.size();
    vector<vector<int>> DP(N, vector<int>(J)); //DP[i][j] := 状態iから2^jステップ後の状態x
    for(int i=0; i<N; i++) DP[i][0] = to[i];

    for(int j=1;j<J;j++){
        for(int i=0; i<N; i++){
            DP[i][j] = DP[DP[i][j-1]][j-1];
        }
    }

    return move(DP);
}


int solve(int a, int b, vector<vector<int>> const& DP){
    int res = 0;
    int now = a;
    while(now < b){
        auto idx = lower_bound(ALL(DP[now]), b) - DP[now].begin() - 1; //b以上にならない最大のindex
        if(idx<0){
            res++; break;
        }
        res += 1<<idx;
        now = DP[now][idx];
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int64> X(N);
    REP(i,N) cin >> X[i];
    int64 L; cin >> L;

    vector<int> to(N);
    REP(i,N){
        to[i] = calc_next(X[i] + L, X);
    }

    auto DP = doubling(to, 1e5);

    int Q; cin >> Q;
    REP(i,Q){
        int a,b; cin >> a >> b;
        a--;b--;
        if(a>b) swap(a,b);
        auto ans = solve(a,b,DP);
        cout << ans << bn;
    }

}