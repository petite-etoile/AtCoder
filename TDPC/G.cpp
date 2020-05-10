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
const int64 INF = 1LL << 61;
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



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string S;
    int64 K;
    cin >> S >> K;
    int N = S.size();
    vector<vector<int64>> DP(N+1,vector<int64>(26,0));
    for(int i=N-1;i>=0;i--){
        DP[i] = DP[i+1];
        auto& tmp = DP[i][S[i]-'a'];
        tmp = 1; //その文字1文字の部分文字列
        for(auto x:DP[i+1]){
            tmp += x;
            chmin(tmp,INF); //オーバーフロー対策
        }
    }

    int64 sum = 0;
    for(auto a:DP[0]){
        sum+=a;
        chmin(sum,INF);
    }
    if(sum<K){
        cout << "Eel" << bn;
        return 0;
    }
    
    string ans = "";
    for(int i=0;i<N;i++){
        int c;
        for(c=0;c<26;c++){
            if(K>DP[i][c]){
                K-=DP[i][c];
            }else{
                K--;
                break;
            }
        }
        ans += c+'a';
        if(K==0) break;
        while(S[i]-'a'!=c) i++;
    }    
    cout << ans << bn;
}