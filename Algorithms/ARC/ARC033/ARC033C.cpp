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
//fixed<<setprecision(10)<<ans<<endl;
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
BinaryIndexedTree BIT(200001);
bool is_ok(int n, int x){
    return x<=BIT.sum(n);
}
int solve(int v){
    int ok = 200'000;
    int ng = 0;
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        if(is_ok(mid,v)) ok = mid;
        else ng = mid;
    }
    return ok;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;

    REP(i,Q){
        int a,b;
        cin >> a >> b;
        if(a==1){
            BIT.add(b,1);
        }else{
            int ans = solve(b);
            BIT.add(ans,-1);
            cout << ans << endl;
        }
    }
}