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
        os << "\n";
    }
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

int find_max_idx(int r, vector<int64> const& A){
    int max_idx = 0;
    REP(i,r){
        if(A[i] > A[max_idx]){
            max_idx = i;
        }
    }
    return max_idx;
}

int64 rec(int64 L, map<int64,int>& D, map<int64,int64>& next_){
    auto ne = next_[L];

    if(D[ne] == 0) return 0;
    int64 res = rec(ne, D, next_);
    int64 tmp = D[ne];
    D[L] += tmp;
    D[ne] = 0;
    return res + tmp * (ne - L);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int64> A(N+1);
    REP(i,N) cin >> A[i+1];//番兵として0を入れる
    N++;
    map<int64,int> D;
    for(auto a:A){
        D[a]++;
    }

    auto B=A;
    sort(ALL(B));
    B.erase(unique(ALL(B)), B.end());
    map<int64,int64> next_;
    REP(i,B.size()-1){
        next_[B[i]] = B[i+1];
    }
    next_[B.back()] = -1;

    vector<int64> ans(N);
    vector<int> max_idxes = {0};
    REP(i,N){
        if(A[i] > A[max_idxes.back()]){
            max_idxes.emplace_back(i);
        }
    }
    reverse(ALL(max_idxes));
    REP(i,max_idxes.size()-1){
        int max_idx = max_idxes[i];
        int L_idx = max_idxes[i+1];
        int64 L = A[L_idx];
        ans[max_idx] = rec(L, D, next_);
        max_idx = L_idx;
    }   

    for(int i=1; i<N; i++){
        cout << ans[i] << bn;
    }
}