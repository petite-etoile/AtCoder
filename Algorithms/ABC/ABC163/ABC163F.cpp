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
        os << "\n";
    }
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

//データ構造をマージする一般的なテク
void teq_merge(map<int,int>& A,map<int,int>& B){
    if(A.size()<B.size()) swap(A,B);
    for(auto e:B) A[e.first] += e.second;
}

vector<int> subtree_size;//subtree[v]:=vを根とする部分木のサイズ
vector<map<int,int>> unusable;    //unusable[v][c]:=vの部分木で色cを通らずに行けない点の数
int dfs(int v, int pre, vector<int64>& ans, const vector<vector<int>>& edge, const vector<int>& color){
    subtree_size[v]=1; //vの分

    for(auto to:edge[v]){
        if(to==pre) continue;
        subtree_size[v] += dfs(to, v, ans, edge, color);
        int usable = subtree_size[to] - unusable[to][color[v]]; //子toの部分木の中で、vからcolor[v]を通らずに到達可能な点の数
        ans[color[v]] -= int64(usable) * (usable-1)/2; //choose(usable, 2);
        teq_merge(unusable[v],unusable[to]);
    }

    unusable[v][color[v]] = subtree_size[v]; //vの色がcolor[v]なのでvの子孫には根からcolor[v]を通らずに到達不可能
    return subtree_size[v];
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    subtree_size.assign(N,0);
    unusable.resize(N); 
    vector<int> color(N);
    REP(i,N) cin >> color[i],color[i]--;
    vector<vector<int>> edge(N);
    REP(i,N-1){
        int a,b; cin >> a >> b;
        edge[--a].emplace_back(--b);
        edge[b].emplace_back(a);
    }
    
    vector<int64> ans(N,int64(N)*(N-1)/2); //頂点数2以上のパスの選び方
    dfs(0,-1,ans,edge,color);
    REP(col,N){
        int usable = N - unusable[0][col];
        ans[col] -= int64(usable)*(usable-1)/2;
    }

    for(auto c:color) ans[c]++;
    cout << ans;
}


// 図解 https://twitter.com/petite_prog/status/1252118046618972161

// int vertex_cnt; //今まで見た頂点の数(帰りがけに加算される)
// vector<int> subtree_size;//subtree[v]:=vを根とする部分木のサイズ
// vector<int> unusable;    //それぞれの色に対して、根からその色を通らないで到達不可な(現時点で確定してる)点の数
// int dfs(int v, int pre, vector<int64>& ans, const vector<vector<int>>& edge, const vector<int>& color){
//     subtree_size[v]=1; //vの分
//     int before = unusable[color[v]]; //子で加算して変動したものも考慮して計算するのは面倒なのでdfsを再帰的に呼ぶ前の状態を保存しておく
//     for(auto to:edge[v]){
//         if(to==pre) continue;
//         int usable_pre = vertex_cnt - unusable[color[v]]; //今まで見た点の中で、根からcolor[v]を通らずに到達可能な点の数
//         subtree_size[v] += dfs(to, v, ans, edge, color);
//         int usable_now = vertex_cnt - unusable[color[v]]; //(子toの子孫を見たあとで)今まで見た点の中で、根からcolor[v]を通らずに到達可能な点の数

//         int usable = usable_now - usable_pre; //子toの部分木の中で、vからcolor[v]を通らずに到達可能な点の数
//         ans[color[v]] -= int64(usable) * (usable-1)/2; //choose(usable, 2);
//     }
//     unusable[color[v]] = before + subtree_size[v]; //vの色がcolor[v]なのでvの子孫には根からcolor[v]を通らずに到達不可能
//     vertex_cnt++;
//     return subtree_size[v];
// }

// int main(){
//     cin.tie(nullptr);
//     ios::sync_with_stdio(false);
//     int N;
//     cin >> N;
//     subtree_size.assign(N,0);
//     unusable.assign(N,0); 
//     vector<int> color(N);
//     REP(i,N) cin >> color[i],color[i]--;
//     vector<vector<int>> edge(N);
//     REP(i,N-1){
//         int a,b; cin >> a >> b;
//         edge[--a].emplace_back(--b);
//         edge[b].emplace_back(a);
//     }
    
//     vector<int64> ans(N,int64(N)*(N-1)/2); //頂点数2以上のパスの選び方
//     dfs(0,-1,ans,edge,color);
//     //(根と違う各)色に対して、残りのパスを計算する なお、根の色ではunusable[c]==0となっているので場合分け不要
//     REP(c,N){
//         int usable = N - unusable[c];
//         ans[c] -= int64(usable)*(usable-1)/2;
//     }

//     //同一点を両端とするパスの分を加算(初期化の段階では考慮してなかったもの)
//     for(auto c:color) ans[c]++;

//     cout << ans;
// }