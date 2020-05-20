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
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
#pragma endregion
//fixed<<setprecision(10)<<ans<<endl;

//木が完全マッチングを作れるかどうか判定する O(N)
bool is_perfect_matching_graph(const vector<vector<int>>& edge){
    int N = edge.size();
    vector<int> degree(N,0);
    vector<bool> visited(N,false);
    queue<int> q;
    REP(i,N){
        degree[i] = edge[i].size();
        if(degree[i] == 1) q.push(i);
    }
    while(not q.empty()){
        int v = q.front(); q.pop();
        if(visited[v]) continue;
        visited[v] = true;
        int pair_of_v = -1;
        for(auto to:edge[v]){
            if(visited[to]) continue;
            pair_of_v = to;
        }
        if(pair_of_v==-1) return false;
        visited[pair_of_v] = true;
        for(auto to:edge[pair_of_v]){
            if(visited[to]) continue;
            degree[to]--;
            if(degree[to] == 1){
                q.push(to);
            }
        }
    }
    return true;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int a,b;
    vector<vector<int>> edge(N);
    REP(i,N-1){
        cin >> a >> b;
        edge[--a].emplace_back(--b);
        edge[b].emplace_back(a);
    }
    if(is_perfect_matching_graph(edge)) cout << "Second" << bn;
    else cout << "First" << bn;
}