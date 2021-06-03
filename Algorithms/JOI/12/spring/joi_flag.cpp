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

vector<tuple<int,int,int>> P;
int dfs(int level, int l, int r, int u, int d){
    if(level == 0) return 0;

    //----点が範囲内にあるなら,右上,左上,右下,左下のどこに何点あるのかカウント----
    vector<vector<int>> point_cnt(4,vector<int>(3));
    for(auto p:P){
        int x,y,z; tie(x,y,z) = p;
        if(x<l or r<=x or y<u or d<=y) continue;
        
        int left_ = x < (l+r)/2, up = y < (u+d)/2;
        point_cnt[left_*2 + up][z]++;;
    }

    //右上,左上,右下,左下 に対して それぞれの色を割り振ったときのコストを計算 level k-1 のときのコストも計算
    vector<vector<int>> cost(4,vector<int>(4));
    REP(i,4){ //lu, ld, ru, rd
        int num = accumulate(ALL(point_cnt[i]), 0);
        if(num == 0) continue;
        REP(j,4){//j,o,i,level-1
            if(j==3){ //level k-1に割り振る
                int l_ = l, r_ = (l+r)/2;
                if(not (i>>1&1)) l_ = r_, r_ = r;
                int u_ = u, d_ = (u+d)/2;
                if(not (i&1)) u_ = d_, d_ = d;
                cost[i][j] = dfs(level-1, l_, r_, u_, d_);
            }else{
                //色j
                cost[i][j] = num - point_cnt[i][j];
            }
        }
    }

    //4!全探索
    vector<int> idx = {0,1,2,3};
    int res = inf;
    do{
        chmin(res, cost[0][idx[0]] + cost[1][idx[1]] + cost[2][idx[2]] + cost[3][idx[3]]);
    }while(next_permutation(ALL(idx)));
    
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    string JOI = "JOI";
    REP(i,M){
        int a,b; char c; cin >> a >> b >> c;
        P.emplace_back(--a,--b,find(ALL(JOI), c) - JOI.begin());
    }

    int ans=dfs(N, 0, 1<<N, 0, 1<<N);
    cout << ans << endl;
}