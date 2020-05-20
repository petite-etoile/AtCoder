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

vector<int64> dijkstra(vector<vector<pair<int64,int64>>> const& edge, int64 start, vector<int64>& previous){
    int64 N = edge.size();
    vector<int64> dist(N,INF);
    // vector<int64> previous(N,-1);
    priority_queue<tuple<int64,int64,int64>,vector<tuple<int64,int64,int64>>, greater<tuple<int64,int64,int64>> > q;
    q.push(make_tuple(0, start, -1));
    vector<bool> visited(N,false);
    
    int64 from,d;
    int64 to,cost,pre;
    while(!q.empty()){
        tie(d,from,pre) = q.top(); q.pop();
        if (visited[from]) continue;
        visited[from] = true;
        dist[from] = d;
        previous[from] = pre;
        for(auto e:edge[from]){
            tie(to,cost) = e;
            if (visited[to]) continue;
            if(chmin(dist[to], int64(d+cost)))
                q.push(make_tuple(d+cost, to, from));
        }
    }

    return dist;
}

bool similar(string s, string t){
    int N = s.size();
    REP(i,N){
        if(s[i]!=t[i]){
            return s.substr(i+1) == t.substr(i+1);
        }
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    string S,T;
    cin >> S >> T;
    cin >> N;
    vector<string> Str(N+2);
    REP(i,N){
        cin >> Str[i];
    }
    Str[N] = S;
    Str[N+1] = T;
    N+=2;
    vector<vector<pair<int64,int64>>> edge(N);
    REP(i,N){
        for(int j=i+1;j<N;j++){
            if(similar(Str[i],Str[j])) {
                edge[i].emplace_back(j,1);
                edge[j].emplace_back(i,1);
            }
        }
    }
    vector<int64> previous(N,-1);
    auto dist = dijkstra(edge, N-2, previous);
    if(dist[N-1] == INF){
        cout << -1 << bn;
    }else{
        stack<string> ans;
        ans.push(Str[N-1]);
        int now = N - 1;
        while(now != N-2){
            now = previous[now];
            ans.push(Str[now]);
        }
        cout << ans.size()-2 << bn;
        while(not ans.empty()){
            cout << ans.top() << bn; ans.pop();
        }
    }


}