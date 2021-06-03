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
//fixed<<setprecision(10)<<ans<<endl;

vector<int64> dijkstra(vector<vector<pair<int64,int64>>> const& edge, int64 start){
    int64 N = edge.size();
    vector<int64> dist(N,INF);
    priority_queue<pair<int64,int64>,vector<pair<int64,int64>>, greater<pair<int64,int64>> > q;
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
            if(chmin(dist[to], int64(d+cost)))
                q.push(mp(d+cost, to));
        }
    }

    return dist;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N,M,R,T; cin >> N >> M >> R >> T;
    vector<vector<pair<int64,int64>>> edge(N);
    REP(i,M){
        int a,b,c; cin >> a >> b >> c;
        edge[--a].emplace_back(--b,c);
        edge[b].emplace_back(a,c);
    }

    int64 ans=0;
    REP(A,N){
        auto dist = dijkstra(edge, A);
        sort(ALL(dist));
        for(int C=1;C<N;C++){
            auto d = dist[C];
            ans += N - (upper_bound(ALL(dist), d*R/T) - dist.begin());
            if(R<T) ans--;
        }
    }

    cout << ans << endl;
}