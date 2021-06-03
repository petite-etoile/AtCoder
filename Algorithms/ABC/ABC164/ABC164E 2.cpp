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

const int64 MAX_COIN = 50*50+1;
vector<vector<int64>> dijkstra(vector<vector<tuple<int64,int64,int64>>> const& edge, int64 start, vector<pair<int64,int64>> const& CD, int64 coin_start){
    int64 N = edge.size();
    vector<vector<int64>> dist(N,vector<int64>(MAX_COIN+1,INF)); //dist[駅][銀貨]
    priority_queue<tuple<int64,int64,int64>,vector<tuple<int64,int64,int64>>, greater<tuple<int64,int64,int64>> > q;
    q.push(make_tuple(start, start, min(MAX_COIN,coin_start)));
    vector<vector<bool>> visited(N,vector<bool>(MAX_COIN+1,false));
    // vector<bool> exchanged(N,false);
    int64 from,d,coin;
    int64 to,cost_dist,cost_coin;
    while(!q.empty()){
        tie(d,from,coin) = q.top(); q.pop();
        // debug(mp(d,from))
        if (visited[from][coin]) continue;
        visited[from][coin] = true;
        dist[from][coin] = d;

        int64 a,b; tie(a,b) = CD[from];
        for(auto e:edge[from]){
            tie(to,cost_dist,cost_coin) = e;
            int64 to_coin = coin - cost_coin;
            if (to_coin < 0 or visited[to][coin]) continue;

            if(chmin(dist[to][to_coin], int64(d+cost_dist))){
                q.push(make_tuple(d+cost_dist, to, to_coin));
            }
        }

        coin += a;
        chmin(coin,MAX_COIN);
        d += b;
        if(not visited[from][coin] and chmin(dist[from][coin], d)){
            q.push(make_tuple(d,from,coin));
        }
    }

    return dist;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false); 
    int N,M,S; cin >> N >> M >> S;
    vector<vector<tuple<int64,int64,int64>>> edge(N);
    REP(i,M){
        int64 u,v,a,b;
        cin >> u >> v >> a >> b; u--,v--;
        edge[u].emplace_back(v,b,a);
        edge[v].emplace_back(u,b,a);
    }
    vector<pair<int64,int64>> CD;
    REP(i,N){
        int64 c,d; cin >> c >> d;
        CD.emplace_back(c,d);
    }

    auto dist = dijkstra(edge,0,CD,S);
    for(int i=1;i<N;i++){
        cout << *min_element(ALL(dist[i])) << bn;
    }


}