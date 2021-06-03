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
ostream& operator<<(ostream& os, pair<T,long double> const&P){
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
long double dijkstra(vector<vector<pair<ll,long double>>> const& edge, ll start){
    ll N = edge.size();
    vector<long double> dist(N,INF);
    priority_queue<pair<long double,ll>,vector<pair<long double,ll>>, greater<pair<long double,ll>> > q;
    q.push(mp(0, start));
    vector<bool> visited(N,false);
    
    ll from;
    long double d;
    ll to;
    long double cost;
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

    return dist[N-1];
}
//fixed<<setprecision(10)<<ans<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,L;
    cin >> N >> L;
    vector<vector<ll>> XVD(N+1,vector<ll>(3,0));
    XVD[0][0] = 0;
    cin>>XVD[0][1]>>XVD[0][2];
    REP(i,N){
        cin >> XVD[i+1][0]>> XVD[i+1][1]>> XVD[i+1][2];
    }
    N++;
    sort(ALL(XVD));
    vector<ll> X(N+1),V(N),D(N);
    REP(i,N){
        X[i] = XVD[i][0];
        V[i] = XVD[i][1];
        D[i] = XVD[i][2];
    }
    X[N] = L;
    vector<vector<pair<ll,long double>>> edge(N+1);
    REP(i,N){
        for(int j=i+1;j<=N;j++){
            if (X[j]-X[i]<=D[i]){
                long double cost = (long double)(X[j]-X[i])/V[i];
                edge[i].push_back(mp(j,cost) );
            }
        }
    }
    // cout << edge;
    long double ans=dijkstra(edge,0);

    if(ans < INF){  
        cout << int(ans) << ".";
        REP(i,10){
            ans*=10.0;
            ans-=int(ans/10)*10;
            cout << int(ans);
        }
        cout << endl;
    }
        // cout << fixed<<setprecision(10)<<ans << endl;
    else
        cout << "impossible\n";
}