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
struct mint {
  ll x;
  mint(ll x=0):x(x%MOD){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime MOD
  mint inv() const {
    return pow(MOD-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};
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
mint dfs(int now,int from);
//fixed<<setprecision(10)<<ans<<endl;
int N,K;
vector<vector<int>> edge;
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K ;
    edge.resize(N);
    REP(i,N-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    mint ans = dfs(0,-1)*K;

    cout << ans.x << endl;
}

mint dfs(int now,int from){
    if (edge[now].size() >=K) return 0;
    int can_color_num; //nowの子に使える色の種類
    if(from==-1){//親がいないならnowに使った色以外使える
        can_color_num = K-1;
    }else{//nowとnowの親以外の色を使える
        can_color_num = K-2;
    }

    mint res = 1;
    for(auto to:edge[now]){
        if(to==from) continue;
        res*=can_color_num--;
        res*=dfs(to,now);
    }
    return res;
}