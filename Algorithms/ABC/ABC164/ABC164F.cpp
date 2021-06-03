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

typedef unsigned long long ull;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<bool> S(N),T(N);
    vector<ull> U(N),V(N);
    vector<vector<ull>> ans(N,vector<ull>(N,0));

    REP(u,N){
        REP(v,N){
            REP(k,64){
                if(U[u]>>k&1){
                    if(S[u]==0){//S論理積
                        ans[u][v] |= 1<<k;
                    }else{ //S論理和
                        if(T[v]==0){ //T論理積
                            if(V[v]>>k&1){
                                ans[u][v] |= 1<<k;
                            }
                        }else{
                            ans[u][v] |= 1<<k;
                        }
                    }
                }
                if(V[v]>>k&1){
                    if(T[v]==0){//T論理積
                        ans[u][v] |= 1<<k;
                    }else{//T論理和
                        if(S[u]==0){//S論理積
                            if(V[v]>>k&1){
                                ans[u][v] |= 1<<k;
                            }
                        }else{
                            ans[u][v] |= 1<<k;
                        }
                    }
                }
            }
        }
    }

    //論理和取りすぎて論理積になってないかチェック(残すやつは乱数で選ぶ)
    REP(u,N){
        if(S[u]==0){//論理積
            ull res = (((1<<63)-1)<<1)+1;
            REP(v,N){
                res &= ans[u][v];
            }
            if(res!=U[u]){
                vector<bool> dif(64,false);
                REP(k,64){
                    if(not ((res>>k&1)&(U[u]>>k&1))) continue; //正しい
                    REP(v,N){
                        
                    }

                }
                if()
            }
            

        }
        REP(k,64){
            if(U[u]>>k&1){

            }

                    if(S[u]==0){//S論理積
                        ans[u][v] |= 1<<k;
                    }else{ //S論理和
                        if(T[v]==0){ //T論理積
                            if(V[v]>>k&1){
                                ans[u][v] |= 1<<k;
                            }
                        }else{
                            ans[u][v] |= 1<<k;
                        }
                    }
                }
                if(V[v]>>k&1){
                    if(T[v]==0){//T論理積
                        ans[u][v] |= 1<<k;
                    }else{//T論理和
                        if(S[u]==0){//S論理積
                            if(V[v]>>k&1){
                                ans[u][v] |= 1<<k;
                            }
                        }else{
                            ans[u][v] |= 1<<k;
                        }
                    }
                }
            }
    }

}