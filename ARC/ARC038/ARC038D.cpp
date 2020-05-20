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

vector<int> P;
vector<vector<int>> edge_rev;
bool is_ok(int64 D,vector<int> degree){
    int N = edge_rev.size()/2;
    vector<bool> visited(2*N,false);
    vector<char> win(2*N,-1);
    queue<int> q;
    REP(i,N){
        if(P[i]>=D){ //先手勝ち
            win[i] = 1;
            q.push(i);
            visited[i] = true;
            if(degree[i+N]==0){
                win[i+N] = 0;
                q.push(i+N);
                visited[i+N] = true;
            }
        }else{ //後手勝ち
            win[i+N] = 1;
            q.push(i+N);
            visited[i+N] = true;
            if(degree[i]==0){
                win[i] = 0;
                q.push(i);
                visited[i] = true;
            }
        }
    }

    //後退解析
    while(not q.empty()){
        int v = q.front(); q.pop();
        for(auto to:edge_rev[v]){
            if(visited[to]) continue;
            degree[to]--;
            if(win[v]==0){ //相手を負けに出来る
                win[to] = 1;
                q.push(to);
                visited[to] = true;
            }else if(win[v]==1){
                if(degree[to]==0){ //どうやっても行き先は相手の勝ち
                    win[to] = 0;
                    q.push(to);
                    visited[to] = true;
                }
            }
        }
    }

    return win[0]==1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    edge_rev.resize(2*N);
    vector<int> degree(2*N,0);
    P.resize(N);
    REP(i,N) cin >> P[i];
    int a,b;
    REP(i,M){
        cin >> a >> b;
        edge_rev[--b].emplace_back(--a+N);
        edge_rev[b+N].emplace_back(a  );
        degree[a  ]++;
        degree[a+N]++;
    }

    int64 ok = 0, ng = 1e9+1;
    while(ng-ok>1){
        int64 mid = (ok+ng)/2;
        if(is_ok(mid, degree)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}


// /*
// 　　　∫ ∫ ∫
// 　　　ノヽ
// 　　（＿　 ）
// 　（＿　　　 ）
// （＿＿＿＿＿＿ ）
// 　ヽ(´･ω･)ﾉ　
// 　　 |　 /
// 　　 UU
// */
// #pragma region macro
// #include <bits/stdc++.h>
// typedef long long int64;
// using namespace std;
// typedef vector<int> vi;
// const int MOD = (int)1e9 + 7;
// const int64 INF = 1LL << 62;
// const int inf = 1<<30;
// template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
// template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
// #define REP(i, n) for (int i = 0; i < (n); i++)
// #define FOR(i,s,n) for (int i = s; i < (n); i++)
// #define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
// #define debug(x) cerr << #x << ": " << x << "\n";
// #define mp make_pair
// #define bn '\n'
// template <typename T>
// ostream& operator<<(ostream& os, vector<T> &V){
//     int N = V.size();
//     REP(i,N){
//         os << V[i];
//         if (i!=N-1) os << " ";
//     }
//     os << "\n";
//     return os;
// }
// template <typename T,typename S>
// ostream& operator<<(ostream& os, pair<T,S> const&P){
//     os << "(";
//     os << P.first;
//     os << " , ";
//     os << P.second;
//     os << ")";
//     return os;
// }
// template <typename T>
// ostream& operator<<(ostream& os, set<T> &S){
//     auto it=S.begin();
//     while(it!=S.end()){
//         os << *it;
//         os << " ";
//         it++;
//     }
//     os << "\n";
//     return os;
// }
// template <typename T>
// ostream& operator<<(ostream& os, deque<T> &q){
//     for(auto it=q.begin();it<q.end();it++){
//         os<<*it;
//         os<<" ";
//     }
//      os<<endl;
//     return os;
// }
// vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
// #pragma endregion
// //fixed<<setprecision(10)<<ans<<endl;

// vector<vector<vector<int64>>> memo;
// vector<vector<int>> edge;
// vector<int64> P;
// int N;
// int64 solve(int turn, int v, bool B_turn){
//     if(turn>=2*N) return P[v];
//     if(memo[turn][v][B_turn]!=-1) return memo[turn][v][B_turn];
//     int64 res;
//     if(B_turn){
//         res = P[v];
//         for(auto x:edge[v]){
//             chmin(res, solve(turn+1, x, B_turn^1));
//         }
//     }else{
//         res = P[v];
//         for(auto x:edge[v]){
//             chmax(res, solve(turn+1, x, B_turn^1));
//         }
//     }
//     memo[turn][v][B_turn] = res;
//     return res;

// }

// int main(){
//     cin.tie(0);
//     ios::sync_with_stdio(false);
//     int M;
//     cin >> N >> M;
//     memo.assign(2*N,vector<vector<int64>>(N,vector<int64>(2,-1)));
//     edge.resize(N);
//     P.resize(N);
//     REP(i,N) cin >> P[i];
//     int a,b;
//     REP(i,M){
//         cin >> a >> b;
//         a--;b--;
//         edge[a].push_back(b);
//     }

//     cout << solve(0,0,0) << endl;
// }