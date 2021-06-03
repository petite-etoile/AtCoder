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
        os << " ";
    }
    os << bn;
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
    mint fac[510000], inv[510000];
public:
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
        if(n<0 || r<0) return 0;
        if(n==r) return 1;
        return fac[n] * inv[r] * inv[n-r];
    }
};

BigCombination B;

template<typename T>
struct Rerooting{

    using F = function<T(T,T)>; 
    F vertex_operation_merge; //頂点作用
    F accumulation_merge; //累積

    T identity_vertex_operation; //頂点作用用の単位元
    T identity_accumulate; //左右から累積する用の単位元
    int N;
    vector<vector<int>> edge;
    vector<T> DP;
    vector<T> ans;

    Rerooting(){}
    Rerooting(vector<vector<int>>& edge, F f1, T identity_vertex_operation, F f2, T identity_accumulate)
        :N(edge.size()), edge(edge), vertex_operation_merge(f1), identity_vertex_operation(identity_vertex_operation), 
            accumulation_merge(f2), identity_accumulate(identity_accumulate){
            DP.assign(N,identity_vertex_operation);
            ans.assign(N,identity_vertex_operation);
    }

    T dfs(int v, int pre){
        T res = identity_vertex_operation;
        
        for(auto to:edge[v]){
            if(to==pre) continue;
            DP[v] = vertex_operation_merge(DP[v], dfs(to, v));
        }
        return DP[v];
    }

    T dfs_with_rerooting(int v, int pre, T pre_value){
        //答えを得る
        cerr << bn;
        for(auto to:edge[v]){
            if(to==pre){ ans[v] = vertex_operation_merge(ans[v], pre_value); }
            else{ ans[v] = vertex_operation_merge(ans[v], DP[to]); }
        }

        //左右から累積Foo
        int to;
        vector<T> left(edge[v].size(), identity_accumulate), right(edge[v].size(), identity_accumulate);
        for(int i=0; i<edge[v].size(); i++){
            int j = edge[v].size() - i - 1;
            if(i){
                left[i] = left[i-1];
                right[j] = right[j+1];
            }

            to = edge[v][i];
            if(to==pre){ left[i]  = accumulation_merge(left[i] , pre_value); }
            else{ left[i]  = accumulation_merge(left[i] , DP[to]); }

            to = edge[v][j];
            if(to==pre){ right[j] = accumulation_merge(right[j], pre_value); }
            else{ right[j] = accumulation_merge(right[j], DP[to]); }
        }

        //根をくるくる
        for(int i=0;i<edge[v].size();i++){
            int to = edge[v][i];
            if(to==pre) continue;
            T value = identity_vertex_operation;
            if(i) value = vertex_operation_merge(value, left[i-1]);
            if(i!=edge[v].size()-1) value = vertex_operation_merge(value, right[i+1]);
            dfs_with_rerooting(to, v, value);
        }
    }

    void build(){
        dfs(0,-1);
        dfs_with_rerooting(0,-1,identity_vertex_operation);
    }

};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int>> edge(N);
    int a,b;
    REP(i,N-1){
        cin >> a >> b;
        edge[--a].emplace_back(--b);
        edge[b].emplace_back(a);
    }
    Rerooting<pair<mint,int>> R(edge, [&](pair<mint,int> x, pair<mint,int> y)->pair<mint,int>{
        x.second--;
        x.first *= y.first;
        x.second += y.second;
        x.first *= B.combination(x.second, y.second);
        x.second++;
        return x;
    }, make_pair(1,1) , [&](pair<mint,int> x, pair<mint,int> y)->pair<mint,int>{
        x.first *= y.first;
        x.second += y.second;
        x.first *= B.combination(x.second, y.second);
        return x;
    }, make_pair(1,0) );
    R.build();

    auto ans = R.ans;
    for(auto a:ans){
        cout << a.first << bn;
    }
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
// using P = pair<int64, int64>;
// typedef vector<int> vi;
// const int MOD = (int)1e9 + 7;
// const int64 INF = 1LL << 62;
// const int inf = 1<<30;
// template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
// template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
// #define REP(i, n) for (int i = 0; i < (n); i++)
// #define FOR(i,s,n) for (int i = s; i < (n); i++)
// #define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
// #define debug(x) cerr << #x << ": " << x << "\n";
// #define mp make_pair
// #define bn '\n'
// template <typename T>
// ostream& operator<<(ostream& os, const vector<T> &V){
//     int N = V.size();
//     REP(i,N){
//         os << V[i];
//         os << "\n";
//     }
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
//      os<<endl;
//     return os;
// }
// vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
// #pragma endregion
// //fixed<<setprecision(10)<<ans<<endl;

// int64 pow(int a,int b,int mod){
//     vector<bool> bit;
//     for(b=b;b>0;b>>=1){
//         bit.push_back(b&1);
//     }
//     vector<int64> fac(bit.size()); fac[0] = a;
//     int64 res = 1;
//     for(int i=1;i<bit.size();i++){
//         fac[i] = (fac[i-1] * fac[i-1])%mod;
//     }
//     for(int i=0;i<bit.size();i++){
//         if(bit[i]) res*=fac[i];
//         res%=mod;
//     }
//     return res;
// }


