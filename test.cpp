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
#define mt make_tuple
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
//fixed<<setprecision(10)<<ans<<endl;

int H,W;
bool is_inside(int h,int w){
    return (0<=h && h<H && 0<=w && w<W);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    vector<string> grid(H);
    vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
    int sh,sw;
    for(int i=0;i<H;i++){
        cin >> grid[i];
        for(int j=0;j<W;j++){
            if(grid[i][j]=='S'){
                sh = i;
                sw = j;
            }
        }
    }
    

    vector<vector<int>> dist(H,vector<int>(W,inf));
    

    priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>> , greater<tuple<int,int,int,int>>> q;

    q.push(mt(0,0,sh,sw));
    vector<vector<bool>> visited(H,vector<bool>(W,false));
    
    int from_h,from_w,d,break_cnt;
    int to_h,to_w,cost;
    int dh,dw;
    while(!q.empty()){
        tie(d,break_cnt,from_h,from_w) = q.top(); q.pop();

        // cout << visited << endl;
        if (visited[from_h][from_w]) continue;
        visited[from_h][from_w] = true;
        dist[from_h][from_w] = d;
        for(auto dhw:dxdy){
            tie(dh,dw)=dhw;
            to_h = from_h+dh;
            to_w = from_w+dw;
            if(!is_inside(to_h,to_w)){
                // cout << "out "<<endl;
                // debug(to_h)
                // debug(to_w)
                continue;
            }
            if(visited[to_h][to_w]){ //すでに確定済み
                // cout << "visited" << endl;
                // debug(to_h)
                // debug(to_w)
                continue;
            }
            if(grid[to_h][to_w] == '#'){
                cost = break_cnt+1; //壊す+進む
                q.push(mt(d+cost,break_cnt+1,to_h,to_w));
            }else if(grid[to_h][to_w] == '.'){
                cost = 1;
                q.push(mt(d+cost,break_cnt,to_h,to_w));
            }else{  //ゴール
                cout << d+cost << endl;
                return 0;
            }
        }
    }
    return 0;
}