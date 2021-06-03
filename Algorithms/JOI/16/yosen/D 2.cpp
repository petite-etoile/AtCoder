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



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N>>M;
    
    vi chara_nums(M,0);
    vi chara(N);
    REP(i,N){
        cin >> chara[i];
        chara[i]--;
        chara_nums[chara[i]]++;
    }

    vector<vector<int>> cumsum(M,vector<int>(N+1,0));
    REP(i,N){
        REP(j,M){
            cumsum[j][i+1]=cumsum[j][i]+(chara[i]==j);
        }
    }
    int max_bit = 1<<M;
    vector<int> DP(max_bit,inf);
    DP[0]=0;
    REP(mask,max_bit){
        int left = 0;
        REP(i,M){
            if((mask>>i)&1) left+=chara_nums[i];
        }
        REP(i,M){
            if((mask>>i)&1) continue;
            int right = left + chara_nums[i];
            int cost = chara_nums[i]-(cumsum[i][right]-cumsum[i][left]);
            chmin(DP[mask|(1<<i)], DP[mask]+cost);
        }
    }
    int ans=DP[max_bit-1];

    cout << ans << endl;
}