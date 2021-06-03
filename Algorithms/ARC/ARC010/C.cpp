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
//fixed<<setprecision(10)<<ans<<endl;

string bin(int n){
    string s = "";
    while(n>0){
        string b = to_string(n%2);
        s = b+s;
        n>>=1;
    }
    return s;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N,M,Y,Z; cin >> N >> M >> Y >> Z;
    
    map<char,int> color;
    vector<int64> score(M);
    vector<vector<vector<int64>>> DP(2,vector<vector<int64>>(1<<M, vector<int64>(M,-INF)));
    DP[0][0][0] = 0;
    DP[1][0][0] = 0;
    REP(i,M){
        char c; int64 s; cin >> c >> s;
        color[c] = i;
        score[i] = s;
    }
    
    string S; cin >> S;
    REP(i,N){
        char s = S[i];
        int new_color = color[s];
        for(int mask = (1<<M)-1; mask >= 0; mask--){
            REP(last_color,M){
                if(DP[i&1][mask][last_color] == -INF) continue;
                chmax(DP[(i&1)^1][mask][last_color],DP[i&1][mask][last_color]);
                
                int64 tmp = DP[i&1][mask][last_color] + score[new_color];
                if(mask&(1<<new_color) and last_color == new_color){
                    tmp += Y;
                }
                chmax(DP[(i&1)^1][mask | (1<<new_color)][new_color], tmp);
            }
        }
    }
    int64 ans = 0;
    REP(mask,1<<M){
        if(mask == (1<<M)-1){
            chmax(ans, *max_element(ALL(DP[0][mask])) + Z );
            chmax(ans, *max_element(ALL(DP[1][mask])) + Z );
        }else{
            chmax(ans, *max_element(ALL(DP[0][mask])));
            chmax(ans, *max_element(ALL(DP[1][mask])));
        }
    }


    cout << ans << endl;
}