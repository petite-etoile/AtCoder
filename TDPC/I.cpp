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
ostream& operator<<(ostream& os, vector<T> &V){
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

vector<vector<int>> dp; //DP[l][r] := [l,r]で取り除ける文字数
string S;
int rec(int l, int r){
    if(dp[l][r]!=-1) return dp[l][r];
    if(r-l+1<3) return 0;
    int res = 0;
    for(int m=l+1; m<=r; m++){
        chmax(res, rec(l,m-1) + rec(m,r));
        if(S[l]=='i' && rec(l+1,m-1)==m-l-1 && S[m]=='w' && rec(m+1,r-1)==r-m-1 && S[r]=='i'){ //完全に中身が取り除けて、残ったS[l]+S[mid]+S[r]が"iwi"になってるなら[l,r]はすべて取り除ける
            res = r-l+1;
        }
    }
    dp[l][r] = res;
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    int N = S.size();

    dp.resize(N);
    REP(i,N){
        dp[i].assign(N,-1);
    }
    int ans=rec(0,N-1)/3;

    cout << ans << endl;
}
