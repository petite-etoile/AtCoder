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
typedef long long ll;
using namespace std;
using P = pair<ll, ll>;
typedef vector<int> vi;
const int MOD = (int)1e9 + 7;
const ll INF = 1LL << 62;
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

struct Medicine{
    int a,b,c;
    Medicine(int a,int b,int c):a(a),b(b),c(c){};
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Ma,Mb;
    cin >> N >> Ma >> Mb;
    vector<Medicine> Med;
    int a,b,c;
    REP(i,N){
        cin >>a>>b>>c;
        Med.emplace_back(a,b,c);
    }
    int MAX_capa=10*40;
    vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(MAX_capa+1,vector<int>(MAX_capa+1,inf)));

    dp[0][Med[0].a][Med[0].b]=Med[0].c;
    REP(i,N){
        dp[i][0][0]=0;
        REP(A,MAX_capa){
            REP(B,MAX_capa){
                a=Med[i].a;
                b=Med[i].b;
                c=Med[i].c;
                if(A+a<=MAX_capa && B+b<=MAX_capa)
                    chmin(dp[i+1][A+a][B+b],dp[i][A][B]+c);
                chmin(dp[i+1][A][B],dp[i][A][B]);
            }
        }    
    }
    // REP(i,N){
    //     REP(A,MAX_capa){
    //         REP(B,MAX_capa){
    //             auto v = dp[i][A][B];
    //             // if (v==inf) cout << "inf" << " ";
    //             // else cout << v << " " ;
    //         }
    //     }
    //     cout << endl << endl;
    // }
    int ans=inf;
    for(int a=Ma,b=Mb; a<=MAX_capa&&b<=MAX_capa; a+=Ma,b+=Mb){
        chmin(ans,dp[N][a][b]);
    }
    if (ans!=inf)
        cout << ans << endl;
    else
        cout << -1 << endl;
}