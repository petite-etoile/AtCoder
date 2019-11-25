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
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
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
os << "\n";
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
bool dfs(int s,vector<vector<int>>& edge,vector<int>& d){
    int N = edge.size();
    bool res = false;
    for(auto to:edge[s]){
        if(d[to]!=INF) {
            if((d[s]-d[to]) %2 == 0) {
                return true; 
            }
            else continue;
        }
        d[to]=d[s]+1;
        bool b = dfs(to,edge,d);
        if(b){ return true;}
    }
    return res;
}
int bfs(int s,vector<vector<int>>& edge){
    int N = edge.size();
    vector<int> dist(N,INF);
    queue<int> q; q.push(s);
    vector<bool> visited(N,0);
    visited[s]=1;
    dist[s]=0;
    int res=0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u:edge[v]){
            if(dist[u]!=INF) continue;
            q.push(u); dist[u] = dist[v]+1;
            chmax(res,dist[u]+1);
        }
    }
    return res;
}
//fixed<<setprecision(10)<<ans<<endl;
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    string s;
    vector<vector<int>> edge(N);
    REP(i,N){
        cin >> s;
        REP(j,N){
            if(s[j]=='0') continue;
            int to = j;
            edge[i].push_back(j);
            edge[j].push_back(i);
        }
    }
    //奇閉路検出
    vector<int> d(N,INF);
    d[0]=0;
    bool b = dfs(0,edge,d);
    if(b){
        cout << -1 << endl;
        exit(0);
    }

    int ans=0;
    REP(i,N){
        chmax(ans,bfs(i,edge));
    }

    cout << ans << endl;
}