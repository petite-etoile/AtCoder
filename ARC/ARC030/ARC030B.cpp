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

vector<vector<int>> edge;
vector<vector<bool>> path;
void dfs(int v, int pre, vector<bool> now){
    now[v] = true;
    path[v] = now;
    for(auto to:edge[v]){
        if(to!=pre) dfs(to, v, now);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,X;
    cin >> N >> X;
    X--;
    edge.resize(N);
    path.resize(N);
    vector<int> H(N);
    bool flag = false;
    REP(i,N){
        cin >> H[i];
        if(H[i]) flag = true;
    }
    REP(i,N-1){
        int a,b;
        cin >> a >> b;
        edge[--a].emplace_back(--b);
        edge[b].emplace_back(a);
    }

    if(flag){
        dfs(X, -1, vector<bool>(N,false));
        vector<bool> nodes(N, false);
        REP(i,N){
            if(H[i]){
                REP(j,N){
                    if(path[i][j]) nodes[j] = true;
                }
            }
        }
        int ans=-1;
        REP(i,N){
            ans += nodes[i];
        }
        cout << ans*2 << endl;
    }else{
        cout << 0 << bn;

    }

}