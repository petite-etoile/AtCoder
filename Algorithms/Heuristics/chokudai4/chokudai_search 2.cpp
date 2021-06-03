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
#pragma region macro
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
template <typename T,typename S,typename U>
ostream& operator<<(ostream& os, tuple<T,S,U> const& P){
    os << "(";
    os << get<0>(P);
    os << ", ";
    os << get<1>(P);
    os << ", ";
    os << get<2>(P);
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
#pragma endregion


//----局面の状態----
class State{
    public:
    int score;
    vector<vector<int>> board;
    State(){
        score = 0;
    }

    State(int score_, vector<vector<int>> const& board_){
        score = score_;
        board = board_;
    }

    bool operator<(const State& S2) const{
        return this->score < S2.score;
    }

    bool operator>(const State& S2) const{
        return this->score > S2.score;
    }
};

//-----------------


//----入出力検証プログラムよりコピペ----
int calc_score_all(vector<vector<int>> const& board, vector<int> const& B){
    int point = 0;
    int N = board.size();

    //tate
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int now = 0;
            for (int k = i; k < N; k++)
            {
                if(board[k][j] == 0) continue;
                now += board[k][j];
                if (now == B[0]) point += B[0];
                if (now == B[1]) point += B[1];
                if (now == B[2]) point += B[2];
                if (now > B[2]) break;
            }
        }
    }

    //yoko
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int now = 0;
            for (int k = j; k < N; k++)
            {
                if(board[i][k] == 0) continue;
                now += board[i][k];
                if (now == B[0]) point += B[0];
                if (now == B[1]) point += B[1];
                if (now == B[2]) point += B[2];
                if (now > B[2]) break;
            }
        }
    }

    return point;
}
//-----------------



//-----部分的なスコア更新を計算-----
int get_added_score(int h, int w, vector<vector<int>> const& board, vector<int> const& B){
    int res = 0, now;

    //tate
    now = 0;
    for(int i=h; i>=0; i--){
        now += board[i][w];
        if(now == B[0]) res += B[0] ;
        else if(now == B[1]) res += B[1];
        else if(now == B[2]) res += B[2];
        else if(now > B[2]) break;
    }
    
    //yoko
    now = 0;
    for(int j=w; j>=0; j--){
        now += board[h][j];
        if(now == B[0]) res += B[0] ;
        else if(now == B[1]) res += B[1];
        else if(now == B[2]) res += B[2];
        else if(now > B[2]) break;
    }

    // debug(res)
    return res;
}
//------------------------------

void chokudai_search(vector<int> const& B, vector<vector<int>> const& L, vector<vector<int>> const& R, int& ans_score, vector<vector<int>>& ans, clock_t end_time){
    int N = L.size();

    // vector<priority_queue<State, vector<State>, greater<State>>> priq_vec; //各深さごとの(スコア, 局面)を降順でもつ
    // vector<priority_queue<State>> priq_vec(N*N); //各深さごとの(スコア, 局面)を昇順でもつ
    vector<multiset<State>> priq_vec(N*N); //各深さごとの(スコア, 局面)を昇順でもつ 状態が大きくなりすぎてMLEするので定期的に削除できるようにmultiset

    //まず探索
    int h,w;
    vector<vector<int>> board(N, vector<int>(N, 0)); int before_score = 0;
    for(int depth=0; depth<N*N; depth++){
        h = depth/N; w = depth%N;


        for(int num = L[h][w]; num <= R[h][w]; num++){
            board[h][w] = num;
            int new_score = before_score + get_added_score(h, w, board, B);
            priq_vec[depth].insert(State(new_score, board));
            // assert(new_score == calc_score_all(board, B));
        }
        
        before_score = (*--priq_vec[depth].end()).score;
        board = (*--priq_vec[depth].end()).board;

    }

    int cnt=0;
    while(true){
        cnt++;
        clock_t now = clock();
        
        //各深さについて、今まで探索したやつで一番いいやつを使って次を探索
        for(int depth=1; depth<N*N; depth++){
            if(now >= end_time - CLOCKS_PER_SEC && clock() >= end_time){
                ans = (*priq_vec[N*N-1].begin()).board;
                ans_score = (*priq_vec[N*N-1].begin()).score;
                return;
            }
            if(priq_vec[depth-1].empty()){ continue;} //priqが空


            State before_state = *--priq_vec[depth-1].end(); priq_vec[depth-1].erase(--priq_vec[depth-1].end()); //１個前の局面の一番いいやつ
            int before_score = before_state.score;
            vector<vector<int>> board = before_state.board;

            h = depth/N; w = depth%N;
            for(int num = L[h][w]; num <= R[h][w]; num++){
                board[h][w] = num;
                int new_score = before_score + get_added_score(h, w, board, B);
                // assert(new_score == calc_score_all(board, B));
                priq_vec[depth].insert(State(new_score, board));
            }

            if(priq_vec[depth].size() > 200) {
                auto l_iter = priq_vec[depth].begin(); auto r_iter = l_iter; 
                for(int _=0; _ < priq_vec[depth].size() - 200; _++) r_iter++;
                priq_vec[depth].erase(l_iter, r_iter);
            }
        }
    }

}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    const double sec = 2.5;    
    clock_t start_time = clock();
    clock_t end_time   = start_time + sec * CLOCKS_PER_SEC;

    
    int N; cin >> N;
    vector<int> B(3); cin >> B[0] >> B[1] >> B[2];
    vector<vector<int>> L(N, vector<int>(N,0));
    vector<vector<int>> R(N, vector<int>(N,0));
    REP(i,N) REP(j,N) cin >> L[i][j];
    REP(i,N) REP(j,N) cin >> R[i][j];

    int score; vector<vector<int>> ans(N,vector<int>(N,0));
    chokudai_search(B,L,R,score,ans,end_time); 

    debug(score)
    for(auto a:ans){cout << a;}
}