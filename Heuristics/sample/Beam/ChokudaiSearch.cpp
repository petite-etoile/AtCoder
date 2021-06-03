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



//----局面の状態----
class State{
    public:
    int score;
    int raw_score;
    vector<char> sol;

    State(){
    }

    State(int const& score_, int const& raw_score_, vector<char> const& sol_){
        score = score_;
        raw_score = raw_score_;
        sol = sol_;
    }

    bool operator<(const State& S2) const{
        return this->score < S2.score;
    }

    bool operator>(const State& S2) const{
        return this->score > S2.score;
    }
};

//(設計した評価関数での)スコアの変化量を返す
int add_score(vector<vector<int>> const& P, pair<int,int> place){
    const int coef = 10; //
    int added_score = 0;//(設計した評価関数での)スコアの変化量
    return added_score;
}

//(生の)スコアの変化量を返す
int add_raw_score(){
    int added_score = 0; //(生の)スコアの変化量
    return added_score;
}

const int DEPTH_MAX = 0; //解の長さの上限

void chokudai_search(int& ans_score, vector<char>& ans, clock_t end_time){

    vector<multiset<State>> priq_vec(DEPTH_MAX); //各深さごとの(スコア, 局面)を昇順でもつ 状態が大きくなりすぎてMLEするので定期的に削除できるようにmultiset

    /*状態変数の定義*/
    vector<char> sol; sol.reserve(DEPTH_MAX); //解
    int before_score = 0; //評価関数のスコア
    int before_raw_score = 0; //生のスコア
    
    for(int depth=0; depth<DEPTH_MAX; depth++){

        /*
        for(auto 選択:選択肢){
            sol[depth] = 選択
            if(許容解ではない) continue;

            int new_score = before_score + add_score(); //評価関数でのスコア
            int new_raw_score = before_raw_score + add_raw_score(); //生のスコア
            //他の状態変数もあるなら更新する
            
            priq_vec[depth].insert(State(new_score, new_raw_score, sol));

            //状態変数を戻す必要があるなら戻す

        }
        
        //これ以上の深さに行けないなら終わる
        if(priq_vec[depth].empty()) {
            move.pop_back();
            break;
        }
        
        
        before_score = (*--priq_vec[depth].end()).score;
        before_raw_score = (*--priq_vec[depth].end()).raw_score;
        sol = (*--priq_vec[depth].end()).sol;
        */

    }


    while(true){
        clock_t now = clock();

        if(now >= end_time){
            return;
        }

        //各深さについて、今まで探索したやつで一番いいやつを使って次を探索
        for(int depth=1; depth<=DEPTH_MAX; depth++){
            if(priq_vec[depth-1].empty()){ continue;} //priqが空

            State before_state = *--priq_vec[depth-1].end(); priq_vec[depth-1].erase(--priq_vec[depth-1].end()); //１個前の局面の一番いいやつ
            int& before_score = before_state.score;
            int& before_raw_score = before_state.raw_score;
            vector<char>& sol = before_state.sol;
            
            /*
            for(auto 選択:選択肢){
                sol[depth] = 選択
                if(許容解ではない) continue;

                int new_score = before_score + add_score(); //評価関数でのスコア
                int new_raw_score = before_raw_score + add_raw_score(); //生のスコア
                //他の状態変数もあるなら更新する
                
                priq_vec[depth].insert(State(new_score, new_raw_score, sol));

                //状態変数を戻す必要があるなら戻す



                if(new_raw_score > ans_score){
                    ans = sol;
                    ans_score = new_raw_score;
                }

            }
            
            */
        }
    }

}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    /*実行時間設定*/
    const double sec = 1.6;    
    
    clock_t start_time = clock();
    clock_t end_time   = start_time + sec * CLOCKS_PER_SEC;

    /*入力*/


    int score = 0; vector<char> ans;
    chokudai_search(score,ans,end_time); 

    debug(score)


}