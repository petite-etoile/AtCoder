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



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int64>> A(N,vector<int64>(6));
    vector<int64> B;

    REP(i,N){ REP(j,6) cin >> A[i][j],B.emplace_back(A[i][j]); }

    //座圧
    sort(ALL(B));
    B.erase(unique(ALL(B)), B.end());
    map<int64,int> enc;
    REP(i,N*6) enc[B[i]] = i;
    for(auto& V:A) for(auto& v:V) v = enc[v];

    vector<long double> DP(N*6,0); //DP[x]:=xが出たあとの期待値
    
    vector<int> dict(N*6,-1); //dict[x]:=xがどのサイコロにあるか
    REP(i,N) REP(j,6) dict[A[i][j]] = i;

    vector<long double> E(N,0); //E[i]:=iのサイコロを次に投げたときの期待値
    long double E_max = 0; //max(E)

    for(int x=N*6-1;x>=0;x--){
        DP[x] = E_max + 1;
        E[dict[x]] += DP[x]/6.0;
        chmax(E_max, E[dict[x]]);
    }

    long double ans = 0;
    REP(i,N) chmax(ans, E[i]);
    cout<<fixed<<setprecision(10)<<ans+1<<endl;
}