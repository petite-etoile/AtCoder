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

int H,W;
vector<vector<int>> A;
vector<vector<bool>> checked;

bool is_inside(int h,int w){
    return (0<=h && h<H && 0<=w && w<W);
}

vector<pair<int,int>> around(int h,int w){
    vector<pair<int,int>> res;
    REP(a,3) REP(b,3){
        int dh = a-1, dw = b-1;
        int next_h = h + dh  ,next_w = w + dw;
        if(not is_inside(next_h, next_w) or mp(dh,dw) == mp(0,0)) continue;
        res.emplace_back(next_h, next_w);
    }
    return res;
}


vector<pair<int,int>> broken;
void around_decrease(int h,int w){
    int next_h,next_w;
    for(auto next_:around(h,w)){
        tie(next_h,next_w) = next_;
        A[next_h][next_w]--;
        if(A[next_h][next_w] <= 0 and not checked[next_h][next_w]){
            broken.emplace_back(next_h,next_w);
            checked[next_h][next_w] = true;
        }
    }
}



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    A.assign(H,vector<int>(W,0));
    checked.assign(H,vector<bool>(W,false));
    vector<string> grid(H);
    REP(h,H) cin >> grid[h];
    
    REP(h,H) REP(w,W) if(grid[h][w] != '.') A[h][w] = grid[h][w]-'0'; else checked[h][w] = true;
    REP(h,H) REP(w,W) if(grid[h][w] == '.') around_decrease(h,w); 
    
    int ans = 0;
    int h,w;
    while(true){
        if(broken.empty()) break;
        auto tmp = broken;
        broken.clear();
        for(auto now:tmp){
            tie(h,w) = now;
            around_decrease(h,w);
        }
        ans++;
    }
    cout << ans << bn;

}