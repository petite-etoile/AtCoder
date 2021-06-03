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

map<pair<int,int>,int> dp;
int N;
vector<int> A;
int dfs(int i, int x){
    if(i==N) return 0;
    if(x==0) return 0;
    if(dp.find(mp(i,x))!=dp.end()) return dp[mp(i,x)];
    int res = 0;
    chmax(res, dfs(i+1, A[i]/x) +  A[i]/x);
    chmax(res, dfs(i+1, x));
    dp[mp(i,x)] = res;
    return res;  
}

template <typename T>
struct SegmentTree{
    /*
    ~~~~1-indexで実装~~~~
            1
        2       3
      4   5   6    7

    ~~~~親・兄弟・子へのアクセスの仕方~~~~
                i>>1
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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    int a;
    REP(i,N)
        cin >> a, A.emplace_back(a);

    //現時点で紙に書かれている数がxのときの最大値を持っておく
    SegmentTree<int> Seg(
        [](int a,int b)->int{
            return max(a,b);
        }, 0
    );
    const int MAX_A = 1e6+1;
    Seg.init(MAX_A);

    int idx,val;
    for(auto a:A){
        vector<pair<int,int>> res;
        for(int64 y=1;y*y<=MAX_A;y++){
            //floor(a/y)
            if(a>=y) {
                res.emplace_back( a/y, Seg.query(y,y+1) + a/y);
            }
            //floor(a/X)=yとなるX
            int l = a / (y+1) + 1;
            int r = a / y;
            if(l<=r){
                res.emplace_back( y, Seg.query(l,r+1) + y);
            }
        }
        for(auto e:res){
            tie(idx,val) = e;
            if(Seg.get_val(idx) < val) Seg.set_val(idx,val);
        }
    }
    auto ans = Seg.query(0,MAX_A+1);
    cout << ans << bn;

}