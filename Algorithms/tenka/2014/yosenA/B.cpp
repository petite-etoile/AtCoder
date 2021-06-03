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

    string S; cin >> S;
    int N = S.size();
    const double COMMAND = -10, BACK1 = -1, BACK3 = -3;
    // -10:コマンド -1:1個戻ってくる -3:3個戻ってくる 正->ダメージ
    priority_queue<pair<double,int>,vector<pair<double,int>>, greater<pair<double,int>>> q;
    REP(i,N) q.push(mp(i,COMMAND));

    double t,damage;;
    int c, combo = 0, i=0;
    int kaburing = 5; //かぶりんの数
    double lock = 0; //硬直で動けなくない時間
    int64 ans=0;
    while (q.size()){
        tie(t,c) = q.top(); q.pop();
        if(c==COMMAND){
            auto s = S[i++];
            if(lock > t) continue;
            if(s == 'N'){ //通常投げ入力
                if(kaburing<1) continue;
                damage = 10+combo/10;

                q.push(mp(t+1.5, damage)); //ダメージ
                q.push(mp(t+1.5+5,BACK1)); //ダメージの5秒後に戻る
                chmax(lock, t+0.5); //硬直
                kaburing--;
            }else if(s == 'C'){ //ため投げ入力
                if(kaburing<3) continue;
                damage = 5*(10+combo/10);

                q.push(mp(t+3.5, damage)); //ダメージ
                q.push(mp(t+3.5+5,BACK3)); //ダメージの5秒後に戻る
                chmax(lock, t+2.5); //硬直
                kaburing-=3;
            }
        }else if(c==BACK1){ //1個戻ってくる
            kaburing++;
        }else if(c==BACK3){ //3個戻ってくる
            kaburing+=3;
        }else{ //ダメージ発生
            ans += c;
            combo++;
        }
    }

    cout << ans << endl;
}