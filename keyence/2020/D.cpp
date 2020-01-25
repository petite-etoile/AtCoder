//bitDP






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
template <typename T>
ostream& operator<<(ostream& os, vector<T> &V){
    int N = V.size();
    REP(i,N){
        os << i;
        os << ":  ";
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
    int N;
    cin >> N;

    vector<int> A(N),B(N);
    REP(i,N) cin >> A[i];
    REP(i,N) cin >> B[i];

    int max_bit = 1<<N;
    vector<vi> dp(max_bit, vi(N,inf));
    REP(i,N) dp[1<<i][i] = i;

    int from_num;
    int to_num;
    for(int mask=1;mask<max_bit;mask++){
        int idx = -1; //右端の添字
        REP(i,N) if(mask>>i&1) idx++;
        map<int,int> not_in_mask; //mask_bit に含まれていないやつたちの居場所
        int not_in_mask_idx = idx;
        REP(i,N){
            if(not (mask>>i&1)){
                not_in_mask[i] = ++not_in_mask_idx;
            }
        }

        REP(from,N){
            if(not (mask>>from&1)) continue;
            int from_mask = mask; //- (1<<from);
            if(abs(idx-from)&1) from_num = B[from];
            else from_num = A[from];
            REP(to,N){
                int to_idx = not_in_mask[to];
                int move_cnt = abs(abs(to-to_idx)-(idx+1));
                if(move_cnt&1) to_num=B[to];
                else to_num=A[to];
                if (from_num>to_num) continue;
                int to_mask = mask|(1<<to);

                chmin(dp[to_mask][to], dp[from_mask][from] + abs(to_idx-(idx+1)));
                debug("AAAAAAAAAAAAA")
                debug(move_cnt);
                debug(mp(to_idx,idx+1))
                debug(mp(from_num, to_num))
                debug(to);
                debug(from_mask);
                debug(dp[from_mask]);
                debug(to_mask)
                debug(dp[to_mask]);
            }
        }
    }
    cout << dp << endl;
    int ans = *min_element(ALL(dp[(1<<N)-1]));

    cout << ans << endl;
}