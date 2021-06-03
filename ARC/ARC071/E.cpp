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
template <typename T,typename S,typename U>
ostream& operator<<(ostream& os, tuple<T,S,U> const& P){
    os << "(";
    os << get<0>(P);
    os << ", ";
    os << get<1>(P);
    os << ", ";
    os << get<2>(P);
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



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string S,T; int Q;
    cin >> S >> T >> Q;
    vector<pair<int,int>> cumsumS = {mp(0,0)}, cumsumT = {mp(0,0)};
    
    REP(i,S.size()){
        auto now = cumsumS.back();
        if(S[i] == 'A') now.first++;
        else now.second++;
        cumsumS.emplace_back(now);
    }

    REP(i,T.size()){
        auto now = cumsumT.back();
        if(T[i] == 'A') now.first++;
        else now.second++;
        cumsumT.emplace_back(now);
    }

    REP(_,Q){
        int a,b,c,d; cin >> a >> b >> c >> d;
        int A = ((cumsumS[b].first - cumsumS[--a].first) - (cumsumT[d].first - cumsumT[--c].first)); //S[a:b]のAの個数 と T[c:d]のAの個数の差
        int B = ((cumsumS[b].second - cumsumS[a].second) - (cumsumT[d].second - cumsumT[c].second)); //S[a:b]のBの個数 と T[c:d]のBの個数の差

        (A%=3)+=3;
        B += A*2;
        if(B%3==0) cout << "YES" << bn;
        else cout << "NO" << bn;
    }
}