// //mint
// struct mint {
//     int64 x;
//     mint(int64 x=0):x((x+2*MOD)%MOD){}
//     mint& operator+=(const mint a) {
//         if ((x += a.x) >= MOD) x -= MOD;
//         return *this;
//     }
//     mint& operator-=(const mint a) {
//         if ((x += MOD-a.x) >= MOD) x -= MOD;
//         return *this;
//     }
//     mint& operator*=(const mint a) {
//         (x *= a.x) %= MOD;
//         return *this;
//     }
//     mint operator+(const mint a) const {
//         mint res(*this);
//         return res+=a;
//     }
//     mint operator-(const mint a) const {
//         mint res(*this);
//         return res-=a;
//     }
//     mint operator*(const mint a) const {
//         mint res(*this);
//         return res*=a;
//     }
//     mint pow(int64 t) const {
//         if (!t) return 1;
//         mint a = pow(t>>1);
//         a *= a;
//         if (t&1) a *= *this;
//         return a;
//     }

//     // for prime MOD
//     mint inv() const {
//         return pow(MOD-2);
//     }
//     mint& operator/=(const mint a) {
//         return (*this) *= a.inv();
//     }
//     mint operator/(const mint a) const {
//         mint res(*this);
//         return res/=a;
//     }
// };
// ostream& operator<<(ostream& os, mint a){
//     os << a.x;
//     return os;
// }



// class BigCombination{
// private:
//     const int MAX = 510'000;
//     mint fac[510000], inv[510000];
// public:
//     BigCombination(){
//         fac[0] = fac[1] = 1;
//         for(int i=2; i<MAX; i++){
//             fac[i] = fac[i-1] * i;
//         }
//         inv[MAX-1] = fac[MAX-1].inv();
//         for(int i=MAX-1;i>0;i--){
//             inv[i-1] = inv[i] * i;
//         }
//     }

//     mint combination(int n,int r){
//         if(n<r) return 0;
//         if(n<0 || r<0) return 0;
//         if(n==r) return 1;
//         return fac[n] * inv[r] * inv[n-r];
//     }
// };

// vector<vector<int>> edge;
// vector<mint> DP;
// vector<mint> ans;
// BigCombination B;
// vector<int> subtree_size;
// mint dfs(int v, int pre){
//     mint res = 1;

//     for(auto to:edge[v]){
//         if(to==pre) continue;
//         res *= dfs(to,v);
//         subtree_size[v] += subtree_size[to];
//     }
//     int sum_ = subtree_size[v]-1;
//     for(auto to:edge[v]){
//         if(to==pre) continue;
//         res *= B.combination(sum_, subtree_size[to]);
//         sum_-=subtree_size[to];
//     }
//     DP[v] = res;
//     return res;
// }


// int N;
// void dfs_with_rerooting(int v, int pre, pair<mint,int> pre_val_and_now_subtree_size){
//     ans[v] = pre_val_and_now_subtree_size;
//     for(auto to:edge[v]){
//         if(to!=pre){
//             ans[v] = merge(ans[v], DP[to]);
//             // ans[v] *= DP[to];
//             // now_subtree_size += subtree_size[to];
//             // ans[v] *= B.combination(now_subtree_size, subtree_size[to]);
//         }
//     }

//     for(auto to:edge[v]){
//         if(to!=pre){
//             mint val = ans[v]/DP[to]/B.combination(N-1,subtree_size[to]);
//             dfs_with_rerooting(to, v, val, N-subtree_size[to]);
//         }
//     }
// }

// //ver.1
// // void dfs_with_rerooting(int v, int pre){
// //     mint pre_val;
// //     if(pre!=-1){
// //         pre_val = ans[pre]/DP[v]/B.combination(N-1,subtree_size[v]);
// //     }

// //     int sum_ = N-1;
// //     for(auto to:edge[v]){
// //         if(to==pre){
// //             ans[v] *= pre_val;
// //         }else{
// //             ans[v] *= DP[to];
// //         }
// //         if(to!=pre){
// //             ans[v] *= B.combination(sum_, subtree_size[to]);
// //             sum_-=subtree_size[to];
// //         }
// //     }
    
// //     for(auto to:edge[v]){
// //         if(to!=pre){
// //             dfs_with_rerooting(to, v);
// //         }
// //     }
// // }

// int main(){
//     cin.tie(0);
//     ios::sync_with_stdio(false);
//     cin >> N;
//     edge.resize(N);
//     DP.assign(N,0);
//     subtree_size.assign(N,1);
//     ans.assign(N,1);

//     int a,b;
//     REP(i,N-1){
//         cin >> a >> b;
//         edge[--a].emplace_back(--b);
//         edge[b].emplace_back(a);
//     }
//     dfs(0,-1);
//     dfs_with_rerooting(0,-1,-1,0);

//     cout << ans;
// }