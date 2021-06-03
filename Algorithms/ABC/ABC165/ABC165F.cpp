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

vector<vector<int>> edge;
vector<int> ans;

void dfs(int now, int pre, vector<int64>& LIS, vector<int64> const& A ){
    int idx,before=-1;
    if(LIS.back()<A[now]){
        idx = LIS.size();
        LIS.emplace_back(A[now]);
    }else{
        auto it = lower_bound(ALL(LIS), A[now]);
        idx = it-LIS.begin();
        before = LIS[idx];
        LIS[idx] = A[now];
    }
    ans[now] = int(LIS.size());
    for(auto to:edge[now]){
        if(to==pre) continue;
        dfs(to,now,LIS,A);
    }
    if(before==-1){
        LIS.pop_back();
    }else{
        LIS[idx] = before;
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int64> A(N);
    REP(i,N) cin >> A[i];
    edge.resize(N);
    REP(i,N-1){
        int a,b;cin >> a >> b;
        edge[--a].emplace_back(--b);
        edge[b].emplace_back(a);
    }
    vector<int64> LIS = {A[0]};
    ans.assign(N,0);
    dfs(0,-1,LIS,A);

    cout << ans;
}


// /*
// 　　　∫ ∫ ∫
// 　　　ノヽ
// 　　（＿　 ）
// 　（＿　　　 ）
// （＿＿＿＿＿＿ ）
// 　ヽ(´･ω･)ﾉ　
// 　　 |　 /
// 　　 UU
// */
// #pragma region macro
// #include <bits/stdc++.h>
// typedef long long int64;
// using namespace std;
// typedef vector<int> vi;
// const int MOD = (int)1e9 + 7;
// const int64 INF = 1LL << 62;
// const int inf = 1<<30;
// const char bn = '\n';
// template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
// template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
// #define REP(i, n) for (int i = 0; i < (n); i++)
// #define FOR(i,s,n) for (int i = s; i < (n); i++)
// #define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
// #define debug(x) cerr << #x << ": " << x << "\n";
// #define mp make_pair
// template <typename T>
// ostream& operator<<(ostream& os, const vector<T> &V){
//     int N = V.size();
//     REP(i,N){
//         os << V[i];
//         if (i!=N-1) os << " ";
//     }
//     os << "\n";
//     return os;
// }
// template <typename T,typename S>
// ostream& operator<<(ostream& os, pair<T,S> const&P){
//     os << "(";
//     os << P.first;
//     os << " , ";
//     os << P.second;
//     os << ")";
//     return os;
// }
// template <typename T>
// ostream& operator<<(ostream& os, set<T> &S){
//     auto it=S.begin();
//     while(it!=S.end()){
//         os << *it;
//         os << " ";
//         it++;
//     }
//     os << "\n";
//     return os;
// }
// template <typename T>
// ostream& operator<<(ostream& os, deque<T> &q){
//     for(auto it=q.begin();it<q.end();it++){
//         os<<*it;
//         os<<" ";
//     }
//     os<<endl;
//     return os;
// }
// template <typename T,typename S>
// ostream& operator<<(ostream& os, map<T,S> const&M){
//     for(auto e:M){
//         os<<e;
//     }
//     os<<endl;
//     return os;
// }
// vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
// #pragma endregion
// //fixed<<setprecision(10)<<ans<<endl;

// vector<vector<int>> edge;
// vector<int> ans;

// template <typename T>
// struct SegmentTree{
//     /*
//     ~~~~1-indexで実装~~~~
//             1
//         2       3
//       4   5   6    7

//     ~~~~親・兄弟・子へのアクセスの仕方~~~~
//                 i>>1
//             i           i^1
//     i<<1|0   i<<1|1
//     */


//     using F = function<T(T,T)>;
//     int N;
//     F func; //関数(minとか)
//     T identity; //単位元
//     vector<T> data; //上から添字 2*Nくらいのノード
//     SegmentTree(){}
//     SegmentTree(F f,T identity):func(f),identity(identity){}

//     void init(int n_){
//         N=1;
//         while(N<n_) N<<=1; //完全二分木がいいので2^k個にする
//         data.assign(N<<1, identity); //2N個のノード
//     }

//     //木を構成(vectorを元に各ノードの値を計算)
//     void build(const vector<T>& v){
//         int n_ = v.size();
//         init(n_);
//         for(int i=0; i<n_; i++){
//             data[N+i] = v[i]; //葉
//         }
//         for(int i=N-1; i; i--){
//             data[i] = func(data[i<<1], data[(i<<1)+1] ); //子をみて親を更新
//         }
//     }

//     //k番目の値をxに変える
//     void set_val(int k, T x){
//         k+=N; //indexをセグ木でのindexに変換
//         data[k] = x; //値の書き換え(葉)
//         while(k>>=1){ //右シフトして0にならない間
//             data[k] = func(data[k<<1], data[(k<<1)+1] );
//         }
//     }

//     //https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf
//     //閉開区間[left,right)で
//     T query(int left,int right){
//         T left_val=identity, right_val=identity; 
//         for(int l=left+N,r=right+N; l<r; l>>=1,r>>=1){
//             if(l&1) left_val = func(left_val, data[l++] );
//             if(r&1) right_val = func(data[--r], right_val);
//         }
//         return func(left_val, right_val);
//     }

//     //葉の値を取得する
//     T get_val(int idx){
//         return data[idx+N];
//     }
// };
// template <typename T>
// ostream& operator<<(ostream& os, SegmentTree<T> &S){
//     int N = S.data.size();
//     int cnt = 0;
//     int up = 1;
//     for(int i=1;i<N;i++){
//         if(S.data[i]!=S.identity){
//             os << S.data[i];
//         }else os << "単";
//         os << " ";
//         cnt++;
//         if (cnt == up){
//             os << "\n\n";
//             up<<=1;
//             cnt=0;
//         }else if (cnt%2==0) os<<",";
//     }
//     os << "\n";
//     return os;
// };

// void dfs(int now, int pre, SegmentTree<int>& Seg, vector<int> const& A ){
//     auto a = Seg.query(0,A[now]);
//     ans[now] = a+1;
//     chmax(ans[now], Seg.query(0,A.size()));
//     int before = Seg.get_val(A[now]);
//     Seg.set_val(A[now],a+1);
//     for(auto to:edge[now]){
//         if(to==pre) continue;
//         dfs(to,now,Seg,A);
//     }
//     Seg.set_val(A[now],before);
// }

// int main(){
//     cin.tie(nullptr);
//     ios::sync_with_stdio(false);
//     int N; cin >> N;
//     vector<int64> A,tmp;
//     REP(i,N) {
//         int64 a; cin >> a;
//         A.emplace_back(a);
//         tmp.emplace_back(a);
//     }
//     sort(ALL(A));   
//     A.erase(unique(ALL(A)),A.end());
//     vector<int> B(N);
//     REP(i,N){
//         auto it = lower_bound(ALL(A),tmp[i]);
//         B[i] = it-A.begin();
//     }

//     edge.resize(N);
//     REP(i,N-1){
//         int a,b; cin >> a >> b;
//         edge[--a].emplace_back(--b);
//         edge[b].emplace_back(a);
//     }

//     SegmentTree<int> Seg(
//         [](int a,int b)->int{
//             return max(a,b);
//         }, 0
//     );

//     Seg.init(N+1);
//     ans.assign(N,0);
//     dfs(0,-1,Seg,B);

//     cout << ans;
// }