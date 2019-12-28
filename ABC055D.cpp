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
        os << "\n";
    }
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, pair<T,T> const&P){
    os << "(";
    os << P.first;
    os << " ";
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
//fixed<<setprecision(10)<<ans<<endl;

ll H,W;
bool is_inside(int h,int w){
    return (0<=h && h<H-2 && 0<=w && w<W-2);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> H >> W >> N;
    map<pair<int,int>,ll> cnt;
    int a,b;
    REP(i,N){
        cin >> a >> b;
        a--;b--;
        for(int dx=-2;dx<=0;dx++){
            for(int dy=-2;dy<=0;dy++){
                if(is_inside(a+dy,b+dx)){
                    cnt[mp(a+dy,b+dx)]++;
                }
            }
        }
    }

    vector<ll> ans(10,0);
    ans[0]=(H-2)*(W-2);
    pair<int,int> where;
    ll num=0;
    for(auto m:cnt){
        tie(where,num)=m;
        ans[num]++;
        ans[0]--;
    }



    cout << ans << endl;
}