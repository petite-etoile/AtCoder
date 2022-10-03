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



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N,S;
    cin >> N >> S;
    vector<int> A(N),B(N);
    REP(i,N){
        cin >> A[i] >> B[i];
    }

    vector<vector<int>> dp(N+1, vector<int>(S+1,0));
    dp[0][0] = 1;
    REP(i,N){
        REP(s,S){
            if(dp[i][s] == 0) continue;
            if(s + A[i] <= S){
                dp[i+1][s+A[i]] = 1;
            }
            if(s + B[i] <= S){
                dp[i+1][s+B[i]] = 1;
            }
        }
    }


    if(dp[N][S]){
        cout << "Yes" << endl;
        string ans = "";
        int val = S;
        for(int i=N-1;i>=0;i--){
            if(val-A[i] >= 0 and dp[i][val-A[i]]){
                ans += "H";
                val -= A[i];
            }else if(val-B[i] >= 0 and dp[i][val-B[i]]){
                ans += "T";
                val -= B[i];
            }else{
                assert(false);
            }
        }
        reverse(ALL(ans));
        cout << ans << endl;

    }else{
        cout << "No" << endl;
    }


}