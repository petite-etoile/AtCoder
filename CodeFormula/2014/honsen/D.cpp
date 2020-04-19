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
    
    int N; cin >> N;
    vector<int64> H(N);
    REP(i,N) cin >> H[i];
    vector<tuple<int,int,int>> MSE;
    vector<int> times;
    int m,s,e;
    REP(i,N){
        cin >> m >> s >> e;
        MSE.emplace_back(--m,s,e);
        times.emplace_back(s);  times.emplace_back(e);
    }

    //-------------座圧して-------------
    sort(ALL(times));
    times.erase(unique(ALL(times)), times.end());
    int MAX_T = times.size();
    vector<int> t_enc(1e5+1);
    REP(i,MAX_T){
        t_enc[times[i]] = i;
    }

    //------------終了時刻でソートして------------
    sort(ALL(MSE),[](tuple<int,int,int> a, tuple<int,int,int> b)->bool{
        return get<2>(a) < get<2>(b);
    });


    //-------------種類ごとにまとめて---------------
    vector<vector<pair<int,int>>> movies(N); 
    REP(i,N){
        tie(m,s,e) = MSE[i];
        movies[m].emplace_back(t_enc[s],t_enc[e]);
    }
    //-------------連続視聴の幸福度の累積和取って-------------
    vector<int64> cumsum =  H;
    REP(i,N-1) cumsum[i+1] += cumsum[i];


    //------------------DP------------------
    vector<int64> DP(MAX_T); //DP[t] := 時刻tまででの幸福度最大
    int64 val, k;
    REP(t,MAX_T){
        
        //すべての種類に対して
        REP(i,N){ 
            //時刻tからk回連続で同種類で見るときの最短終了時刻
            vector<int> end_time;
            int now = t;
            REP(k,movies[i].size()){
                if(now <= movies[i][k].first) {
                    end_time.emplace_back(movies[i][k].second); 
                    now = movies[i][k].second;
                }
            }

            REP(k,end_time.size()){
                chmax(DP[end_time[k]], DP[t] + cumsum[k]); 
            }
        }
    }
    auto ans=*max_element(ALL(DP));

    cout << ans << endl;
}