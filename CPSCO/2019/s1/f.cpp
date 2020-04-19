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

vector<tuple<int64,int,int>> TAB;
int N;
bool is_ok(int64 x){
    vector<pair<int,int>> LR;
    int64 t,a,b;
    for(auto e:TAB){
        tie(t,a,b) = e;
        if(a-x<0) return false;
        int sub = (a-x)/b;
        LR.emplace_back(t-sub, t+sub);
    }

    sort(ALL(LR));
    int idx = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    int r;
    REP(i,N){
        while(idx < N and LR[idx].first <=  i) q.push(LR[idx++].second);
        if(q.empty()) return false;
        r = q.top(); q.pop();
        if(r<i) return false;
    }
    return true;

}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    int64 t,a,b;

    REP(i,N){
        cin >> t >> a >> b;
        TAB.emplace_back(--t,a,b);
    }

    int64 ok = -1e9, ng = 1e9+1;
    while(ng-ok>1){
        auto mid = (ng+ok)/2;
        if(is_ok(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}