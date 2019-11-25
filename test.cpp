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
const ll INF = 1LL << 60;
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
class BinaryIndexedTree{
public:
    size_t size;
    std::vector<ll> node;
    BinaryIndexedTree(size_t s){ 
        this->node.assign(s+1, 0); //1-index
        this->size = s;
    }

    void add(int index, int value){
        while(index <= this->size ){
            this->node[index] += value;
            index += index & -index;
        }
    }

    int sum(int index){
        int res = 0; //零元・単位元
        while(index > 0){
            res += this->node[index];
            index -= index & -index;
        }
        return res;
    }

    ll get(int index){
        return this->node[index];
    }
};
ll pow(int a,int b,int mod){
    vector<bool> bit;
    for(b=b;b>0;b>>=1){
        bit.push_back(b&1);
    }
    vector<int> fac(bit.size()); fac[0] = a;
    int res = 1;
    for(int i=1;i<bit.size();i++){
        fac[i] = fac[i-1] * fac[i-1];
    }
    for(int i=0;i<bit.size();i++){
        if(bit[i]) res*=fac[i];
        res%=mod;
    }
    return res;
}

class BigCombination{
private:
    const int MAX = 510'000;
    long long fac[510000], inv[510000];
    int mod = 1e9+7;
public:
    BigCombination(){
        fac[0] = fac[1] = 1;
        for(int i=2; i<MAX; i++){
            fac[i] = (fac[i-1] * i) % mod;
        }
        inv[MAX-1] = pow(fac[MAX-1], mod-2, mod);
        for(int i=MAX-1;i>0;i--){
            inv[i-1] = (inv[i] * i) % mod;
        }
    }

    long long combination(int n,int r){
        if(n<r) return 0;
        return (fac[n] * inv[r] * inv[n-r]) % mod;
    }
};

//fixed<<setprecision(10)<<ans<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c;
    cin >>a >>b;
    BigCombination BC;
    BC.combination();

}