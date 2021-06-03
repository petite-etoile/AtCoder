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
        vector<vector<int>> new_edge(scc_size);
        for(int i=0;i<N;i++){
            int topo = topological_index[i];
            for(auto to:edge[i]){
                if(topo!=topological_index[to]) new_edge[topo].emplace_back(topological_index[to]);
            }
        }
        for(int i=0;i<scc_size;i++){
            sort(new_edge[i].begin(), new_edge[i].end());
            new_edge[i].erase(unique(new_edge[i].begin(), new_edge[i].end()), new_edge[i].end());
        }
        return new_edge;
    }

};

int64 pow(int a,int b,int mod){
    vector<bool> bit;
    for(b=b;b>0;b>>=1){
        bit.push_back(b&1);
    }
    vector<int64> fac(bit.size()); fac[0] = a;
    int64 res = 1;
    for(int i=1;i<bit.size();i++){
        fac[i] = (fac[i-1] * fac[i-1])%mod;
    }
    for(int i=0;i<bit.size();i++){
        if(bit[i]) res*=fac[i];
        res%=mod;
    }
    return res;
}


//mint
struct mint {
    int64 x;
    mint(int64 x=0):x((x+2*MOD)%MOD){}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(int64 t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime MOD
    mint inv() const {
        return pow(MOD-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};
ostream& operator<<(ostream& os, mint a){
    os << a.x;
    return os;
}

class BigCombination{
private:
    const int MAX = 510'000;
public:
    mint fac[510000], inv[510000];
    BigCombination(){
        fac[0] = fac[1] = 1;
        for(int i=2; i<MAX; i++){
            fac[i] = fac[i-1] * i;
        }
        inv[MAX-1] = fac[MAX-1].inv();
        for(int i=MAX-1;i>0;i--){
            inv[i-1] = inv[i] * i;
        }
    }

    mint combination(int n,int r){
        if(n<r) return 0;
        if(n==r) return 1;
        return fac[n] * inv[r] * inv[n-r];
    }
    mint permutation(int n,int r){
        if (n < r) return 0;
        return fac[n] * inv[n-r];
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> P(N);
    REP(i,N) cin >> P[i];
    vector<vector<int>> edge(N);
    int K = 0;
    REP(i,N){
        P[i]--;
        if(P[i]>=0){
            edge[P[i]].emplace_back(i);
            edge[i].emplace_back(P[i]);
        }else K++;
    }
    StronglyConnectedComponents SCC(edge);
    
    edge = SCC.build_graph();

    int edge_num = N-SCC.get_scc_size();
    mint ans= mint(N-1).pow(K) * edge_num; //元からある辺の数
    mint def = ans;
    vector<bool> can_add_edge(SCC.get_scc_size());
    vector<int> components_size(SCC.get_scc_size(), 0);
    REP(i,N){
        if(P[i] < 0){
            can_add_edge[SCC.get_topological_index(i)] = true;
        }
        components_size[SCC.get_topological_index(i)] += 1;
    }
    debug(components_size)

    BigCombination B;
    debug(ans)
    REP(i,SCC.get_scc_size()){
        debug(i)
        debug(can_add_edge)
        for(int k=1; k<=K-can_add_edge[i]; k++){ //自分に伸びてくる辺の数
            debug(mp(i,k))
            if(can_add_edge[i]){
                ans += B.combination(K-1,k) * (mint(components_size[i]).pow(k) * mint(N-components_size[i]-1).pow(K-k-1) * (N-1)) / (k+1);
                debug(mp(mint(components_size[i]).pow(k), mp(mint(N-components_size[i]-1).pow(K-k-1) ,(N-1))));
                debug(mint(components_size[i]).pow(k) * mint(N-components_size[i]-1).pow(K-k-1) * (N-1))
            }else{
                debug(mp(mint(components_size[i]).pow(k), mint(N-components_size[i]-1).pow(K-k)))
                debug(mint(components_size[i]).pow(k) * mint(N-components_size[i]-1).pow(K-k))
                ans += mint(components_size[i]).pow(k) * mint(N-components_size[i]-1).pow(K-k) / (k+1);
            }
            debug(ans)
        }
        debug("")
    }




    cout << ans << endl;
}