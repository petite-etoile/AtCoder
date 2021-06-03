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



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int64> A(2*N);
    REP(i,N) cin >> A[i];
    REP(i,N) A[i+N] = A[i];

    vector<vector<int64>> DP(N,vector<int64>(N,0)); //DP[i][j] = [i,j]のケーキを最適に取った時の
    REP(i,N) DP[i][i] = A[i], DP[i][(i+1)%N] = max(A[i],A[i+1]);

    for(int len=3;len<=N;len++){
        REP(l, N){
            int r = l + len - 1;
            
            //lを取る
            if(A[(l+1)%N] > A[r%N]){
                chmax(DP[l][r%N], A[l] + DP[(l+2)%N][r%N]);
            }else{
                chmax(DP[l][r%N], A[l] + DP[(l+1)%N][(r-1+N)%N]);
            }

            //rを取る
            if(A[l] > A[(r-1+N)%N]){
                chmax(DP[l][r%N], A[r] + DP[(l+1)%N][(r-1+N)%N]);
            }else{
                chmax(DP[l][r%N], A[r] + DP[l][(r-2+N)%N]);
            }
        }
    }

    int64 ans=0;
    REP(l,N){
        int r = l+N-1;
        chmax(ans, DP[l][r%N]);
    }

    cout << ans << endl;
}

// /*
// 　　　∫ ∫ ∫
// 　　　ノヽ
// 　　（＿　 ）
// 　（＿　　　 ）
// （＿＿＿＿＿＿ ）
// 　ヽ(´･ω･)ﾉ　
// 　　 |　 /
// 　　 UU
// */
// #pragma region macro
// #include <bits/stdc++.h>
// typedef long long int64;
// using namespace std;
// using P = pair<int64, int64>;
// typedef vector<int> vi;
// const int MOD = (int)1e9 + 7;
// const int64 INF = 1LL << 62;
// const int inf = 1<<30;
// template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
// template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
// #define REP(i, n) for (int i = 0; i < (n); i++)
// #define FOR(i,s,n) for (int i = s; i < (n); i++)
// #define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
// #define debug(x) cerr << #x << ": " << x << "\n";
// #define mp make_pair
// #define bn '\n'
// template <typename T>
// ostream& operator<<(ostream& os, vector<T> &V){
//     int N = V.size();
//     REP(i,N){
//         os << V[i];
//         if (i!=N-1) os << " ";
//     }
//     os << "\n";
//     return os;
// }
// template <typename T,typename S>
// ostream& operator<<(ostream& os, pair<T,S> const&P){
//     os << "(";
//     os << P.first;
//     os << " , ";
//     os << P.second;
//     os << ")";
//     return os;
// }
// template <typename T>
// ostream& operator<<(ostream& os, set<T> &S){
//     auto it=S.begin();
//     while(it!=S.end()){
//         os << *it;
//         os << " ";
//         it++;
//     }
//     os << "\n";
//     return os;
// }
// template <typename T>
// ostream& operator<<(ostream& os, deque<T> &q){
//     for(auto it=q.begin();it<q.end();it++){
//         os<<*it;
//         os<<" ";
//     }
//      os<<endl;
//     return os;
// }
// vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
// #pragma endregion
// //fixed<<setprecision(10)<<ans<<endl;



// int main(){
//     cin.tie(0);
//     ios::sync_with_stdio(false);
//     int N;
//     cin >> N;
//     vector<int64> A(2*N);
//     REP(i,N) cin >> A[i];
//     REP(i,N) A[i+N] = A[i];

//     vector<int64> cumsum(2*N+1,0);
//     REP(i,2*N) cumsum[i+1] = cumsum[i] + A[i];

//     debug(cumsum)

//     vector<vector<int64>> DP(N,vector<int64>(N,0)); //DP[i][j] = [i,j]のケーキを最適に取った時の
//     REP(i,N) DP[i][i] = A[i];
//     for(int len=2;len<=N;len++){
//         REP(l, N){
//             int r = l + len - 1;
//             DP[l][r%N] = max(A[l]+cumsum[r+1] - cumsum[l+1] - DP[(l+1)%N][r%N],   A[r]+cumsum[r] - cumsum[l] - DP[l][(r-1)%N] );
//         }
//     }

//     cout << " " << (DP);

//     int64 ans=0;
//     REP(l,N){
//         int r = l+N-1;
//         chmax(ans, DP[l][r%N]);
//     }

//     cout << ans << endl;
// }