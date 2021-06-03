#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD = (int)1e9 + 7;
const int INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = s; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
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
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
vector<int> prime_factorization(int n){
    int copy = n; //for文がぶっ壊れないようにcopy
    vector<int> prime;
    for(int i=2;i*i<=copy;i++){
        while(n%i==0){
            n/=i;
            prime.push_back(i);
        }
    }
    if(n!=1) prime++; //√n以上の素因数があった(2つ以上あることは絶対にない)
    return primes;
}
int solve(int n){
    int copy = n; //for文がぶっ壊れないようにcopy
    int prime=0;
    for(int i=2;i*i<=copy;i++){
        bool pri = false;
        while(n%i==0){
            n/=i;
            pri=true;
        }
        if(pri){
            prime++; 
        }
    }
    if(n!=1) prime++; //√n以上の素因数があった(2つ以上あることは絶対にない)
    return prime+1; //素因数の数 + 1
}
//fixed<<setprecision(10)<<ans<<endl;
signed main(){

    int A,B,G;
    cin >> A>>B;
    G=gcd(A,B);
    
    int ans=solve(G);
    cout << ans << endl;
}