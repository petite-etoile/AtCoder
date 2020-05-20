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
#pragma region macro
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
#define bn '\n'
template <typename T>
ostream& operator<<(ostream& os, const vector<T> &V){
    int N = V.size();
    REP(i,N){
        os << V[i];
        if (i!=N-1) os << " ";
    }
    os << "\n";
    return os;
}
template <typename T,typename S>
ostream& operator<<(ostream& os, pair<T,S> const&P){
    os << "(";
    os << P.first;
    os << " , ";
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
template <typename T,typename S>
ostream& operator<<(ostream& os, map<T,S> const&M){
    for(auto e:M){
        os<<e;
    }
    os<<endl;
    return os;
}
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
#pragma endregion
//fixed<<setprecision(10)<<ans<<endl;

int64 pow(int a,int b,int mod){
    vector<bool> bit;
    for(b=b;b>0;b>>=1){
        bit.push_back(b&1);
    }
    vector<int64> fac(bit.size()); fac[0] = a;
    int64 res = 1;
    for(int i=1;i<bit.size();i++){
        fac[i] = (fac[i-1] * fac[i-1])%mod;
    }
    for(int i=0;i<bit.size();i++){
        if(bit[i]) res*=fac[i];
        res%=mod;
    }
    return res;
}


//mint
struct mint {
    int64 x;
    mint(int64 x=0):x((x+2*MOD)%MOD){}
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
    mint pow(int64 t) const {
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
ostream& operator<<(ostream& os, mint a){
    os << a.x;
    return os;
}

vector<int64> dijkstra(vector<vector<pair<int64,int64>>> const& edge, int64 start){
    int64 N = edge.size();
    vector<int64> dist(N,INF);
    priority_queue<pair<int64,int64>,vector<pair<int64,int64>>, greater<pair<int64,int64>> > q;
    q.push(mp(0, start));
    vector<bool> visited(N,false);
    
    int64 from,d;
    int64 to,cost;
    while(!q.empty()){
        tie(d,from) = q.top(); q.pop();
        if (visited[from]) continue;
        visited[from] = true;
        dist[from] = d;
        for(auto e:edge[from]){
            tie(to,cost) = e;
            if (visited[to]) continue;
            if(chmin(dist[to], int64(d+cost)))
                q.push(mp(d+cost, to));
        }
    }

    return dist;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int64 N,M,s,t;
    cin >> N >> M >> s >> t;
    s--;t--;
    int64 a,b,c;
    vector<vector<pair<int64,int64>>> edge(N);
    vector<tuple<int64,int64,int64>> ABC;
    REP(i,M){
        cin >> a >> b >> c;
        --a;--b;
        ABC.emplace_back(a,b,c);
        edge[a].emplace_back(b,c);
        edge[b].emplace_back(a,c);
    }   

    auto dist = dijkstra(edge, s);

    vector<mint> dp1(N,0),dp2(N,0);
    dp1[s] = 1;
    dp2[t] = 1;
    
    vector<pair<int64,int64>> d;
    REP(i,N) d.emplace_back(dist[i],i);
    sort(ALL(d));

    REP(i,N){
        int64 from,dist_from;
        tie(dist_from, from) = d[i];
        for(auto e:edge[from]){
            int64 to,cost;
            tie(to,cost) = e;
            if(dist[to] > dist_from + cost) dp1[to] = dp1[from];
            if(dist[to] == dist_from + cost) dp1[to] += dp1[from];
        }
    }

    for(int i=N-1;i>=0;i--){
        int64 from,dist_from;
        tie(dist_from, from) = d[i];
        for(auto e:edge[from]){
            int64 to,cost;
            tie(to,cost) = e;
            if(dist[to] < dist_from - cost) dp2[to] = dp2[from];
            if(dist[to] == dist_from - cost) dp2[to] += dp2[from];
        }
    }

    mint ans = dp1[t]*dp1[t];

    REP(i,N){
        if(dist[t] ==  2*dist[i]) ans -= dp1[i]*dp1[i]*dp2[i]*dp2[i];
    }

    for(auto e:ABC){
        int64 a,b,c;
        tie(a,b,c) = e;
        if(dist[a]>dist[b]) swap(a,b);
        if(dist[a]+c==dist[b] and dist[a]*2<dist[t] and dist[b]*2>dist[t]){
            ans -= dp1[a]*dp1[a]*dp2[b]*dp2[b];
        }
    }

    cout << ans << endl;
}