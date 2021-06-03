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


//拡張Euclidの互除法
//ap + bq = gcd(a,b) となる(p,q)を求め、gcd(a,b)を返す
long long exGCD(long long a, long long b, long long &p, long long &q){
    if(b==0){
        p=1; q= 0;
        return a;
    }
    long long d = exGCD(b,a%b,q,p);
    q -= a/b * p;
    return d;
}

//中国の剰余定理
//解がx≡r(mod. M)となるような r,Mをpairで返す
pair<long long,long long> ChineseRem(const vector<long long>& b,const vector<long long>& m){
    if(b.size()!=m.size()){
        cerr << "bとmのサイズが違います" << bn;
        return make_pair(-1,-1);
    }
    long long r = 0, M = 1;
    long long p,q;
    REP(i,b.size()){
        long long d = exGCD(M,m[i],p,q);
        if((b[i]-r)%d != 0) return make_pair(-1,-1); //解無し
        long long tmp = (b[i] - r)/d * p % (m[i]/d);
        r += M * tmp;
        M *= m[i] / d;
    }
    r%=M;
    while(r<0) r+=M;
    return make_pair(r,M);
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    
    vector<int> ans(N-2,2);
    ans.emplace_back(3);
    vector<int64> b = {0, 1};
    vector<int64> m = {2*(N-2)+3, 2};
    if((N-2) % 3 == 0){
        b.emplace_back(0);
    }else b.emplace_back(3 - (2*(N-2)) % 3);
    m.emplace_back(3);
    auto res = ChineseRem(b,m);    
    ans.emplace_back(res.first);
    cout << ans;
}