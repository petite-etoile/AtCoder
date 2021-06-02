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
const char bn = '\n';
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = s; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
#define mp make_pair
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
template <typename T,typename S,typename U>
ostream& operator<<(ostream& os, tuple<T,S,U> const& P){
    os << "(";
    os << get<0>(P);
    os << ", ";
    os << get<1>(P);
    os << ", ";
    os << get<2>(P);
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
    int64 N, L; cin >> N >> L;
    vector<pair<int64,char>> XS;
    REP(i,N){
        int64 x; char c; cin >> x >> c;
        XS.emplace_back(x,c);
    }

    sort(ALL(XS));
    if(XS.back().second == 'R') XS.emplace_back(L+1,'L'),N++;
    if(XS[0].second == 'L') XS.emplace_back(0,'R'),N++;
    sort(ALL(XS));

    vector<int> idx(N,-1);
    int now = 0; char before = 'R'; 
    REP(i,N){
        int64 x; char s; tie(x,s) = XS[i];
        if(before == 'L' and before!=s) now++;
        idx[i] = now;
        before = s;
    }
    vector<int64> scoreL1(now+1,0), scoreR1(now+1,0);
    vector<int64> scoreL2(now+1,0), scoreR2(now+1,0);
    
    //Lのスコアを求める
    int64 last_dif, cnt, last_same;
    REP(i,N){
        int64 x; char s; tie(x,s) = XS[i];
        if(s=='R'){
            last_dif = x;
            cnt = 0;
            last_same = -1;
        }else{
            if(last_same < 0) last_same = x;
            scoreL2[idx[i]] += (x - last_same) - cnt;
            scoreL1[idx[i]] += (x - last_dif) - ++cnt;
        }
    }

    //Rのスコアを求める
    for(int i=N-1; i>=0; i--){
        int64 x; char s; tie(x,s) = XS[i];
        if(s=='L'){
            last_dif = x;
            cnt = 0;
            last_same = -1;
        }else{
            if(last_same < 0) last_same = x;
            scoreR2[idx[i]] += abs(x-last_same) - cnt;
            scoreR1[idx[i]] += abs(x-last_dif) - ++cnt;
        }
    }

    int64 ans=0;
    REP(i,now+1){
        ans += max(scoreL1[i] + scoreR2[i], scoreR1[i] + scoreL2[i]);
    }
    cout << ans << endl;
}