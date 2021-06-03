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
const ll INF = 1LL << 62;
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
    os << endl;
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
//fixed<<setprecision(10)<<ans<<endl;


int N=3;
int b[2][3];
int c[3][2];
map<int,pair<int,int>> score_dict;
int dfs(int term,vector<vi>& board){
    if (term==9){
        int score_t = 0;
        int score_a = 0;
        REP(i,N){
            REP(j,N-1){
                if(board[i][j]==board[i][j+1]) score_t+=c[i][j];
                else score_a+=c[i][j];
            }
        }
        REP(i,N-1){
            REP(j,N){
                if(board[i][j]==board[i+1][j]) score_t+=b[i][j];
                else score_a+=b[i][j];
            }
        }
        score_dict[score_t-score_a]=mp(score_t,score_a);
        return score_t-score_a;
    }
    int max_score = -inf;
    int min_score = inf;
    REP(i,N){
        REP(j,N){
            if (board[i][j]!=-1) continue; //すでにおいてある
            board[i][j]=term%2;
            int score = dfs(term+1,board);
            chmax(max_score, score);
            chmin(min_score, score);
            board[i][j]=-1;
        }
    }
    // debug(candidate)
    int best_score;
    if(term&1) best_score= min_score;
    else best_score= max_score;
    return best_score;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i,2)REP(j,3)cin>>b[i][j];
    REP(i,3)REP(j,2)cin>>c[i][j];

    vector<vi> board(N,vi(N,-1));

    int ans=dfs(0, board);
    cout << score_dict[ans] << endl;
}