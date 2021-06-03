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
//fixed<<setprecision(10)<<ans<<endl;

//素因数分解
vector<ll> prime_factorization(ll n){
    ll copy = n;
    vector<ll> res;
    for(ll i=2;i*i<=copy;i++){
        if(n%i==0){
            res.push_back(i);
        }
        while(n%i==0){
            n/=i;
        }
    }
    if(n!=1) res.push_back(n);
    return res;
}

int MAX = 55555;
vector<bool> Eratos(2*MAX+2,1);
//エラトステネスの篩
void Eratosthenes(int n){
    for(int i=2;i*i<=n;i++){
        if(Eratos[i]==0) continue;
        for(int j=2*i;j<=n;j+=i){
            Eratos[j]=0;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    Eratosthenes(MAX);
    vi ans;
    for(int i=2;i<MAX;i++){
        if(!Eratos[i]) continue;
        bool ok = i%5==4; 
        if(ok)ans.emplace_back(i);
        if(ans.size()==N)break;
    }
    cout << ans << endl;
}