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

bool dfs(int s, vector<vector<int>>& edge, vector<int>& dist){
    stack<int> st;
    st.push(s);
    while(not st.empty()){
        int v = st.top(); st.pop();
        for(auto u:edge[v]){
            if(dist[u]!=inf){
                if((dist[v]-dist[u])&1) continue;
                return true; //奇閉路
            }
            dist[u]=dist[v]+1;
            st.push(u);
        }
    }
    return false;
}

int bfs(int s, vector<vector<int>>& edge){
    int N = edge.size();
    queue<int> q;
    q.push(s);
    vector<int> dist(N,inf); dist[s]=1;

    int res = 0;
    while(not q.empty()){
        int v = q.front(); q.pop();
        for(auto u:edge[v]){
            if(dist[u]!=inf) continue;
            q.push(u);
            dist[u] = dist[v]+1;
            chmax(res, dist[u]);
        }
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int>> edge(N);
    REP(i,N){
        string t; cin >> t;
        REP(j,N){
            if(t[j]=='1') edge[i].emplace_back(j);
        }
    }

    vector<int> dist(N,inf);
    dist[0]=0;
    if(dfs(0,edge,dist)){
        cout << -1 << bn;
        return 0;
    }

    int ans=0;
    REP(i,N){
        chmax(ans, bfs(i,edge));
    }

    cout << ans << endl;
}