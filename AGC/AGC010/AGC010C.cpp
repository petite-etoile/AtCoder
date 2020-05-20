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

bool ans = true;
int dfs(int now, int pre, vector<int64> const& A, vector<vector<int>> const& edge){
    if(edge[now].size() == 1 and pre!=-1){
        return A[now];
    }

    vector<int64> child;
    for(auto to:edge[now]){
        if(pre==to) continue;
        child.emplace_back(dfs(to,now,A,edge));
    }

    int64 max_ = *max_element(ALL(child)); 
    int64 sum_ = accumulate(ALL(child), 0LL); //子の石の数合計
    int64 can = (sum_ - max(0LL, max_-(sum_-max_))) / 2; //この部分木内だけで除去できる石の数

    if(sum_< A[now]) ans = false;  //部分木の根を除去するようなパスは必ず子を含む
    if(A[now] < can) ans=false;  //部分木内でのみ除去しても根の石の数が足りない
    int64 decrease = sum_ - A[now]; //この部分木内のパスで除去する数
    if(decrease > can) ans = false;  
    return A[now] - decrease; //外とのパスで除去する石の数をもつ頂点(葉)に縮約
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int64> A(N);
    REP(i,N) cin >> A[i];

    vector<vector<int>> edge(N);
    REP(i,N-1){
        int a,b; cin >> a >> b;
        edge[--a].emplace_back(--b);
        edge[b].emplace_back(a);
    }

    auto res = dfs(0, -1, A, edge);
    if(edge[0].size() == 1){
        if(A[0] != res) ans = false;
    }else{
        if(res != 0) ans = false;
    }

    if(ans){
        cout << "YES" << bn;
    }else cout << "NO" << bn;
}