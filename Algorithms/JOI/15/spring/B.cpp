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

int f(int s, vector<vector<int>> const& cumsum, vector<tuple<int,int,int>> const& JOI){
    int res = 0;
    for(auto& e:JOI){
        int l,r,c; tie(l,r,c) = e;
        int s_cnt = (cumsum[c][s+r] - cumsum[c][s+l]); //[l,r)にある文字cの数
        res += (r-l) - s_cnt; //足りてない数(=変更しないといけない文字数)
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int K; string S; cin >> K >> S;
    S += S; int N = S.size(); 
    
    vector<int> A(N);
    string T = "JOI";
    REP(i,N) A[i] = find(ALL(T),S[i]) - T.begin();

    vector<vector<int>> cumsum(3,vector<int>(N+1));
    REP(i,N){
        REP(j,3){
            cumsum[j][i+1] = cumsum[j][i] + (A[i] == j);
        }
    }

    int now = 1;
    vector<tuple<int,int,int>> JOI; //tuple ( [l,r),s ) 4K個
    for(int k=K-1; k>=0; k--){
        int length = pow(4,k);
        REP(j,3){
            JOI.emplace_back(now, now+length, j);
            now += length;
        }   
    }

    int ans=inf;
    REP(i,N/2){
        chmin(ans, f(i,cumsum, JOI));
    }
    cout << ans << endl;
}

