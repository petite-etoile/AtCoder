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
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
//fixed<<setprecision(10)<<ans<<endl;

//
int64 binary_knapsack(vector<int64>& val,vector<int64>& weight, int64 W){
    int N = val.size();
    vector<vector<int64>> dp(N,vector<int64>(W+1,0));
    REP(w,W+1){
        if(weight[0]<=w) dp[0][w] = val[0];
    }
    REP(i,N-1){
        REP(w,W+1){
            if(w>=weight[i+1]){
                dp[i+1][w] = dp[i][w-weight[i+1]]+val[i+1];
            }
            chmax(dp[i+1][w], dp[i][w]);
        }
    }
    return dp.back().back();
}

int64 big_weight_knapsack(vector<int64>& val,vector<int64>& weight, int64 W){
    int64 N = val.size();
    int64 MAX=*max_element(ALL(val))*N;
    vector<int64> dp(MAX+1,INF);//価値vを達成するのに最小重さ

    dp[0] = 0;
    REP(i,N){
        for(int64 v=MAX;v>=0;v--){
            if (v>val[i])
                chmin(dp[v],dp[v-val[i]]+weight[i]);
            else
                chmin(dp[v],weight[i]);
        }
    }

    int64 res=0;
    REP(i,MAX){
        if(dp[i]<=W)
            res=i;
        else break;
    }
    return res;
}

vector<pair<int64,int64>> get_half_sack(vector<int64>& val, vector<int64>& weight, int64 W){
    int N = val.size();
    int max_bit = 1<<N;
    vector<pair<int64,int64>> res;
    REP(bit_set,max_bit){
        int64 v=0,w=0;
        REP(i,N){
            if(bit_set&(1<<i)){
                v+=val[i];
                w+=weight[i];
            }
        }
        if(w<=W) res.push_back(mp(v,w));
    }
    return res;
}

int64 huge_knapsack(vector<int64>& val, vector<int64>& weight, int64 W){
    int N = val.size();
    vector<int64> val1,val2,weight1,weight2;
    REP(i,N){
        if (i<N/2){
            val1.emplace_back(val[i]);
            weight1.emplace_back(weight[i]);
        }else{
            val2.emplace_back(val[i]);
            weight2.emplace_back(weight[i]);
        }
    }
    vector<pair<int64,int64>> vw1=get_half_sack(val1,weight1,W); //前半
    vector<pair<int64,int64>> vw2=get_half_sack(val2,weight2,W); //後半
    int64 v,w,v2,w2;
    int64 res=0;
    
    sort(ALL(vw2),[&](pair<int64,int64> a,pair<int64,int64> b){
        return a.second<b.second;
    });//重さが大きい順に試していく
    sort(ALL(vw1),[&](pair<int64,int64> a,pair<int64,int64> b){
        return a.second>b.second;
    });//重さが大きい順に試していく)
    auto it = vw2.begin();
    int64 current_max_v=0; int64 current_weight=0;
    for(auto vw:vw1){
        tie(v,w) = vw;
        int64 remain = W-w;
        while(it!=vw2.end()){
            bool updated=false;
            tie(v2,w2)=*it;
            if(remain>=w2){
                chmax(current_max_v,v2);
                chmax(current_weight,w2);
                it++;
                updated=true;
            }
            chmax(res,current_max_v+v);
            if(!updated) break;
        }
    }
    return res;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int64 N,W;
    cin >> N >> W;

    vector<int64> val(N);
    vector<int64> weight(N);
    REP(i,N){
        cin >> val[i] >> weight[i];
    }
    int64 ans=0;
    if(N<=30){
        ans = huge_knapsack(val,weight,W);
    }else if(*max_element(ALL(weight)) <= 1000){
        ans = binary_knapsack(val,weight,W);
    }else if(*max_element(ALL(val)) <= 1000){
        ans = big_weight_knapsack(val,weight,W);
    }else{
        while (1){}
    }

    cout << ans << endl;
}