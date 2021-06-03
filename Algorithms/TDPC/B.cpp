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


vector<int> A,B;
int N,M;
vector<pair<int,int>> memo;
inline int enc(int i,int j) {return i*(M+1)+j;}

pair<int,int> rec(int a,int b,int turn){
    if(a==N && b==M) return make_pair(0,0);
    if(memo[enc(a,b)]!=mp(-1,-1)) return memo[enc(a,b)];

    int64 res_A = 0, res_B = 0;
    int64 tmp_A,tmp_B;
    if(a<N){
        tie(tmp_A,tmp_B) = rec(a+1,b,turn^1);
        if(turn==0){ //snuke
            tmp_A += A[a];
            if(chmax(res_A, tmp_A)){
                res_B = tmp_B;
            }
        }else{ //smeke
            tmp_B += A[a];
            if(chmax(res_B, tmp_B)){
                res_A = tmp_A;
            }
        }
    }
    if(b<M){
        tie(tmp_A,tmp_B) = rec(a,b+1,turn^1);
        if(turn==0){ //snuke
            tmp_A += B[b];
            if(chmax(res_A, tmp_A)){
                res_B = tmp_B;
            }
        }else{ //smeke
            tmp_B += B[b];
            if(chmax(res_B, tmp_B)){
                res_A = tmp_A;
            }
        }
    }
    memo[enc(a,b)] = mp(res_A,res_B);
    return mp(res_A,res_B); 
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    A.resize(N);
    B.resize(M);
    memo.assign((N+1)*(M+1),mp(-1,-1));
    REP(i,N) cin >> A[i];
    REP(i,M) cin >> B[i];

    int ans,gomi;
    tie(ans,gomi) = rec(0,0,0);

    cout << ans << endl;
}
