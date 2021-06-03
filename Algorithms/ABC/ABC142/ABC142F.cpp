#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef vector<int> vi;
const int MOD = (int)1e9 + 7;
const int INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = s; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
#define mp make_pair
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
template <typename T>
ostream& operator<<(ostream& os, pair<T,T> &P){
    os << P.first;
    os << " ";
    os << P.second;
    os << endl;
    return os;
}
//fixed<<setprecision(10)<<ans<<endl;
int N,M;
set<int> ng_nodes;
vector<int> answer;
vector<vector<int>> edge;

vector<int> bfs(int s){ 
    vector<int> dist(N,INF),pre(N);//pre(N); pre[s]=-1; 経路復元するなら
    queue<int> q; q.push(s);
    dist[s]=0;
    pre[s]=-1;
    while(!q.empty()){
        int v = q.front(); q.pop();

        for(auto u:edge[v]){
            if(dist[u]!=INF) continue;
            q.push(u); dist[u] = dist[v]+1;
            pre[u] = v;
        }
    }
    debug(dist);

    //サイクル検出
    pair<int,int> best(INF,-1);
    REP(v,N){
        if(v==s) continue;
        for(auto u:edge[v]){
            if(u==s){
                chmin(best,mp(dist[v],v));
            }
        }
    }
    debug(best);
    if(best.first == INF) return vector<int>(N+1); //サイクルなし
    //経路復元
    vector<int> res; int v = best.second;
    while(v!=-1){
        res.push_back(v+1);
        v=pre[v];
    }
    debug(res);
    return res;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    edge.resize(N);
    REP(i,M){
        int a,b;
        cin >> a >> b;
        a--;b--;
        edge[a].push_back(b);
    }
    vector<int> ans(N+2);
    REP(s,N){
        vi now = bfs(s);
        if(now.size() < ans.size()){
            ans = now;
        }
    }
    if(ans.size() > N)cout << -1 << endl;
    else{
        cout << ans.size() << endl;
        cout << ans;
    }
}
