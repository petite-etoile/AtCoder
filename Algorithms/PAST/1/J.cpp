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

int H,W;
int id(int h,int w){
    return h*W+w;
}

vector<ll> dijkstra(vector<vector<pair<ll,ll>>> const& edge, ll start){
    ll N = edge.size();
    vector<ll> dist(N,INF);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>> > q;
    q.push(mp(0, start));
    vector<bool> visited(N,false);
    
    ll from,d;
    ll to,cost;
    while(!q.empty()){
        tie(d,from) = q.top(); q.pop();
        if (visited[from]) continue;
        visited[from] = true;
        dist[from] = d;
        for(auto e:edge[from]){
            tie(to,cost) = e;
            if (visited[to]) continue;
            q.push(mp(d+cost, to));
        }
    }

    return dist;
}
bool is_inside(int h,int w){
    return (0<=h && h<H && 0<=w && w<W);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    vector<vi> A(H,vi(W));
    REP(i,H)REP(j,W) cin >> A[i][j];
    vector<vector<pair<ll,ll>>> edge(H*W);
    int nh,nw,dh,dw;
    REP(h,H){
        REP(w,W){
            for(auto dxy:dxdy){
                tie(dh,dw) = dxy;
                nh=h+dh;
                nw=w+dw;
                if(is_inside(nh,nw)){
                    edge[id(h,w)].emplace_back(id(nh,nw), A[nh][nw]);
                }
            }
        }
    }
    int s = id(H-1,0),v = id(H-1,W-1),t =id(0,W-1);

    ll ans=INF;
    REP(h,H){
        REP(w,W){
            auto dists = dijkstra(edge,id(h,w));
            chmin(ans, dists[s]+dists[v]+dists[t]+A[h][w]);
        }
    }



    cout << ans << endl;
}