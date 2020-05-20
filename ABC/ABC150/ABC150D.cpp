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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int64 N,M;
    cin >> N >> M;
    vector<int64> A(N);
    vector<int64> B(N);
    REP(i,N) cin >> A[i], B[i] = A[i]/2;

    int64 x,m;
    tie(x,m) = ChineseRem(B,A);
    if(x==-1){
        cout << 0 << bn;
    }else{
        int ans = M/m + (x<=(M%m));
        cout << ans << endl;
    }

}