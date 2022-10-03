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
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cassert>
#include <cmath>
#include <utility>
#include <tuple>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << (x) << "\n";
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

void simulate(int N, int bit, vector<vector<int64>> const& A, vector<vector<map<int64,int64>>>& pattern_num){
    int h=0, w=0;
    int64 val = 0;
    REP(i,N-1){
        val ^= A[h][w];
        if(bit & (1 << i)){
            h++;
        }else{
            w++;
        }
    }
    pattern_num[h][w][val]++;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int64>> A(N, vector<int64>(N)), A_rev(N, vector<int64>(N));
    REP(i,N){
        REP(j,N){
            cin >> A[i][j];
            A_rev[N-1-j][N-1-i] = A[i][j];
        }
    }

    vector<vector<map<int64,int64>>> pattern_num1(N,vector<map<int64,int64>>(N)), pattern_num2(N,vector<map<int64,int64>>(N));
    REP(bit, 1<<(N-1)){
        simulate(N, bit, A, pattern_num1);
        simulate(N, bit, A_rev, pattern_num2);
    }


    int64 ans=0;
    REP(i,N){
        REP(j,N){
            for(auto e: pattern_num1[i][j]){
                int64 val, num; tie(val, num) = e;
                ans += num * pattern_num2[i][j][val^A[i][j]];
            }
        }
    }



    cout << ans << endl;
}