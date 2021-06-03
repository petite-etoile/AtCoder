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
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
//fixed<<setprecision(10)<<ans<<endl;

int H,W;
bool is_inside(int h,int w){
    return (0<=h && h<H && 0<=w && w<W);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    vector<string> Vs(H);
    REP(i,H) cin >> Vs[i];
    
    queue<pair<int,int>> q;
    q.push(mp(0,0));
    int h,w;
    int dh,dw,ch,cw;
    set<pair<int,int>> visited;
    int cnt=0;
    REP(i,H*W){
        queue<pair<int,int>> tmp;
        while(!q.empty()){

            tie(h,w) = q.front();q.pop();
            for(auto dhw:dxdy){
                tie(dh,dw) = dhw;
                ch=h+dh,cw=w+dw;

                if(is_inside(ch,cw)){
                    if(visited.find(mp(ch,cw)) == visited.end() && Vs[ch][cw]=='.') {
                        tmp.push(mp(ch,cw));
                        visited.insert(mp(ch,cw));
                    }
                }
                if (mp(ch,cw) == mp(H-1,W-1)){
                    cnt = i+2;
                }
            }   
        }   
        if(cnt!=0) break;
        q = tmp;
    }

    if (cnt==0){
        cout << -1 << endl;
        return 0;
    }
    int ans=H*W;
    REP(i,H){
        REP(j,W){
            ans-=(Vs[i][j]=='#');
        }
    }
    cout << ans-cnt << endl;
    
}