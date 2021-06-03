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

template <typename T>
ostream& operator<<(ostream& os, queue<T> q){
    while(q.size()){
        os<<q.front(); q.pop();
        os<<" ";
    }
    os<<endl;
    return os;
}
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
#pragma endregion
//fixed<<setprecision(10)<<ans<<endl;

int H,W;
int enc(int h, int w){
    return h*W+w;
} 
bool is_inside(int h,int w){
    return (0<=h && h<H && 0<=w && w<W);
}
vector<string> grid;
queue<pair<int,int>> bfs_with_breaking(queue<pair<int,int>> q){
    vector<bool> visited(H*W);
    queue<pair<int,int>> res;
    REP(i,q.size()){
        res.push(q.front());
        q.push(q.front());
        visited[enc(q.front().first, q.front().second)] = true;
        q.pop();
    }
    int h,w;
    int to_h,to_w;
    while(not q.empty()){
        tie(h,w) = q.front(); q.pop();
        for(auto dhw:dxdy){
            tie(to_h,to_w) = mp(h+dhw.first, w+dhw.second );
            if(not is_inside(to_h, to_w)) continue;
            if(visited[enc(to_h, to_w)]) continue;
            visited[enc(to_h, to_w)] = true;
            if(grid[to_h][to_w] == '#'){
                res.push(mp(to_h,to_w));
            }else{
                q.push(mp(to_h,to_w));
                res.push(mp(to_h,to_w));
            }
        }
    }

    return res;
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
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    grid.resize(H);
    REP(i,H) cin >> grid[i];

    int s,g;
    int to_h,to_w;
    vector<vector<pair<int64,int64>>> edge(H*W);
    REP(h,H){
        REP(w,W){
            if(grid[h][w] == 's') s = enc(h,w);
            if(grid[h][w] == 'g') g = enc(h,w);
            for(auto dhw:dxdy){
                tie(to_h,to_w) = mp(h+dhw.first, w+dhw.second );
                if(not is_inside(to_h, to_w)) continue;
                if(grid[to_h][to_w] == '#'){
                    edge[enc(h,w)].emplace_back(enc(to_h,to_w), 1);
                }else{
                    edge[enc(h,w)].emplace_back(enc(to_h,to_w), 0);
                }
            }
        }
    }
    auto dist = dijkstra(edge, s);
    if(dist[g]<=2) cout << "YES" << bn;
    else cout << "NO" << bn;
    // queue<pair<int,int>> q1,q2,q3;
    // for(auto dhw:dxdy){
    //         tie(to_h,to_w) = mp(h+dhw.first, w+dhw.second );
    //         if(not is_inside(to_h, to_w)) continue;
    //         if(visited[enc(to_h, to_w)]) continue;
    //         visited[enc(to_h, to_w)] = true;
    //         if(grid[to_h][to_w] == '#'){
    //             res.push(mp(to_h,to_w));
    //         }else{
    //             q.push(mp(to_h,to_w));
    //             res.push(mp(to_h,to_w));
    //         }
    //     }
    // }

    // REP(i,H){
    //     REP(j,W){
    //         if(grid[i][j] == 's') q1.push(mp(i,j));
    //     }
    // }
    // q2 = bfs_with_breaking(q1);
    // q3 = bfs_with_breaking(q2);

    

    // vector<bool> visited(H*W,false);
    // REP(i,q3.size()){
    //     q3.push(q3.front());
    //     visited[enc(q3.front().first, q3.front().second)] = true;
    //     if(grid[q3.front().first][q3.front().second] == 'g'){
    //         cout << "YES" << bn;
    //         return 0;
    //     }
    //     q3.pop();
    // }
    // int h,w;
    // int to_h,to_w;
    // while(not q3.empty()){
    //     tie(h,w) = q3.front(); q3.pop();
    //     for(auto dhw:dxdy){
    //         tie(to_h,to_w) = mp(h+dhw.first, w+dhw.second );
    //         if(not is_inside(to_h, to_w)) continue;
    //         if(visited[enc(to_h, to_w)]) continue;
    //         visited[enc(to_h, to_w)] = true;
    //         if(grid[to_h][to_w] == '#'){
    //         }else{
    //             if(grid[to_h][to_w] == 'g'){
    //                 cout << "YES" << bn;
    //                 return 0;
    //             }
    //             q3.push(mp(to_h,to_w));
    //         }
    //     }
    // }
    // cout << "NO" << bn;
}