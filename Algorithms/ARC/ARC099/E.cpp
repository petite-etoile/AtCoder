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

vector<vector<int>> get_complement_graph(vector<vector<int>> const& edge){
    int N = edge.size();
    vector<vector<int>> res(N);
    vector<vector<bool>> tmp(N,vector<bool>(N,true));
    
    REP(i,N){
        tmp[i][i] = false;
        for(auto to:edge[i]){
            tmp[i][to] = false;
        }
        REP(j,N){
            if(tmp[i][j]) res[i].emplace_back(j);
        }
    }
    return move(res);
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

    /*
        問題を言い換えると出来るだけ多くの辺を取り除いてクリークを(ちょうど)２つ作る
        取り除いたあとのグラフの辺数最小化
        クリークは補グラフで非連結となっていて、2つのクリークだけのグラフは補グラフで完全二部グラフになっているので、補グラフ出来るだけ多くの辺を追加して完全二部グラフを作る問題に帰着する
    */
    edge = get_complement_graph(edge); //補グラフを取得


    vector<int> color(N,-1); //その連結成分での二部グラフでの所属
    vector<pair<int,int>> cnt;

    REP(i,N){
        if(color[i] != -1) continue;
        queue<int> q({i});
        cnt.emplace_back(1,0);
        color[i] = 0;
        while(not q.empty()){
            int v; v = q.front(); q.pop();
            for(auto to:edge[v]){
                if(color[to] == -1){
                    color[to] = color[v] ^ 1;
                    q.push(to);
                    if(color[to]) cnt.back().second++;
                    else cnt.back().first++;
                }
                else if(color[to] != color[v] ^ 1){
                    cout << -1 << bn;
                    return 0;
                }
            }
        }
        // add_edge_cnt += cnt.back().first * cnt.back().second; //この連結成分を完全二部グラフにしたときに張らないといけない辺の数
    }

    /*
        各連結成分から二部グラフのどちらかのグループを選ぶを繰り返して、集合Sを作ると、選ばなかったグループの和集合Tと二部グラフに出来る。
        グループ間でS,Tを張る辺の数は|S|*|T|であり、選出可能なSの大きさを列挙することで実行可能解を探索する
    */
    int Z = cnt.size();
    vector<vector<bool>> subset_size(Z+1,vector<bool>(N,false));
    subset_size[0][0] = true;
    REP(i,Z){
        int a,b; tie(a,b) = cnt[i];
        REP(s,N){
            if(not subset_size[i][s]) continue;
            subset_size[i+1][s+a] = true;
            subset_size[i+1][s+b] = true;
        }
    }

    int add_edge_cnt = 0; //補グラフで完全二部グラフを作ってそのグラフでの辺の数から、すでにある辺の数を最後に引く
    int max_edge_cnt = 0; //考えられる完全二部グラフでの辺数最大
    REP(s,N){
        if(not subset_size.back()[s]) continue;
        int t = N-s;
        chmax(max_edge_cnt, s*t);
    }
    int edge_cnt = N*(N-1)/2 - M; //もともとの補グラフでの辺数
    add_edge_cnt = max_edge_cnt - edge_cnt;
    int ans = M - add_edge_cnt; //補グラフで加えた辺の数 = 元のグラフで除いた辺の数. 目的関数は 元の辺の数 - 除いた辺の数
    cout << ans << bn;
}