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
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
#pragma endregion

bool is_ok(long double t, vector<pair<int64,int64>>& ZC){
    long double l = -1e5, r = 1e5;
    long double z,c;
    for(auto e:ZC){
        tie(z,c) = e;
        long double dz = t/c;
        chmax(l, z-dz);
        chmin(r, z+dz);
    }
    return l<=r;
}

long double binary_search(long double ok, long double ng, long double eps, vector<pair<int64,int64>>& ZC){
    while(abs(ng-ok)>eps){
        auto mid = (ok+ng)/2;
        if(is_ok(mid,ZC)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<pair<int64,int64>> XC,YC;
    int64 x,y,c;
    REP(i,N){
        cin >> x >> y >> c;
        XC.emplace_back(x,c);
        YC.emplace_back(y,c);
    }
    long double ok = 1e9, ng = 0, eps = 1e-6;
    auto ans_x = binary_search(ok,ng,eps,XC);
    auto ans_y = binary_search(ok,ng,eps,YC);

    cout << fixed<<setprecision(10)<<max(ans_x, ans_y)<<endl;
}