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

int dijkstra(vector<vector<pair<int,int>>> const& edge, int64 start){
    int64 N = edge.size();
    vector<int> dist(N,inf);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > q;
    q.push(mp(0, start));
    vector<bool> visited(N,false);
    
    int64 from,d;
    int64 to,cost;
    while(!q.empty()){
        tie(d,from) = q.top(); q.pop();
        if (visited[from]) continue;
        visited[from] = true;
        dist[from] = d;
        for(auto e:edge[from]){
            tie(to,cost) = e;
            if (visited[to]) continue;
            if(chmin(dist[to], int(d+cost)))
                q.push(mp(d+cost, to));
        }
    }

    return dist.back();
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    //Taxiの複数形Taxisまじ？

    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> Taxis(N);
    int a,b;
    REP(i,N){
        cin >> a >> b;
        Taxis[i] = mp(a,b);
    }
    vector<vector<int>> edge(N);
    REP(i,M){
        cin >> a >> b;
        edge[--a].emplace_back(--b);
        edge[b].emplace_back(a);
    }
    vector<vector<pair<int,int>>> edge2(N);
    int cost, step_max;
    REP(i,N){
        tie(cost,step_max) = Taxis[i];  
        queue<int> q;
        q.push(i);
        vector<bool> visited(N);
        REP(step,step_max){
            queue<int> tmp;
            while(not q.empty()){
                int v = q.front(); q.pop();
                if(visited[v]) continue;
                visited[v] = true;
                for(auto to:edge[v]){
                    if(visited[to]) continue;
                    tmp.push(to);
                    edge2[i].emplace_back(to,cost);
                }
            }
            q = tmp;
        }
    }

    int ans=dijkstra(edge2,0);

    cout << ans << endl;
}