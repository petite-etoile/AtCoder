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


int N,M,X;
vector<int> T;
vector<vector<vector<int>>> dijkstra(vector<vector<pair<int,int>>> const& edge, int start){
    vector<vector<vector<int>>> dist(N,vector<vector<int>>(X+1,vector<int>(2,inf)));
    priority_queue< tuple<int,int,int,int>,vector<tuple<int,int,int,int>>, greater<tuple<int,int,int,int>> > q;
    vector<vector<vector<bool>>> visited(N,vector<vector<bool>>(X+1,vector<bool>(2,false)));

    
    q.push(make_tuple(0,start,0,T[start]));
    int from,d,from_tmp,x;
    int to,cost,to_tmp;

    while(!q.empty()){
        tie(d,from,x,from_tmp) = q.top(); q.pop();
        if (visited[from][x][from_tmp]) continue;
        visited[from][x][from_tmp] = true;
        dist[from][x][from_tmp] = d;
        for(auto e:edge[from]){
            tie(to,cost) = e;
            if(T[to] == 2){
                if (visited[to][min(X,x+cost)][from_tmp]) continue;
                q.push(make_tuple(d+cost, to, min(X,x+cost), from_tmp));
            }else if(T[to]==from_tmp){
                if (visited[to][0][T[to]]) continue;
                q.push(make_tuple(d+cost, to, 0, T[to]));
            }else if(x+cost>=X){
                if (visited[to][0][T[to]]) continue;
                q.push(make_tuple(d+cost, to, 0, T[to]));
            }
        }
    }

    return dist;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> X;
    T.resize(N);
    REP(i,N) cin >> T[i];
    REP(i,N) {
        if(T[i]==2){
            T[i]=1;
        }else if(T[i]==1){
            T[i]=2;
        }
    }

    vector<vector<pair<int,int>>> edge(N);
    int a,b,c;
    REP(i,M){
        cin >> a >> b >> c;
        --a;--b;

        edge[a].emplace_back(b,c);
        edge[b].emplace_back(a,c);
    }

    auto ans = inf;
    auto res = dijkstra(edge,0);
    REP(x,X+1){
        REP(t,2){
            chmin(ans, res[N-1][x][t]);
        }
    }


    cout << ans << endl;
}
