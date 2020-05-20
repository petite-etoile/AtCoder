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


template <typename T>
struct SegmentTree{
    /*
    ~~~~1-indexで実装~~~~
            1
        2       3
      4   3   5    6

    ~~~~親・兄弟・子へのアクセスの仕方~~~~
                i<<1
            i           i^1
    i<<1|0   i<<1|1
    */


    using F = function<T(T,T)>;
    int N;
    F func; //関数(minとか)
    T identity; //単位元
    vector<T> data; //上から添字 2*Nくらいのノード
    SegmentTree(){}
    SegmentTree(F f,T identity):func(f),identity(identity){}

    void init(int n_){
        N=1;
        while(N<n_) N<<=1; //完全二分木がいいので2^k個にする
        data.assign(N<<1, identity); //2N個のノード
    }

    //木を構成(vectorを元に各ノードの値を計算)
    void build(const vector<T>& v){
        int n_ = v.size();
        init(n_);
        for(int i=0; i<n_; i++){
            data[N+i] = v[i]; //葉
        }
        for(int i=N-1; i; i--){
            data[i] = func(data[i<<1], data[(i<<1)+1] ); //子をみて親を更新
        }
    }

    //k番目の値をxに変える
    void set_val(int k, T x){
        k+=N; //indexをセグ木でのindexに変換
        data[k] = x; //値の書き換え(葉)
        while(k>>=1){ //右シフトして0にならない間
            data[k] = func(data[k<<1], data[(k<<1)+1] );
        }
    }

    //https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf
    //閉開区間[left,right)で
    T query(int left,int right){
        T left_val=identity, right_val=identity; 
        for(int l=left+N,r=right+N; l<r; l>>=1,r>>=1){
            if(l&1) left_val = func(left_val, data[l++] );
            if(r&1) right_val = func(data[--r], right_val);
        }
        return func(left_val, right_val);
    }

    //葉の値を取得する
    T get_val(int idx){
        return data[idx+N];
    }
};

template <typename T>
ostream& operator<<(ostream& os, SegmentTree<T> &S){
    int N = S.data.size();
    int cnt = 0;
    int up = 1;
    for(int i=1;i<N;i++){
        if(S.data[i]!=S.identity){
            os << S.data[i];
        }else os << "単";
        os << " ";
        cnt++;
        if (cnt == up){
            os << "\n\n";
            up<<=1;
            cnt=0;
        }else if (cnt%2==0) os<<",";
    }
    os << "\n";
    return os;
};


struct LowestCommonAncestor{
    map<int,int> index_of;
    map<int,int> depth_of;
    vector<pair<int,int>> depth_node;
    vector<vector<int>> edge;
    SegmentTree<pair<int,int>> S;
    
    LowestCommonAncestor(vector<vector<int>>& edge, int root):edge(edge){
        dfs(root, 0, -1);

        S = SegmentTree<pair<int,int>> (
            [](pair<int,int> a,pair<int,int> b)->pair<int,int>{
                return min(a,b);
            }, make_pair(INT_MAX,-1)
        );
        S.init(depth_node.size());
        S.build(depth_node);
    }
    
    //dfsで通った点をvectorに入れていく(コンストラクタでのみ使用)
    void dfs(int v, int dep, int pre){
        depth_of[v] = dep;
        depth_node.emplace_back(dep,v);

        for(auto to:edge[v]){
            if(pre==to) continue;
            dfs(to,dep+1,v);
            depth_node.emplace_back(dep,v);
        }

        index_of[v] = depth_node.size() - 1;
        return;
    }

    //aとbの最深共通祖先を返す(深さ、ノード) 0-indexed
    pair<int,int> get_LCA(int a, int b){
        int l = index_of[a];
        int r = index_of[b];
        if (l > r) swap(l, r);

        return S.query(l,r+1);
    }

    //node vの深さを返す(0-indexed)
    int get_depth(int v){
        return depth_of[v];
    }
};

struct LowLink{
    vector<bool> visited;
    vector<vector<int>> edge;
    vector<int> pre_order,low; //low[v]:=min{pre_order[u]|u==v or uがvの子孫(vを含む)に補木辺を持つ}
    int N;
    vector<int> articulation_points; //関節点:=2つ以上の2連結成分に含まれる点(=グラフから削除すると連結成分が一つ増えるような点)
    vector<pair<int,int>> bridge; //橋:=グラフから削除すると連結成分が一つ増えるような辺
    //O(N+M)
    LowLink(vector<vector<int>> const& edge):edge(edge){
        N = edge.size();
        visited.assign(N,false);
        int order = 0; 
        pre_order.assign(N,0); low.assign(N,0);
        for(int v=0;v<N;v++) dfs(v,-1,v,order);
    }

