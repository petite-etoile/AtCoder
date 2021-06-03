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
#include <bits/stdc++.h>
typedef long long int64;
typedef long double ld;
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
template <typename T>
ostream& operator<<(ostream& os, pair<T,T> const&P){
    os << P.first;
    os << " ";
    os << P.second;
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
//fixed<<setprecision(10)<<ans<<endl;














int N,x[301],y[301];


ld get_r(ld X, ld Y){
    ld ret = 0;
    
    for(int i = 0;i < N;++i)
        ret = max(ret,(X - x[i]) * (X - x[i]) + (Y - y[i]) * (Y - y[i]));
    
    return ret;
}

ld searchY(ld X){
    ld lo = 0,hi = 1000;
    
    for(int it = 0;it < 100;++it){
        ld a = (2 * lo + hi) / 3;
        ld b = (lo + 2 * hi) / 3;
        
        ld ra = get_r(X,a);
        ld rb = get_r(X,b);
        
        if(ra < rb) hi = b;
        else lo = a;
    }
    
    return get_r(X,lo);
}

ld searchX(){
    ld lo = 0,hi = 1000;
    
    for(int it = 0;it < 100;++it){
        ld a = (2 * lo + hi) / 3;
        ld b = (lo + 2 * hi) / 3;
        
        ld ra = searchY(a);
        ld rb = searchY(b);
        
        if(ra < rb) hi = b;
        else lo = a;
    }
    
    return searchY(lo);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i,N){ cin >> x[i] >> y[i];}

    ld ans = sqrt(searchX());
    cout << fixed<<setprecision(10)<<ans<<endl;
}