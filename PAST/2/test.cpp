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

struct cumsum2D{
    int H,W;
    vector<vector<int64>> cumsum;
    cumsum2D(vector<vector<int64>> A) :H(A.size()), W(A[0].size()){
        cumsum.assign(H+1, vector<int64>(W+1,0));
        for(int h=0;h<H;h++){
            for(int w=0;w<W;w++){
                cumsum[h+1][w+1] = A[h][w];
            }
        }

        for(int h=0;h<H;h++){
            for(int w=0;w<W;w++){
                cumsum[h+1][w+1] += cumsum[h+1][w] + cumsum[h][w+1] - cumsum[h][w];
            }
        }
    }

    // return sum(A[h][w]) {h,w | h in [h_begin, h_end) and w in [w_begin, w_end)}
    int64 get(int h_begin, int h_end, int w_begin, int w_end){
        return cumsum[h_end][w_end] - cumsum[h_begin][w_end] - cumsum[h_end][w_begin] + cumsum[h_begin][w_begin];
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N,Q;
    cin >> N >> Q;
    vector<int64> X,Y;
    vector<tuple<int64,int64,int64,int64,int64>> LRUDC;
    int64 l,r,u,d;
    int64 D,C;
    REP(i,N){
        cin >> l >> u >> D >> C;
        r = l + D;
        d = u + D;
        LRUDC.emplace_back (l,r,u,d,C);
        X.emplace_back(l);
        X.emplace_back(r+1);
        Y.emplace_back(u);
        Y.emplace_back(d+1);
    }

    vector<pair<int64,int64>> XY;
    REP(i,Q){
        int64 x,y;
        cin >> x >> y;
        XY.emplace_back(x,y);
        X.emplace_back(x);
        Y.emplace_back(y);
    }


    //---------座圧------------
    X.emplace_back(INF);
    Y.emplace_back(INF);
    sort(ALL(X));
    X.erase(unique(ALL(X)), X.end());
    sort(ALL(Y));
    Y.erase(unique(ALL(Y)), Y.end());
    
    map<int64,int> x_enc,y_enc;
    REP(i,X.size()){
        x_enc[X[i]] = i;
    }
    REP(i,Y.size()){
        y_enc[Y[i]] = i;
    }

    vector<vector<int64>> A(X.size(),vector<int64>(Y.size(),0));

    //---------2次元imos---------
    for(auto& e:LRUDC){
        tie(l,r,u,d,C) = e;
        l = x_enc[l], r = x_enc[r+1], u = y_enc[u], d = y_enc[d+1];
        // debug(mp(mp(l,r),mp(u,d)))
        A[l][u] += C;
        A[l][d] -= C;
        A[r][u] -= C;
        A[r][d] += C;
    }

    cumsum2D cumsum(A);
    debug(cumsum.cumsum)
    for(auto e:XY){
        int64 x,y; tie(x,y) = e;
        x = x_enc[x], y = y_enc[y];
        auto ans = cumsum.cumsum[x+1][y+1];//cumsum.get(0,x+1,0,y+1);
        cout << ans << bn;
    }
}
