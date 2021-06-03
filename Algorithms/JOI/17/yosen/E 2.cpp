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
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<bitset>
#include<unordered_map>
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
//fixed<<setprecision(10)<<ans<<endl;

vector<vector<int>> grid;
int H,W;
bool is_inside(int h,int w){
    return (0<=h && h<H && 0<=w && w<W);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W;

    grid.assign(H,vector<int>(W,0));
    REP(i,H){
        REP(j,W){
            cin >> grid[i][j];
        }
    }

    vector<vector<vector<int64>>> DP(H,vector<vector<int64>>(W,vector<int64>(H*W,INF)));
    DP[0][0][0] = 0;
    int dx,dy;
    int next_h,next_w;
    REP(step,H*W){
        if(not step) step++;
        REP(i,H){
            REP(j,W){
                for(auto e:dxdy){
                    tie(dx,dy) = e;
                    next_h = i+dx;
                    next_w = j+dy;
                    if(not is_inside(next_h,next_w)) continue;
                    if(DP[next_h][next_w][step-1] == INF) continue;
                    chmin(DP[i][j][step], DP[next_h][next_w][step-1] + (step-1) * 2 * grid[i][j] + grid[i][j]);
                }
            }
        }
    }

    auto ans=*min_element(ALL(DP[H-1][W-1]));



    cout << ans << endl;
}