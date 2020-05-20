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
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
//fixed<<setprecision(10)<<ans<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,C;
    cin >> N >> C;
    vector<vector<pair<int,int>>> ST_groupBy_C(C);
    int s,t,c;
    int last = 0;
    REP(i,N){
        cin >> s >> t >> c;
        c--;
        chmax(last,t);
        ST_groupBy_C[c].push_back(mp(s,t));

    }
    vector<int> cnt(last+1);
    REP(c,C){
        sort(ALL(ST_groupBy_C[c]));
        int idx = 0;
        // debug(ST_groupBy_C[c])
        REP(now,last+1){
            if(idx>=ST_groupBy_C[c].size()){
                break;
            }
            tie(s,t) = ST_groupBy_C[c][idx];
            // cout << s << " " << now << " "<< t << " " << (s-1<=now && now <= t) << endl;
            if(s<=now && now <= t){
                cnt[now]++;
            }
            if (t <= now) idx++;


        }
        // cout << cnt;

    }
    int ans=0;
    for(auto c:cnt) chmax(ans,c);



    cout << ans << endl;
}