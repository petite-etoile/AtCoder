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



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int64 N,D; cin >> N >> D;


    auto M = D;
    int two = 0, three = 0, five = 0;
    while(M%2==0) {two++; M/=2;}
    while(M%3==0) {three++; M/=3;}
    while(M%5==0) {five++; M/=5;}


    //DP[i][j][k][l]:=サイコロをi回降った中で(ちょうど)2^j * 3^k * 5^l を素因数に持つ確率
    vector<vector<vector<vector<long double>>>> DP(N+1, vector<vector<vector<long double>>>(two+1, vector<vector<long double>>(three+1, vector<long double>(five+1, 0))));
    DP[0][0][0][0] = 1;

    REP(i,N){
        for(int j=0; j<=two; j++){
            for(int k=0; k<=three; k++){
                for(int l=0; l<=five; l++){
                    DP[i+1][j][k][l] += DP[i][j][k][l]; //1
                    DP[i+1][min(j+1, two)][k][l] += DP[i][j][k][l]; //2
                    DP[i+1][j][min(k+1, three)][l] += DP[i][j][k][l]; //3
                    DP[i+1][min(j+2, two)][k][l] += DP[i][j][k][l]; //4
                    DP[i+1][j][k][min(l+1,five)] += DP[i][j][k][l]; //5
                    DP[i+1][min(j+1, two)][min(k+1, three)][l] += DP[i][j][k][l]; //6
                }
            }
        }
    }


    long double ans = DP[N][two][three][five];
    REP(_,N) ans /= 6.0;
    if(M==1) cout << fixed<<setprecision(10) << ans << endl;
    else cout << 0 << bn;
}