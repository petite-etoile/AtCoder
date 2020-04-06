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

struct StronglyConnectedComponents{
    vector<int> topological_index; //属する強連結成分のトポロジカル順序
    vector<bool> visited;
    vector<vector<int>> edge, edge_rev;
    vector<int> post_order;
    int N;
    int scc_size = 0; //強連結成分の数

    //O(N+M)
    StronglyConnectedComponents(vector<vector<int>>& edge):edge(edge){
        N = edge.size();
        edge_rev.resize(N);
        for(int v=0;v<N;v++){
            for(auto to:edge[v]){
                edge_rev[to].emplace_back(v);
            }
        }
        visited.assign(N,false);
        topological_index.resize(N);
        for(int i=0;i<N;i++){
            if(not visited[i]) dfs(i);
        }
        visited.assign(N,false);
        reverse(post_order.begin(), post_order.end());
        for(auto v:post_order){
            if(not visited[v]) dfs_rev(v,scc_size++);
        }
    }

    void dfs(int v){
        visited[v] = true;
        for(auto to:edge[v]){
            if(not visited[to]) dfs(to);
        }
        post_order.emplace_back(v);
    }

    void dfs_rev(int v, int idx){
        visited[v] = true;
        topological_index[v] = idx;
        for(auto to:edge_rev[v]){
            if(not visited[to]) dfs_rev(to, idx);
        }
    }

    //vが属している強連結成分のトポロジカル順序
    int get_topological_index(int v){
        return topological_index[v];
    }

    //強連結成分の数
    int get_scc_size(){
        return scc_size;
    }

    vector<vector<int>> build_graph(){
        vector<vector<int>> new_edge(N);
        for(int i=0;i<N;i++){
            int topo = topological_index[i];
            for(auto to:edge[i]){
                new_edge[topo].emplace_back(topological_index[to]);
            }
        }
        for(int i=0;i<scc_size;i++){
            sort(new_edge[i].begin(), new_edge[i].end());
            new_edge[i].erase(unique(new_edge[i].begin(), new_edge[i].end()), new_edge[i].end());
        }
        return new_edge;
    }

};


int N;
vector<int64> X,Y; 
vector<int> X_idx,Y_idx; //それぞれZの何番目の要素か
vector<pair<int64,int>> Z; //XとYを混ぜてソートしたもの。
int leaf_cnt = 1;
//[L,R)にfromから辺を張る に相当する
void add_edge(int L,int R,int from,vector<vector<int>>& edge){
    for(int l=L+leaf_cnt, r=R+leaf_cnt; l<r; l>>=1, r>>=1){
        if(l&1) edge[from].emplace_back(l++);
        if(r&1) edge[from].emplace_back(--r);
    }
}

//ポケットモンスター 最小距離がd以上にできる/できない
bool is_ok(int64 d){
    d--; 
    while(leaf_cnt<=N*2*2){
        leaf_cnt<<=1;
    }
    vector<vector<int>> edge(2*leaf_cnt); //セグ木状に。

    for(int i=2;i<leaf_cnt;i++){ //1-indexedです 上から下に有向辺を張る
        edge[i].emplace_back(i<<1|0);
        edge[i].emplace_back(i<<1|1);
    }

    REP(i,N){
        //xかyのちょうど片方だけ使うという関係を張っておくことでもうこれ以降は独立したものとして扱える
        // edge[X_idx[i]  +leaf_cnt].emplace_back(Y_idx[i]+2*N+leaf_cnt); //x => not y
        edge[X_idx[i]+2*N+leaf_cnt].emplace_back(Y_idx[i]  +leaf_cnt); //not x => y
        // edge[Y_idx[i]  +leaf_cnt].emplace_back(Y_idx[i]+2*N+leaf_cnt); //y => not x
        edge[Y_idx[i]+2*N+leaf_cnt].emplace_back(X_idx[i]  +leaf_cnt); //not y => x
    }

    int left_index, right_index;
    REP(i,N){
        int64 x = X[i];
        left_index = lower_bound(ALL(Z), mp(x-d,0)) - Z.begin();   //左端(閉区間)
        right_index = lower_bound(ALL(Z), mp(x+d+1,0)) - Z.begin();//右端(開区間)
        add_edge(left_index +2*N, X_idx[i]+2*N, X_idx[i]+leaf_cnt, edge);    // x => not b (X_iより前)
        add_edge(X_idx[i]+1 +2*N, right_index+2*N, X_idx[i]+leaf_cnt, edge); // x => not b (X_iより後)

        int64 y = Y[i];
        left_index = lower_bound(ALL(Z), mp(y-d,0)) - Z.begin();    //左端(閉区間)
        right_index = lower_bound(ALL(Z), mp(y+d+1,0)) - Z.begin(); //右端(開区間)
        add_edge(left_index +2*N, Y_idx[i]+2*N,    Y_idx[i]+leaf_cnt, edge); // y => not b (Y_iより前)
        add_edge(Y_idx[i]+1 +2*N, right_index+2*N, Y_idx[i]+leaf_cnt, edge); // y => not b (Y_iより後)
    }

    StronglyConnectedComponents SCC(edge);
    
    bool valid = true;
    REP(i,N){
        if(SCC.get_topological_index(i+leaf_cnt) == SCC.get_topological_index(i+2*N+leaf_cnt)){
            valid = false;
        }
    }
    return valid;

}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    X_idx.resize(N);
    Y_idx.resize(N);
    int x,y;
    REP(i,N){
        cin >> x >> y;
        Z.emplace_back(x,i);
        Z.emplace_back(y,i+N);
        X.emplace_back(x);
        Y.emplace_back(y);
    }
    sort(ALL(Z));

    REP(i,N){
        //ソートされたあとの配列でx,yがそれぞれ何番目か
        X_idx[i] = lower_bound(ALL(Z), make_pair(X[i],i  )) - Z.begin();
        Y_idx[i] = lower_bound(ALL(Z), make_pair(Y[i],i+N)) - Z.begin();
    }

    int64 ok = 0, ng = 1e9;
    while( ng-ok > 1){
        int64 mid = (ok+ng)/2;
        if(is_ok(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}