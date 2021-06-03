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
#include <iostream>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<bitset>
#include<unordered_map>
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



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int>> edge(N);
    int a,b;
    REP(i,N-1){
        cin >> a >> b;
        edge[--a].emplace_back(--b);
        edge[b].emplace_back(a);
    }

    vector<int> color(N,-1);
    queue<int> q;
    q.push(0);
    REP(step,N){
        queue<int> tmp;
        while(not q.empty()){
            int v = q.front(); q.pop();
            if(color[v]>=0) continue;
            color[v] = step&1;
            for(auto to:edge[v]){
                if(color[to]>=0) continue;
                tmp.push(to);
            }
        }
        q = tmp;
    }

    vector<int> color_cnt(2,0);
    for(auto c:color){
        color_cnt[c]++;
    }

    // debug(color)

    vector<int> ans(N);
    vector<int> perm = {1,2,3};
    if(color_cnt[0]<=N/3){
        int three_color = 0;
        REP(i,N){
            if(color[i] == three_color){
                ans[i] = perm[2];
                perm[2] += 3;
            }else{
                if(perm[0]<=N){
                    ans[i]  = perm[0];
                    perm[0] += 3;
                }else if(perm[1]<=N){
                    ans[i] = perm[1];
                    perm[1] += 3;
                }else{
                    ans[i] = perm[2];
                    perm[2] += 3;
                }
            }
        }
    }else if(color_cnt[1]<=N/3){
        int three_color = 1;
        REP(i,N){
            if(color[i] == three_color){
                ans[i] = perm[2];
                perm[2] += 3;
            }else{
                if(perm[0]<=N){
                    ans[i]  = perm[0];
                    perm[0] += 3;
                }else if(perm[1]<=N){
                    ans[i] = perm[1];
                    perm[1] += 3;
                }else{
                    ans[i] = perm[2];
                    perm[2] += 3;
                }
            }
        }
    }else{
        REP(i,N){
            if(perm[color[i]]<=N){
                ans[i] = perm[color[i]];
                perm[color[i]] += 3;
            }else{
                ans[i] = perm[2];
                perm[2] += 3;
            }
        }
    }




    cout << ans << endl;
}