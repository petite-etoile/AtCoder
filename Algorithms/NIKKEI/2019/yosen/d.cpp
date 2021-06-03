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
typedef long long ll;
using namespace std;
using P = pair<ll, ll>;
typedef vector<int> vi;
const int MOD = (int)1e9 + 7;
const ll INF = 1LL << 61;
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
        for(int i=n_-1; i; i++){
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
    int N = S.data.size()/2;
    REP(i,N){
        os << S.data[i+N];
        if (i!=N-1) os << " ";
    }
    os << "\n";
    return os;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;


    SegmentTree<ll> S(
        [](ll a,ll b)->ll{
            return min(a,b);
        }, INF
    );

    S.init(N);
    S.set_val(0,0);

    vector<tuple<ll,ll,ll>> query;
    ll l,r,c;
    REP(i,M){
        cin>>l>>r>>c;
        l--;r--;
        query.emplace_back(l,r,c);
    }

    sort(ALL(query),[](auto a,auto b){
        if(get<1>(a)==get<1>(b)) return get<0>(a)<get<0>(b);
        return get<1>(a)<get<1>(b);
    });

    REP(i,M){
        tie(l,r,c) = query[i];
        auto from = S.query(l,r);
        auto to = S.query(r,r+1);
        if(to>from+c) S.set_val(r,from+c);
    }
    // cout << S;
    ll ans = S.get_val(N-1);
    if(ans==S.identity) cout << "-1\n";
    else cout << ans << endl;
}















/*
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using P = pair<ll, ll>;
typedef vector<int> vi;
const int MOD = (int)1e9 + 7;
const ll INF = 1LL << 60;
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
vector<ll> dijkstra(vector<vector<pair<ll,ll>>> const& edge, ll start){
    ll N = edge.size();
    vector<ll> dist(N,INF);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>> > q;
    q.push(mp(0, start));
    vector<bool> visited(N,false);
    
    ll from,d;
    ll to,cost;
    while(!q.empty()){
        tie(d,from) = q.top(); q.pop();
        if (visited[from]) continue;
        visited[from] = true;
        dist[from] = d;
        for(auto e:edge[from]){
            tie(to,cost) = e;
            if (visited[to]) continue;
            q.push(mp(d+cost, to));
        }
    }

    return dist;
}
//fixed<<setprecision(10)<<ans<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vector<vector<pair<ll,ll>>> edge(N);
    int l,r,c;
    REP(i,M){
        cin >> l >> r >> c;
        l--;r--;
        edge[l].push_back(mp(r,c)); 
    }
    REP(i,N-1) edge[i+1].push_back(mp(i,0)); //重み0の辺
    auto dist = dijkstra(edge, 0);

    if (dist[N-1]>=INF) cout << -1 << endl;
    else cout << dist[N-1]<< endl;
}
*/