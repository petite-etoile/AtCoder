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
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(3*N);
    REP(i,3*N) cin >> A[i];
    
    ll left=0, right=0;
    priority_queue<int,vector<int>,greater<int>> L; //昇順
    priority_queue<int> R; //降順
    vector<ll> left_max(3*N), right_min(3*N);
    REP(i,N){
        L.push(A[i]);
        left += A[i];
        
        R.push(A[i+2*N]);
        right += A[i+2*N];
    }
    left_max[N-1] = left;
    right_min[2*N] = right;

    REP(k,N){
        left -= L.top(); L.pop();
        right -= R.top(); R.pop();
        
        int index1 = N + k;
        int index2 = 2*N - k -1;
        
        left += A[index1]; L.push(A[index1]);
        right += A[index2]; R.push(A[index2]);
        
        left_max[index1] = max(left, left_max[index1-1]);
        right_min[index2] = min(right, right_min[index2+1]);
    }
    ll ans = -INF;
    debug(left_max)
    debug(right_min)
    REP(i,N+1){
        int index = N + i -1;
        chmax(ans,left_max[index] - right_min[index+1]);
    }
    cout << ans << endl;
}