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

typedef long double ld;
const ld eps = 5e-7;
vector<pair<ld,ld>> XY;
ld g(ld x, ld y){
    ld res = 0;
    for(auto e:XY){
        chmax(res, hypot(e.first-x, e.second-y));
    }
    return res;
}

//xが決められた時、yの位置を三分探索で決め、そのときの半径を返す
ld f(ld x){
    ld up = 0, bot = 1000;
    ld up_val = g(x,up), bot_val = g(x,bot);
    REP(i,100){
    // while(abs(up_val-bot_val) > eps){
        ld mu = (up*2 + bot) / 3, mb = (up + bot*2) / 3;
        ld mu_val = g(x,mu), mb_val = g(x,mb);

        if(mu_val < mb_val) bot = mb, bot_val = mb_val;
        else up = mu, up_val = mu_val;

    }
    return up_val;
}

//xの位置を三分探索で決める
ld TsearchX(){
    ld left = 0, right = 1000;
    ld left_val = f(left), right_val = f(right);
    REP(i,100){
    // while(abs(left_val-right_val) > eps){
        ld ml = (left*2+right)/3, mr = (left+right*2)/3;
        ld ml_val = f(ml), mr_val = f(mr);

        if(ml_val < mr_val) right = mr, right_val = mr_val;
        else left = ml, left_val = ml_val;
    }
    return left_val;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    REP(i,N){
        ld x,y; cin >> x >> y;
        XY.emplace_back(x,y);
    }

    auto ans = TsearchX();

    cout<<fixed<<setprecision(10)<<ans<<endl;
}