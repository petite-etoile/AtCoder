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
const ll INF = 1LL << 60;
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
//fixed<<setprecision(10)<<ans<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H,W,K,V;
    cin >> H >> W >> K >> V;
    vector<vector<ll>> A(H,vector<ll>(W));
    REP(i,H){
        REP(j,W){
            cin >> A[i][j];
        }
    }
    vector<vector<ll>> cumsum(H+1,vector<ll>(W+1,0));
    REP(i,H){
        REP(j,W){
            cumsum[i+1][j+1] = A[i][j];
        }
    }
    REP(i,H+1){
        REP(j,W){
            cumsum[i][j+1] += cumsum[i][j];
        }
    }
    REP(i,H){
        REP(j,W+1){
            cumsum[i+1][j] += cumsum[i][j];
        }
    }
    
    
    
    // debug(cumsum)
    
    
    
    ll ans=0;
    bool ok;
    REP(up,H){
        for(int bot=up;bot<H;bot++){
            REP(left,W){
                for(int right=left;right<W;right++){
                    ll sums = cumsum[bot+1][right+1]-cumsum[up][right+1]-cumsum[bot+1][left]+cumsum[up][left];
                    ll cnt = (bot-up+1)*(right-left+1);
                    if(sums <= V-cnt*K ) ok = true;
                    else ok = false;
                    // cout << up << " " << bot << " " << left << " " << right <<  "s" << sums << " " << ok << endl;
                    // debug(cumsum[bot][left])

                    if(ok){
                        chmax(ans, cnt);
                    }
                }
            }
        }
    }



    cout << ans << endl;
}
