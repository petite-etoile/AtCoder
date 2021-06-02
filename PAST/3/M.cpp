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

vector<int> bfs(int s, vector<vector<int>>const& edge){
    int N = edge.size();
    vector<int> dist(N, inf); dist[s] = 0;
    queue<int> q; q.push(s);
    while(not q.empty()){
        int v; v = q.front(); q.pop();
        for(auto to:edge[v]){
            if(dist[to] != inf) continue;
            dist[to] = dist[v] + 1;
            q.push(to);
        }
    }
    return move(dist);
}
string bin(int n){
    string s = "";
    while(n>0){
        string b = to_string(n%2);
        s = b+s;
        n>>=1;
    }
    return s;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    vector<vector<int>> edge(N);
    REP(i,M){
        int a,b; cin >> a >> b;
        edge[--a].emplace_back(--b);
        edge[b].emplace_back(a);
    }
    int s; cin >> s; s--;
    int K; cin >> K;

    vector<int> enc(K);
    vector<int> T(K);
    REP(i,K){
        int t; cin >> t; t--; T[i]=t; 
        enc[i] = t;
    }
    vector<vector<int64>> cost(K,vector<int64>(K,0));
    REP(i,K){
        auto dist = bfs(T[i], edge);
        REP(j,K){
            cost[i][j] = dist[enc[j]];
        }
    }
    vector<vector<int64>> DP(1<<K, vector<int64>(K, INF));
    auto dist = bfs(s,edge);
    // debug(dist)
    REP(k,K){

        DP[0][k] = dist[enc[k]];
    }
    REP(mask, 1<<K){
        REP(from,K){
            REP(to,K){
                auto c = cost[from][to];
                chmin(DP[mask|(1<<to)][to], DP[mask][from] + c);
            }
        }
    }
    int64 ans=*min_element(ALL(DP[(1<<K)-1]));
    cout << ans << endl;
}