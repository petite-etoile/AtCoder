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

int f(char c){
    if(c=='R') return 1;
    if(c=='G') return 2;
    if(c=='B') return 4;
    cerr << " error" << bn;
    return 0;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    string S;
    cin >> N >> S;
    vector<int64> cnt_R(N),cnt_G(N),cnt_B(N);
    int64 ans=0;
    REP(i,N){
        if(i){
            cnt_R[i]=cnt_R[i-1];
            cnt_G[i]=cnt_G[i-1];
            cnt_B[i]=cnt_B[i-1];
        }
        if(S[i] == 'R') {
            cnt_R[i]++;
            ans += cnt_G[i]*cnt_B[i];
        }
        if(S[i] == 'G') {
            cnt_G[i]++;
            ans += cnt_R[i]*cnt_B[i];
        }
        if(S[i] == 'B') {
            cnt_B[i]++;
            ans += cnt_G[i]*cnt_R[i];
        }
    }
    REP(i,N){
        REP(k,N){
            if(i+2*k>=N)break;
            auto tmp = f(S[i]) + f(S[i+k]) + f(S[i+2*k]);
            if(tmp==7) ans--;
        }
    }


    cout << ans << endl;
}