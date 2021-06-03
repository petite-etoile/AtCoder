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
ostream& operator<<(ostream& os, vector<T> &V){
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

class BinaryIndexedTree{
public:
    size_t size;
    std::vector<int64> node;
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

    int64 get(int index){
        return this->node[index];
    }
};
template <typename T>
int64 Inversion_number(vector<T>& A){
    size_t N = A.size();
    
    vector<int> B = A;
    sort(ALL(B)); 
    B.erase(unique(ALL(B)), B.end());

    BinaryIndexedTree BIT(N);
    int64 ans=0; /////　オーバーフローには気をつけましょう！！！！！！！！！！！！！

    REP(i,N){
        int idx = lower_bound(ALL(B),A[i]) - B.begin();
        ans += i - BIT.sum(idx+1);
        BIT.add(idx+1,1);
    }
    return ans;
}


vector<int64> A;
//x以上の要素が全組み合わせの半分以上含まれるかどうか
bool is_ok(int64 x){
    int N = A.size();
    vector<int> B(N);
    REP(i,N){
        if(A[i])
    }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    A.resize()
    REP(i,N) cin >> A[i];

    vector<int64> cumsum = A;
    REP(i,N){
        cumsum[i]+=A[i];
        if(i) cumsum[i]+=cumsum[i-1];
    }

    int64 ok = 0;
    int64 ng = 1e9 + 1;
    while(ng-ok>1){
        int64 mid = (ok+ng)/2;
        if(is_ok(mid)) ok = mid;
        else ng = mid;
    }

    int ans=0;



    cout << ans << endl;
}