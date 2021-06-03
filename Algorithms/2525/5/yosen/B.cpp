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
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
#pragma endregion
//fixed<<setprecision(10)<<ans<<endl;

string bin(int64 n){
    string s = "";
    while(n>0){
        string b = to_string(n%2);
        s = b+s;
        n>>=1;
    }
    return s;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int64 N,K;
    cin >> N >> K;
    vector<int64> A(N);
    REP(i,N) cin >> A[i];

    vector<int64> cumsum(N+1,0);
    REP(i,N){
        cumsum[i+1] = cumsum[i];
        cumsum[i+1] += A[i];
    }

    const int bit_length = 41; //log2(10^9 * 1000) < 40
    vector<vector<bool>> bits;
    REP(l,N){
        for(int r=l+1;r<=N;r++){
            int64 S = cumsum[r] - cumsum[l];
            vector<bool> tmp(bit_length, false);
            int i = 0;
            while(S){
                tmp[i] = S&1;
                S>>=1;
                i++;
            }
            bits.emplace_back(tmp);
        }
    }
    vector<int> bits_cnt(bit_length, 0);
    for(auto bit_:bits){
        REP(i,bit_length){
            bits_cnt[i] += bit_[i];
        }
    }

    int64 ans=0;
    vector<bool> removed(bits.size() , false);
    for(int i=bit_length-1; i>=0; i--){ //上から採用する
        if(bits_cnt[i] >= K){
            ans += pow(2,i);
            REP(b,bits.size()){
                if(not bits[b][i] & not removed[b]){ //使えないやつの排除
                    removed[b] = true;
                    REP(j,bit_length){
                        bits_cnt[j] -= bits[b][j];
                    }
                }
            }
        }
    }

    cout << ans << endl;
}