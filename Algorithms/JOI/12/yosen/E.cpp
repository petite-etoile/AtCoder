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
    int N,K; cin >> N >> K;
    vector<int64> X,Y,Z;
    vector<tuple<int64,int64,int64,int64,int64,int64>> P;
    REP(i,N){
        int64 x1,x2,y1,y2,z1,z2; cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        P.emplace_back(x1,y1,z1,x2,y2,z2);
        X.emplace_back(x1); X.emplace_back(x2);
        Y.emplace_back(y1); Y.emplace_back(y2);
        Z.emplace_back(z1); Z.emplace_back(z2);
    }
    sort(ALL(X));
    sort(ALL(Y));
    sort(ALL(Z));
    X.erase(unique(ALL(X)), X.end());
    Y.erase(unique(ALL(Y)), Y.end());
    Z.erase(unique(ALL(Z)), Z.end());

    int64 ans = 0;

    REP(idx1,X.size()-1){
        int64 l=X[idx1], r=X[idx1+1];
        REP(idx2,Y.size()-1){
            int64 u=Y[idx2], d=Y[idx2+1];
            REP(idx3,Z.size()-1){
                int64 f=Z[idx3], b=Z[idx3+1];
                int cnt = 0;
                REP(k,N){
                    int64 x1,y1,z1,x2,y2,z2; tie(x1,y1,z1,x2,y2,z2) = P[k];
                    if(x1 <= l and r <= x2 and y1 <= u and d <= y2 and z1 <= f and b <= z2) cnt++;
                }
                if(cnt >= K) ans += (r-l)*(d-u)*(b-f);
            }
        }
    }

    cout << ans << endl;
}