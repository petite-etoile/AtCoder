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
ostream& operator<<(ostream& os, set<T> const&S){
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

int64 calc_score(int D, vector<int64> const& C, vector<vector<int64>> const& S, vector<int> T);
vector<set<int>> init_set(int D, vector<int> const& T);

int64 replace_contest(int D, vector<int64> const& C, vector<vector<int64>> const& S, vector<int>& T, int64 pre_val, int date, int q, vector<set<int>>& contest_schedule);

int prev_contest(int date, int contest, vector<set<int>> const& contest_schedule){
    return *--contest_schedule[contest].lower_bound(date);
}

int next_contest(int date, int contest, vector<set<int>> const& contest_schedule){
    return *contest_schedule[contest].upper_bound(date);
}

int64 f(int date, int contest, vector<int> const& last, vector<int64> const& C, vector<vector<int64>> const& S);

vector<int> greedy(int D, vector<int64> const& C, vector<vector<int64>> const& S);

unsigned long xor128();
const int rand_max = (1<<30) - 1;



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int D; cin >> D;

    vector<int64> C(26);
    REP(i,26) cin >> C[i];

    vector<vector<int64>> S(D, vector<int64>(26));
    REP(i,D) REP(j,26) cin >> S[i][j];

    vector<int> T = greedy(D, C, S);
    
    auto score = calc_score(D, C, S, T);

    auto contest_schedule = init_set(D, T);

    clock_t start = clock();
    clock_t stop = start + 19 * CLOCKS_PER_SEC / 20;
    int contest, date;
    while(true){
        if(clock() >= stop){
            break;
        }
        REP(_,5){
            // ----replace_contest----
            int contest = xor128() % 26;
            int date = xor128() % D;
            if(T[date] == contest) continue;

            int ori = T[date];
            int64 new_val = replace_contest(D, C, S, T, score, date, contest, contest_schedule);
            if(new_val > score){
                //解を更新
                score = new_val;
            }else{
                //解を更新しないので戻す
                T[date] = ori;
                contest_schedule[contest].erase(date);
                contest_schedule[ori].insert(date);
            }

            // ----swap_date----
            int date1 = xor128() % D, date2 = xor128() % D;
            int contest1 = T[date1], contest2 = T[date2];
            if(date1 == date2 or contest1 == contest2) continue;

            int64 tmp_val = replace_contest(D, C, S, T, score, date1, contest2, contest_schedule);
            new_val = replace_contest(D, C, S, T, tmp_val, date2, contest1, contest_schedule);

            if(new_val > score){
                //解を更新
                score = new_val;
            }else{
                //解を更新しないので戻す
                T[date1] = contest1;
                T[date2] = contest2;
                contest_schedule[contest1].erase(date2);
                contest_schedule[contest2].erase(date1);
                contest_schedule[contest1].insert(date1);
                contest_schedule[contest2].insert(date2);
            }



        }
    }

    for(auto t:T) cout << t+1 << bn;
}

unsigned long xor128() {
    static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
    unsigned long t=(x^(x<<11));
    x=y; y=z; z=w;
    return ( w=(w^(w>>19))^(t^(t>>8)) );
}

int64 f(int date, int contest, vector<int> const& last, vector<int64> const& C, vector<vector<int64>> const& S){
    int64 res = S[date][contest];
    REP(j,26) if(j!=contest) res -= C[j] * (date - last[j]);
    return res; 
}

int64 replace_contest(int D, vector<int64> const& C, vector<vector<int64>> const& S, vector<int>& T, int64 pre_val, int date, int q, vector<set<int>>& contest_schedule){
    int64 new_val = pre_val;
    int p = T[date];
    
    //1. date日目のコンテストpに関して,lastなんたらでの満足度低下が増える
    new_val -= C[p] * ( date - prev_contest(date, p, contest_schedule) ) * (next_contest(date, p, contest_schedule) - date);
    //2.          コンテストqに関して,lastなんたらでの満足度低下が減る
    new_val += C[q] * ( date - prev_contest(date, q, contest_schedule) ) * (next_contest(date, q, contest_schedule) - date);
    //3. p,qに関して満足度が増える
    new_val += S[date][q] - S[date][p];
    
    contest_schedule[q].insert(date);
    contest_schedule[p].erase(date);
    T[date] = q;

    return new_val;
}

int64 calc_score(int D, vector<int64> const& C, vector<vector<int64>> const& S, vector<int> T){
    int64 score = 0;
    vector<int> last(26, -1);
    vector<int64> res(D);
    REP(i,D){
        last[T[i]] = i;
        score += S[i][T[i]];
        REP(j,26){
            score -= C[j] * (i-last[j]);
        }
        res[i] = score;
    }
    return score;
    // return res;
}

vector<set<int>> init_set(int D, vector<int> const& T){
    vector<set<int>> res(26);
    REP(i,26){
        res[i].insert(-1);
        res[i].insert(D);
    }
    REP(date, D){
        res[T[date]].insert(date);
    }
    return move(res);
}

vector<int> greedy(int D, vector<int64> const& C, vector<vector<int64>> const& S){
    vector<int> last(26,-1);
    vector<int> T(D,-1);

    int64 tmp = 0;
    REP(date,D){
        int best_contest; int64 best_val = -INF;
        REP(j,26){
            auto val = f(date, j, last, C, S);
            if(best_val < val){
                best_contest = j;
                best_val = val;
            }
        }
        last[best_contest] = date;
        T[date] = best_contest;
        tmp += best_val;
    }
    return T;
}