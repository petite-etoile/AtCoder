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
const ll INF = 1LL << 62;
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

int N,M;
vector<vector<bool>> mat;
int dfs(vector<bool> A, int d){ //A[d] == true => i人目を採用
    if(d==N){ //check
        int group_size = 0; //派閥に属する人数
        REP(i,N) if(A[i]) group_size++;
        REP(i,N){
            if(not A[i]) continue; //派閥に入ってない
            REP(j,N){
                if(not A[j]) continue; //派閥に入ってない
                if(not mat[i][j]) return 0; //iとjが知り合いじゃない
            }
        }
        return group_size; //全員知り合いだったので、派閥の大きさを返す
    }

    int res = 0;
    chmax(res, dfs(A, d+1)); //dを不採用
    A[d] = true;
    chmax(res, dfs(A, d+1)); //dを採用
    return res; //dを採用した場合と不採用だった場合の最大値を返す
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    mat.assign(N, vector<bool>(N,false));
    int x,y;
    REP(i,M) cin >> x >> y, x--,y--, mat[x][y]=true, mat[y][x]=true;
    REP(i,N) mat[i][i]=true;

    vector<bool> A(N);    
    cout << dfs(A, 0) << '\n';
    return 0;


    int max_bit = 1<<N;
    int ans=0;
    REP(mask,max_bit){
        bool ok = true;
        int cnt = 0;
        REP(i,N){
            if(!(mask>>i&1)) continue;
            cnt++;
            REP(j,N){
                if(!(mask>>j&1)) continue;
                if(!mat[i][j]) {ok=false; break;}
            }
        }
        if(ok) chmax(ans,cnt);
    }
    cout << ans << endl;
}