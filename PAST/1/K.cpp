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
        dfs(root, 0);

        S = SegmentTree<pair<int,int>> (
            [](pair<int,int> a,pair<int,int> b)->pair<int,int>{
                return min(a,b);
            }, make_pair(INT_MAX,-1)
        );
        S.init(depth_node.size());
        S.build(depth_node);
    }
    
    //dfsで通った点をvectorに入れていく(コンストラクタでのみ使用)
    void dfs(int v, int dep){
        depth_of[v] = dep;
        depth_node.emplace_back(dep,v);

        for(auto to:edge[v]){
            dfs(to,dep+1);
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




int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int p;
    int root;
    vector<vector<int>> edge(N);

    REP(i,N){
        cin >> p;
        if (p==-1){
            root = i;
        }else{
            edge[p-1].emplace_back(i);
        }
    }
    SegmentTree<pair<int,int>> S;(
        [](pair<int,int> a,pair<int,int> b)->pair<int,int>{
            return min(a,b);
        }, make_pair(__INT_MAX__,-1)
    );
    LowestCommonAncestor LCA(edge, root);

    int Q;
    cin >> Q;
    int a,b;
    int lca,depth;
    REP(i,Q){
        cin >> a >> b;
        tie(depth, lca) = LCA.get_LCA(--a, --b);
        if (lca == b) cout << "Yes" << bn;
        else cout << "No" << bn;
    }
}

/*
　　MLE解法
*/




/*
　　　∫ ∫ ∫
　　　ノヽ
　　（＿　 ）
　（＿　　　 ）
（＿＿＿＿＿＿ ）
　ヽ(´･ω･)ﾉ　
　　 |　 /
　　 UU
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using P = pair<ll, ll>;
typedef vector<int> vi;
const int MOD = (int)1e9 + 7;
const ll INF = 1LL << 62;
const int inf = 1<<30;
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
ostream& operator<<(ostream& os, pair<T,T> const&P){
    os << P.first;
    os << " ";
    os << P.second;
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
//fixed<<setprecision(10)<<ans<<endl;



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vi> edge(N);
    int p;
    int root;
    REP(i,N){
        cin >> p;
        p--;
        if(p==-2) root = i;
        else edge[p].push_back(i);
    }

    stack<int> st;
    st.push(root);
    int u;
    vector<bitset<150001>> bi(N);

    while (!st.empty()){
        u = st.top();st.pop();
        auto a = bi[u];
        a.set(u);
        for(auto v:edge[u]){
            st.push(v);
            bi[v] = a;
        } 
    }
    int Q;
    cin >> Q;
    int a,b;
    REP(i,Q){
        cin >> a >> b;
        a--;b--;
        if(bi[a][b]) cout << "Yes\n";
        else cout << "No\n";

    }

}

*/