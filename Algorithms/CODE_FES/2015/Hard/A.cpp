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



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int64 N;
    cin >> N;
    vector<int64> A(N);
    REP(i,N) cin >> A[i];
    vector<int64> DP_left(N,0), DP_right(N,0);
    vector<int64> cumsum(N+1);
    REP(i,N) cumsum[i+1] = cumsum[i] + A[i];
    REP(i,N){
        if(i){
            DP_left[i] += DP_left[i-1];
        }
        DP_left[i] += i; //今まで置いた分もひっくり返る
        DP_left[i] += cumsum[i+1];

        int j = N-i-1;
        if(i){
            DP_right[j] += DP_right[j+1];
        }
        DP_right[j] += i;
        DP_right[j] += cumsum[N] - cumsum[j];
    }

    int64 ans = INF;
    REP(i,N){
        if(i&1) continue;
        int64 tmp = 0;
        if(i) tmp += DP_left[i-1];
        if(i+1<N) tmp += DP_right[i+1];
        chmin(ans, tmp);
    }

    cout << ans << endl;
}