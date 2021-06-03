/*

はじめてのびぃむさぁち。
多様性がカス(最初の方はスコアが同じようなのだから)　かもしれん
これがうまくいったらちょくだいさぁちもしてみる


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
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
#pragma endregion
//fixed<<setprecision(10)<<ans<<endl;

int calc_score_naive(vector<vector<int>> const& board, vector<int> const& B){
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

// 累積和を用いて高速にできる(今はいいや)
// int calc_score(vector<vector<int>> const& board, int B1, int B2, int B3){
//     int res = 0;
//     REP(col,N){
//         REP(i,N){

//         }
//     }
//     return res;
// }

int get_added_score(int i_, int j_, vector<vector<int>> const& board, vector<int> const& B){
    int res = 0, now;

    //tate
    now = 0;
    for(int i=i_; i>=0; i--){
        now += board[i][j_];
        if(now == B[0]) res += B[0] ;
        else if(now == B[1]) res += B[1];
        else if(now == B[2]) res += B[2];
        else if(now > B[2]) break;
    }
    
    //yoko
    now = 0;
    for(int j=j_; j>=0; j--){
        now += board[i_][j];
        if(now == B[0]) res += B[0] ;
        else if(now == B[1]) res += B[1];
        else if(now == B[2]) res += B[2];
        else if(now > B[2]) break;
    }

    // debug(res)
    return res;
}

void beam_search(vector<int> const& B, vector<vector<int>> const& L, vector<vector<int>> const& R, int& score, vector<vector<int>>& ans){
    int beam_width = 120; //ビーム幅
    int N = L.size();
    
    int init_score = 0; vector<vector<int>> init_board(N,vector<int>(N,0));
    pair<int, vector<vector<int>> > init_pair(init_score, init_board);

    vector<pair<int, vector<vector<int>>>> last_boards = {init_pair};

    REP(i,N){
        REP(j,N){
            vector<pair<int, vector<vector<int>>>> new_boards; //直前の深さから1個深いところにある解(直前捨てなかった解からの遷移のみ)
            int l = L[i][j], r = R[i][j];
            for(auto last_score_and_board : last_boards){
                int last_score; vector<vector<int>> last_board;
                tie(last_score, last_board) = last_score_and_board;

                for(int x=l; x<=r; x++){
                    vector<vector<int>> new_board = last_board; //一手前の盤面(last_board)からi,jをxにした盤面
                    // assert(new_board[i][j] == 0);
                    new_board[i][j] = x;
                    
                    int new_score = last_score + get_added_score(i,j,new_board,B);
                    // debug(new_score)
                    // assert(new_score == calc_score_naive(new_board, B));


                    new_boards.emplace_back(new_score, new_board);
                }
            }

            //new_boardsをスコア順にソートして, 大きいのからbeam_width個だけを残してlast_boardsとする.
            sort(ALL(new_boards), greater<pair<int,vector<vector<int>>>>());
            // debug(new_boards)
            if(new_boards.size() > beam_width)new_boards.erase(new_boards.begin() + beam_width, new_boards.end());
            // debug("A")
            last_boards = new_boards;
            // debug(last_boards.size());
        }
    }

    // debug(last_boards[0])
    tie(score,ans) = last_boards[0];




}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> B(3); cin >> B[0] >> B[1] >> B[2];
    vector<vector<int>> L(N, vector<int>(N,0));
    vector<vector<int>> R(N, vector<int>(N,0));
    REP(i,N) REP(j,N) cin >> L[i][j];
    REP(i,N) REP(j,N) cin >> R[i][j];

    vector<vector<int>> board(N, vector<int>(N,0));
    int score; vector<vector<int>> ans;
    beam_search(B,L,R,score,ans); 

    for(auto a:ans){cout << a;}


}