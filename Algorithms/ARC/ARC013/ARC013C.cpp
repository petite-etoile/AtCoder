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



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int64> nim;
    int64 X,Y,Z,M;
    int64 x,y,z;
    REP(i,N){
        cin >> X >> Y >> Z >> M;
        int64 max_x = 0,max_y = 0,max_z = 0,min_x = INF ,min_y = INF ,min_z = INF;
        REP(j,M){
            cin >> x >> y >> z;
            chmin(min_x,x);
            chmax(max_x,x);
            chmin(min_y,y);
            chmax(max_y,y); 
            chmin(min_z,z);
            chmax(max_z,z);
        }
        nim.emplace_back(min_x);    
        nim.emplace_back(X-max_x-1);    
        nim.emplace_back(min_y);    
        nim.emplace_back(Y-max_y-1);    
        nim.emplace_back(min_z);    
        nim.emplace_back(Z-max_z-1);    
    }
    int64 ans=0;
    for(auto a:nim){
        ans ^= a;
    }

    if(ans){
        cout << "WIN" << bn;
    }else{
        cout << "LOSE" << bn;
    }

}