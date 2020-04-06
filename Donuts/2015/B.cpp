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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vector<int> A(N);
    REP(i,N) cin >> A[i];
    vector<pair<int, vector<int>>> combo;
    int B,C;
    REP(i,M){
        cin >> B >> C;
        vector<int> vec;
        REP(j,C){
            int c;
            cin >> c;
            vec.emplace_back(--c);
        }
        combo.emplace_back(B,vec);
    }

    int64 ans = 0;

    //M個の集合からK個の部分集合を走査する
    int mask = (1 << 9) - 1; 
    while(mask < 1 << N){
        //集合に対する処理
        int64 tmp = 0;
        REP(i,N){
            if(mask >> i & 1) tmp += A[i];
        }
        REP(j,M){
            vector<int> com;
            tie(B,com) = combo[j];
            int cnt = 0;
            for(auto c:com){
                cnt += (mask>>c&1);
            }
            if(cnt >= 3) tmp += B;
        }
        chmax(ans,tmp);
        int x = mask&-mask;
        int y = mask + x;
        mask = ((mask & ~y) / x >> 1) | y;
    }


    cout << ans << endl;
}