    void dfs(int v,int pre,int root,int& order){
        if(visited[v]) return;
        visited[v] = true;
        
        pre_order[v] = order++; 
        low[v] = pre_order[v];
        int child_cnt = 0; 
        bool Art_flag = false;
        for(auto to:edge[v]){
            if(to==pre) continue;
            if(visited[to])  low[v] = min(low[v], pre_order[to]);
            else {
                dfs(to,v,root,order);
                low[v] = min(low[v], low[to]);
                child_cnt++;
                if(pre_order[v]<=low[to]) Art_flag=true;
                if(pre_order[v] < low[to]) bridge.emplace_back(min(v,to), max(v,to));
            }
        }
        if(v==root and child_cnt>=2) articulation_points.emplace_back(v);
        if(v!=root and Art_flag) articulation_points.emplace_back(v);
    }

    //関節点を返す
    vector<int> get_art_points(){
        /*点vが関節点 <=>DFS木において
            ・vが根なら子の数が複数
            ・そうでなければ、vの子孫と先祖を結ぶ補木辺が存在しない*/
        return articulation_points;
    }

    //橋を返す
    vector<pair<int,int>> get_bridge(){
        return bridge;
    }

    bool is_bridge(int a,int b){
        if(pre_order[a]>pre_order[b]) swap(a,b);
        return pre_order[a] < low[b];
    }
};

//二辺連結成分分解(LowLinkに依存)
struct TwoEdgeConnectedComponents{
    int N;
    vector<vector<int>> edge,edge_ori;
    vector<int> visited;
    int tecc_size = 0;
    vector<int> index;
    TwoEdgeConnectedComponents(vector<vector<int>> const& edge_):edge_ori(edge_),N(edge_.size()){
        //bridgeを除いたグラフを生成
        LowLink LL(edge_ori);
        edge.resize(N);
        for(int v=0;v<N;v++){
            for(auto to:edge_ori[v]){
                if(not LL.is_bridge(v,to)) edge[v].emplace_back(to);
            }
        }
        visited.assign(N,false);
        index.assign(N,-1);
        for(int i=0;i<N;i++){
            if(not visited[i]) dfs(i,tecc_size++);
        }
    }

    void dfs(int v,int k){
        index[v] = k;
        visited[v] = true;
        for(auto to:edge[v]){
            if(not visited[to]) dfs(to,k);
        }
    }

    int get_index(int v){
        return index[v];
    }

    vector<vector<int>> build_graph(){
        vector<vector<int>> res(N);
        for(int v=0;v<N;v++){
            for(auto to:edge_ori[v]){
                if(index[v]!=index[to]) res[index[v]].emplace_back(index[to]);
            }
        }

        for(int v=0;v<N;v++){
            sort(ALL(res[v]));
            res[v].erase(unique(ALL(res[v])), res[v].end());
        }
        return res;
    }

    int get_tecc_size(){
        return tecc_size;
    }
};

vector<int> bfs(vector<vector<int>>& edge,int s){
    int N = edge.size();
    queue<int> q({s});
    vector<int> dist(N,inf);
    dist[s] = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto to:edge[v]){
            if(dist[to]==inf){
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
    return dist;
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
    TwoEdgeConnectedComponents TECC(edge);
    edge = TECC.build_graph();
    LowestCommonAncestor LCA(edge,0);
    auto dist = bfs(edge,0);


    int Q; cin >> Q;
    REP(i,Q){
        int a,b,c; cin >> a >> b >> c; a--,b--,c--;
        a = TECC.get_index(a), b = TECC.get_index(b), c = TECC.get_index(c);
        int dist_a = dist[a], dist_b = dist[b], dist_c = dist[c];
        int D_ab = dist[a]+dist[b]-2*dist[LCA.get_LCA(a,b).second];
        int D_bc = dist[b]+dist[c]-2*dist[LCA.get_LCA(b,c).second];
        int D_ca = dist[c]+dist[a]-2*dist[LCA.get_LCA(c,a).second];
        if(D_ab+D_bc==D_ca) cout << "OK" << bn;
        else cout << "NG" << bn;
    }
}