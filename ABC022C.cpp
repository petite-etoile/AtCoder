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
const int inf = (1<<30)-1;
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



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vector<vector<int>> D(N,vector<int>(N,inf));
    REP(i,N) D[i][i]=0;
    map<int,int> start_edge;
    int a,b,l;
    REP(i,M){
        cin>>a>>b>>l;
        a--; b--;
        if(a){
            D[a][b] = l;
            D[b][a] = l;
        }else{
            start_edge[b]=l;
        }
    }
    REP(k,N){
        REP(i,N){
            REP(j,N){
                chmin(D[i][j],D[i][k]+D[k][j]);
            }
        }
    }
    int ans = inf;
    int to,len;
    REP(i,N){
        if(start_edge[i]==0) continue;
        for(int j=i+1;j<N;j++){
            if(i==j || i==0) continue;
            if(start_edge[j]==0) continue;
            chmin(ans, start_edge[i]+start_edge[j]+D[i][j]);
        }
    }
    if (ans>=inf) cout << -1 << endl;
    else cout << ans << endl;
}