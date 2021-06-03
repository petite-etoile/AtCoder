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



vector<long double> plus_vec,minus_vec,zeros;
int64 K;
//X"以下"の数がk-1個以下
bool is_low(int64 X){
    if(X==0) return int64(plus_vec.size()) * minus_vec.size() + int64(zeros.size())*(zeros.size()-1)/2 + int64(zeros.size()) * (plus_vec.size()+minus_vec.size())< K;
    int64 low_cnt = 0;

    for(auto a:plus_vec){
        long double need = abs(X)/a;
        if(X<0){
            low_cnt += minus_vec.end() - lower_bound(ALL(minus_vec), need);
        }else if(X>0){
            low_cnt += upper_bound(ALL(plus_vec) , need) - plus_vec.begin();
            low_cnt += minus_vec.size();
            if(a*a<=X) low_cnt--;
            low_cnt += zeros.size() * 2;
        }
    }


    for(auto a:minus_vec){
        long double need = abs(X)/a;
        if(X<0){
            low_cnt += plus_vec.end() - lower_bound(ALL(plus_vec) , need);
        }else if(X>0){
            low_cnt += upper_bound(ALL(minus_vec), need) - minus_vec.begin();
            low_cnt += plus_vec.size();
            if(a*a<=X) low_cnt--;
            low_cnt += zeros.size() * 2;
        }
    }
    if(X>0) low_cnt += int64(zeros.size()) * (zeros.size() - 1) ; 

    low_cnt /= 2;
    
    return low_cnt < K;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N >> K;
    
    vector<int64> A(N);
    REP(i,N){
        cin >> A[i];
        if (A[i]>0) plus_vec.emplace_back(A[i]);
        else if(A[i]==0) zeros.emplace_back(0);
        else minus_vec.emplace_back(-A[i]);
    }

    sort(ALL(minus_vec));
    sort(ALL(plus_vec));

    int64 low = -1e18, high = 1e18+1;
    while(high-low>1){
        int64 mid = (high+low)/2;
        if(is_low(mid)) low = mid;
        else high = mid;
    }

    int64 ans=high;
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


// bool low_cnt_less_than_K(int64 X);

// int64 K;
// vector<int64> A;
// int main(){
//     cin.tie(0);
//     ios::sync_with_stdio(false);
//     int N;
//     cin >> N >> K;
    
//     A.resize(N);
//     REP(i,N)  cin >> A[i];
//     sort(ALL(A));

//     int64 low = -1e18-1, high = 1e18+1;
//     while(high-low>1){
//         int64 mid = (high+low)/2;
//         if(low_cnt_less_than_K(mid)) low = mid;
//         else high = mid;
//     }

//     int64 ans=high;
//     cout << ans << endl;
// }


// //X"以下"の数がk-1個以下
// bool low_cnt_less_than_K(int64 X){
//     int N = A.size();
//     int64 low_cnt = 0;
//     REP(i,N-1){
//         int64 a = A[i];
//         if(a==0){
//             if(X>=0) low_cnt+=N-i-1;
//         }else if(a > 0){
//             int64 lower_b = i, upper_b = N;
//             while(upper_b-lower_b>1){
//                 int64 mid = (upper_b+lower_b)/2;
//                 if(A[mid] * a <= X){
//                     lower_b = mid;
//                 }else{
//                     upper_b = mid;
//                 }
//             }
//             low_cnt += upper_b - i - 1;   
//         }else{
//             int64 lower_b = i, upper_b = N;
//             while(upper_b-lower_b>1){
//                 int64 mid = (upper_b+lower_b)/2;
//                 if(A[mid] * a <= X){
//                     upper_b = mid;
//                 }else{
//                     lower_b = mid;
//                 }
//             }
//             low_cnt += N - upper_b;
//         }
//     }
    
//     return low_cnt < K;
// }