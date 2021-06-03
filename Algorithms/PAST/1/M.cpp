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
typedef long double ld;
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
    os << "(";
    os << P.first;
    os << " ";
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
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};

bool is_ok(ld x,vector<pair<int,int>>& AB,pair<int,int> C=mp(-1,-1)){

    sort(ALL(AB),[&](pair<int,int> a,pair<int,int> b){
        return a.first - x * a.second > b.first - x*b.second;
    });
    int k=4;
    ll res1 = 0,res2 = 0;
    if (C==mp(-1,-1)) k++;
    else{
        res1 += C.first;
        res2 += C.second;
    }
    REP(i,k){
        res1 += AB[i].first;
        res2 += AB[i].second;
    }   
    return res1>=res2*x;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> AB;
    int a,b;
    REP(i,N){
        cin >> a >> b;
        AB.emplace_back(b,a);
    }
    vector<pair<int,int>> C;
    REP(i,M){
        cin >> a >> b;
        C.emplace_back(b,a);
    }

    ld eps = 0.0000005;
    ld mid;
    ld ans=0;
    REP(i,M){
        ld ok=0,ng=100001;
        while (abs(ok-ng)>eps){
            mid = (ok+ng)/2;
            if(is_ok(mid,AB,C[i])){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        chmax(ans,ok);
    }

    ld ok=0,ng=100001;
    while (abs(ok-ng)>eps){
        mid = (ok+ng)/2;
        if(is_ok(mid,AB)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    chmax(ans,ok);



    cout <<fixed<<setprecision(10)<< ans << endl;
}