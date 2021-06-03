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
template <typename T>
ostream& operator<<(ostream& os, priority_queue<T> M){
    while(M.size()){
        T e; e=M.top(); M.pop();
        os<<e<<" ";
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
    int N; cin >> N;
    vector<vector<int64>> A(N);
    REP(i,N){
        int k; cin >> k;
        REP(_,k){
            int64 a; cin >> a;
            A[i].emplace_back(a);
        }
        A[i].emplace_back(0);
        A[i].emplace_back(0);
    }

    priority_queue<pair<int64,int>> PQ1,PQ2;
    set<pair<int64,int>> S;
    vector<int> idx(N,2);
    vector<vector<int64>> B(N);
    REP(i,N){
        PQ1.push(mp(A[i][0],i));
        PQ2.push(mp(A[i][0],i));
        B[i].emplace_back(A[i][0]);
        
        PQ2.push(mp(A[i][1], i));
        B[i].emplace_back(A[i][1]);//2のpriority_queueに入ってるやつ
    }

    int M; cin >> M;
    vector<int64> ans;
    REP(_,M){
        int64 b; cin >> b;
        if(b==1){
            while(true){
                int64 a; int i; tie(a,i) = PQ1.top(); PQ1.pop();
                if(S.find(mp(a,i)) == S.end()){
                    S.insert(mp(a,i));
                    ans.emplace_back(a);
                    REP(j,B[i].size()){
                        if(B[i][j] == a){
                            B[i].erase(B[i].begin() + j);
                            break;
                        }
                    }
                    PQ1.push(mp(B[i][0],i)); 
                    if(idx[i] < A[i].size()){
                        PQ2.push(mp(A[i][idx[i]],i));
                        B[i].emplace_back(A[i][idx[i]]);
                        idx[i]++;
                    }
                    break;
                }
            }
        }else{
            while(true){
                int64 a; int i; tie(a,i) = PQ2.top(); PQ2.pop();
                if(S.find(mp(a,i)) == S.end()){
                    S.insert(mp(a,i));
                    ans.emplace_back(a);
                    REP(j,B[i].size()){
                        if(B[i][j] == a){
                            B[i].erase(B[i].begin() + j);
                            break;
                        }
                    }
                    PQ1.push(mp(B[i][0], i));
                    if(idx[i] < A[i].size()){
                        PQ2.push(mp(A[i][idx[i]], i));
                        B[i].emplace_back(A[i][idx[i]]);
                        idx[i]++;
                    }
                    break;
                }
            }
        }
        // debug(ans.back())
        // debug(PQ1)
        // debug(PQ2)
        // debug(B)
    }


    cout << ans << endl;
}