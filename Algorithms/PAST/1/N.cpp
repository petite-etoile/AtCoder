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



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int64 N,W,C;
    cin >> N >> W >> C;
    vector<int64> places;
    vector<tuple<int64,int64,int64>> LRP;
    REP(i,N){
        int64 l,r,p; cin >> l >> r >> p;
        LRP.emplace_back(l,r,p);
        places.emplace_back(l); places.emplace_back(l+1); places.emplace_back(r); places.emplace_back(r+1);
    }
    places.emplace_back(0);
    places.emplace_back(W);
    sort(ALL(places));
    places.erase(unique(ALL(places)), places.end());


    map<int64,int> place_enc;
    REP(i,places.size()){ place_enc[places[i]] = i; }

    vector<int64> plus(places.size()),minus(places.size());
    int64 l,r,p;
    for(auto e:LRP){
        tie(l,r,p) = e;
        plus[place_enc[l+1]]+=p;
        minus[place_enc[r]]+=p;
    }

    int64 ans=INF,now = 0;
    int l_idx=0;
    for(int r_idx=0;r_idx<places.size();r_idx++){
        int64 r = places[r_idx];
        now += plus[r_idx];
        while(r-places[l_idx+1]>=C){
            now -= minus[++l_idx];
        } 
        if(r-places[l_idx]>=C and r<=W){
            chmin(ans,now);
        }
    }
    cout << ans << endl;
}