#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD = (int)1e9 + 7;
const int INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = s; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
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
ostream& operator<<(ostream& os, pair<T,T> &P){
    os << P.first;
    os << " ";
    os << P.second;
    os << "\n";
    return os;
}
//fixed<<setprecision(10)<<ans<<endl;
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> B(M);
    REP(i,N) cin >> A[i];
    REP(i,M) cin >> B[i];
    vector<pair<int,int>> sushi_vec(2'000'001,make_pair(-1,-1));
    REP(i,N)REP(j,M){
        int sushi = A[i]+B[j];
        int one = sushi_vec[sushi].first, two = sushi_vec[sushi].second;
        if (one==-1){
            sushi_vec[sushi]=make_pair(i,j);
        }else{
            cout << one << " " << two << " " <<  i << " " << j << " ";
            exit(0);
        }
    }
    cout << -1 << endl;

}