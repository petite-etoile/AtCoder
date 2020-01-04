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
    os << ",";
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

bool is_ok(int x, vi& A, ll V, ll P, ll M){
    int N=A.size();
    int nokori = V-(x+1);
    nokori -= P-1;

    if (nokori<=0) return A[x]+M>=A[N-P];

    ll dif_sum = 0;
    for(int i=x+1;i<=N-P;i++){
        dif_sum+=A[i]-A[x];
    }
    ll sub = ((N-P)-x-nokori)*M; //毎ターン埋められる差

    if(A[x]+M<A[N-P]) return false;
    return dif_sum <= sub;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M,V,P;
    cin >> N>>M>>V>>P;
    vi A(N);
    REP(i,N) cin >> A[i];
    sort(ALL(A));

    int ok = N-1;
    int ng = -1;
    if (!is_ok(0,A,V,P,M)) ng=0;
    while (abs(ok-ng)>1){
        int mid = (ok+ng)/2;
        // debug(mid)
        // cout << ok << " " << ng << "ok,mid,A[mid]" << A[mid]<<endl;
        if(is_ok(mid,A,V,P,M)) ok = mid;
        else ng = mid;
    }
    // debug(ok)

    int ans=N-ok;
    cout << ans << endl;
}