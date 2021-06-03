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
int H,W;
bool is_inside(int h,int w){
    return (0<=h && h<H && 0<=w && w<W);
}
//fixed<<setprecision(10)<<ans<<endl;



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    vector<vector<int>> grid(H,vector<int>(W));
    map<int,pair<int,int>> M;
    map<pair<int,int>,int> status; //-2なら尾根,-1なら未確認,0以上なら行き先が(自身の可能性有)
    REP(i,H)REP(j,W) cin >> grid[i][j], M[grid[i][j]]=mp(i,j);
    int h,w,dx,dy;
    int cnt=0,ans=0;
    for(int i=1;i<=H*W;i++) tie(h,w)=M[i],status[mp(h,w)]=-1;
    for(int i=1;i<=H*W;i++){
        tie(h,w)=M[i];
        cnt=0;
        int before=-1;
        for(auto dxy:dxdy){
            tie(dx,dy)=dxy;
            if(is_inside(h+dy,w+dx)){
                auto st = status[mp(h+dy,w+dx)];
                if(st==-2){
                    ans++;
                    status[mp(h,w)]=-2;
                    break;
                }else if(st==-1){
                    continue;
                }else{
                    if (before!=-1&&before!=st){
                        status[mp(h,w)]=-2;
                        ans++;
                        break;
                    }else{
                        status[mp(h,w)]=st;
                        before=st;
                    }
                }
            }
        }
        if (status[mp(h,w)]==-1) status[mp(h,w)]=i;//池
    }
    cout << ans << endl;
}