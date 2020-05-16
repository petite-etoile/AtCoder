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

string bin(int n){
    string s = "";
    while(n>0){
        string b = to_string(n%2);
        s = b+s;
        n>>=1;
    }
    return s;
}

// O(2^N)
struct MaximumIndependentSet{
    vector<vector<int>> edge;
    vector<bool> OK; //OK[S]:=グループ1の頂点集合Sが独立集合かどうか
    vector<int> NG; //NG[S]:=グループ1の頂点集合Sが隣接しているグループ2の頂点集合
    vector<int> DP; //DP[U]:=グループ2の頂点集合Uの最大独立集合のサイズ
    size_t N,N1,N2;
    int MIS_size = 0;
    MaximumIndependentSet(vector<vector<int>> const& edge) :N(edge.size()), edge(edge){
        build();
    }

    void build(){
        N1 = N/2, N2 = (N+1)/2;
        group1_solve(); //グループ1に対する,OK,NGを計算
        group2_solve(); //グループ2に対する,DPを計算
        merge(); //OK,NG,DP を用いて最大独立集合を計算
    }

    void group1_solve(){
        //-----OKの計算-----
        OK.assign(1<<N1, true);
        for(int i=0; i<N1; i++){
            for(auto to:edge[i]){
                if(to<N1) OK[(1<<i) | (1<<to)] = false;
            }
        }
        for(int mask=0; mask < 1<<N1; mask++){
            if(OK[mask]) continue;
            for(int i=0; i<N1; i++){
                OK[mask | (1<<i)] = false;
            }
        }

        //-----NGの計算-----
        NG.assign(1<<N1, 0);
        for(int i=0; i<N1; i++){
            for(auto to:edge[i]){
                if(to<N1) continue;
                to -= N1;
                NG[1<<i] |= 1<<to;
            }
        }

        for(int mask=0; mask < 1<<N1; mask++){
            for(int i=0; i<N1; i++){
                NG[mask | (1<<i)] |= NG[mask] | NG[1<<i];
            }
        }
    }
    void group2_solve(){
        DP.assign(1<<N2, N2);
        //-----OKと同様の計算-----
        for(int i=0; i<N2; i++){
            for(auto to:edge[i+N1]){
                if(to>=N1) DP[(1<<i) | (1<<(to-N1))] = 0;
            }
        }
        for(int mask=0; mask < 1<<N2; mask++){
            if(DP[mask]>0){
                DP[mask] = __builtin_popcount(mask);
                continue;
            }
            for(int i=0; i<N2; i++){
                DP[mask | (1<<i)] = 0;
            }
        }

        //-----DPの計算-----
        for(int mask=0; mask < 1<<N2; mask++){
            for(int i=0; i<N2; i++){
                DP[mask | (1<<i)] = max(DP[mask], DP[mask | (1<<i)]);
            }
        }
    }
    void merge(){
        for(int mask1=0; mask1 < 1<<N1; mask1++){
            if(OK[mask1]){
                int mask2 = ((1<<N2)-1) ^ NG[mask1];
                MIS_size = max(MIS_size, __builtin_popcount(mask1) + DP[mask2]);
            }
        }
    }

    int get_MIS_size(){
        return MIS_size;
    }

};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    int half = N/2;
    vector<vector<int>> edge(N);
    REP(i,M){
        int a,b; cin >> a >> b;
        edge[--a].emplace_back(--b);
        edge[b].emplace_back(a);
    }

    MaximumIndependentSet MIS(edge);
    int ans=MIS.get_MIS_size();
    cout << ans << endl;
}