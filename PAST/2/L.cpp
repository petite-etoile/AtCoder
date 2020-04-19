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



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N,K,D;
    cin >> N >> K >> D;
    vector<int64> A(N);
    REP(i,N) cin >> A[i];
    vector<int64> ans(K,-1);
    REP(i,K){
        int idx = N-1-(i*D);
        if(idx<0){
            cout << -1 << bn;
            return 0;
        }
        ans[K-i-1] = A[idx];
    }
    priority_queue<pair<int64,int>, vector<pair<int64,int>>, greater<pair<int64,int>>>  q;
    int i = N-1-(K*D);
    vector<bool> added(N);
    while(i>=0){
        q.push(mp(A[i],i));
        added[i]=true;
        // debug(mp(A[i],i))
        i--;
    }

    int l_lim = 0; //[l_lim, inf) の区間にないといけない
    int64 val;
    int idx;
    REP(i,K){
        // debug(ans)
        bool changed = false;
        int r = N-1-((K-1-i)*D);
        while(r>=0 and not added[r]){
            q.push(mp(A[r],r));
            added[r]=true;
            // debug(mp(A[r],r))
            r--;
        }
        while(!q.empty()){
            tie(val,idx) = q.top(); 
            // debug(mp(val,idx))
            if(idx<l_lim){
                q.pop();
                continue;
            }
            if(val <= ans[i]){
                q.pop();
                ans[i] = val;
                l_lim = idx + D;
                changed = true;
            }
            break;
        }
        if(not changed) break;
    }
    cout << ans;
}