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
    int H,W,K;
    cin >> H >> W >> K;
    vector<string> Sv(H);
    REP(i,H){
        cin >> Sv[i];
    }
    vector<vector<int>> continuous(H,vector<int>(W,0));
    REP(w,W){
        REP(h,H){
            if(h==0){
                continuous[h][w]=(Sv[h][w]=='o');
                continue;
            }
            if(Sv[h][w]=='o'){
                continuous[h][w]=continuous[h-1][w]+1;
            }else{
                continuous[h][w]=0;
            }
        }
    }
    // cout << continuous;

    int ans = 0;
    for(int w=K-1;w<W-K+1;w++){
        for(int h=K-1;h<H-K+1;h++){
            bool ok = true;
            REP(k,K){
                int depth = K-1-k;
                // cout << mp(h,w) << " " << k << " " << depth <<  ":" << continuous[h+depth][w+k] << endl;
                if(continuous[h+depth][w+k]<2*(K-k)-1){
                    // debug(2*(K-k))
                    ok=false;
                    break;
                }
                // cout << mp(h,w) << " " << k << " " << depth <<  ":" << continuous[h+depth][w-k] << endl;
                if(continuous[h+depth][w-k]<2*(K-k)-1){
                    ok=false;
                    break;
                }
            }
            ans+=ok;
            // if(ok)debug(mp(h,w))
        }
    }


    cout << ans << endl;
}