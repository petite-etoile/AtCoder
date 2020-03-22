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
    int A,B;
    cin >> A >> B;
    vector<int64> Stones(N);
    REP(i,N) cin >> Stones[i];


    if(A==B){ //Nimと同じ手で勝てる
        int64 nim_result = 0;
        for(auto a:Stones) nim_result ^= a%(A+1);

        if(nim_result!=0) cout << "Hanako" << bn;
        else cout << "Jiro" << bn;
    }else if(A>B){  //勝てない状態でも、B+1以上の山があるなら、それをB+1を取ることで敵はXORを0にできなくなる
        int64 nim_result = 0;
        for(auto a:Stones) nim_result ^= a%(B+1);

        if(nim_result!=0) cout << "Hanako" << bn;
        else{
            bool overB_exist = false;
            for(auto a:Stones){
                if(a>B) overB_exist = true;
            }
            if(overB_exist) cout << "Hanako" << bn;
            else cout << "Jiro" << bn;
        }
    }else{ //Aより多い山も、XOR!=0も渡しては勝てない
        int64 nim_result = 0;
        for(auto a:Stones) nim_result ^= a%(A+1);

        int64 overA_cnt = 0;
        for(auto a:Stones){
            if(a>A) overA_cnt++;
        }
        if(overA_cnt >= 2 or nim_result==0) cout << "Jiro" << bn;
        else{
            if(overA_cnt == 0){
                cout << "Hanako" << bn;
            }else{ //全体のXORを最多の山から引いたときに、A未満になるなら、勝ち
                bool hanako_win = false;
                for(auto a:Stones){
                    if(a>A){
                        nim_result ^= a%(A+1);
                        int64 line = a/(A+1)*(A+1);
                        //line + nim_result か、 line - ((A+1) - nim_result)にしたい
                        int64 cand1 = line + nim_result;
                        int64 cand2 = line - ((A+1) - nim_result);
                        if((cand1<=A) && (1<= a-cand1) && (a-cand1 <= A)) hanako_win = true;
                        if((cand2<=A) && (1 <= a-cand2) && (a-cand2 <= A)) hanako_win = true;
                    }
                }

                if(hanako_win) cout << "Hanako" << bn;
                else cout << "Jiro" << bn;
            }
        }
    }
}