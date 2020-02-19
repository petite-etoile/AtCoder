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
ostream& operator<<(ostream& os, vector<T> &V){
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


random_device seed_gen; 
mt19937_64 engine(seed_gen());
const uint64_t random_base = engine()%100000+1000;
template <typename T> 
struct RollingHash{
    const uint64_t mod = (1ull << 61) - 1;
    const uint64_t base = random_base;
    const uint64_t MASK31 = (1ull << 31) - 1;
    const uint64_t MASK30 = (1ull << 30) - 1;
    vector<uint64_t> pows, hash;
    RollingHash(){}

    RollingHash(const T& S)
        : pows(S.size()+1,1), hash(S.size()+1,0) {
        size_t N = S.size();
        for(int i=0; i<N; i++){
            hash[i+1] = CalcMod( Mul(hash[i], base) + S[i] );
            pows[i+1] = CalcMod( Mul(pows[i], base));
        }
    }

    //https://qiita.com/keymoon/items/11fac5627672a6d6a9f6 ～メルセンヌ素数mod～
    uint64_t Mul(uint64_t a, uint64_t b){
        uint64_t au = a>>31 , ad = a & MASK31; //上位30bitと下位31bit
        uint64_t bu = b>>31 , bd = b & MASK31; //上位30bitと下位31bit

        uint64_t mid = ad*bu + au*bd, midu = mid>>30, midd = mid&MASK30;
        return au*bu*2 + midu + (midd<<31) + ad*bd;
    }

    uint64_t CalcMod(uint64_t val){
        val = (val&mod) + (val>>61);
        if (val >= mod) val-=mod;
        return val;
    }

    //S[l:r]のハッシュを取得する
    uint64_t get_hash(int l, int r){
        if (r<l){
            cerr << "r<l:" << make_pair(l,r) << endl;
        }
        unsigned long long a = hash[r], b =CalcMod( Mul(hash[l] , pows[r-l]));
        while (a<b) a+= mod;
        uint64_t res = CalcMod(a-b);
        return res;
    }
};

int N;
string S;

bool is_ok(int length, RollingHash<string>& RH){
    map<uint64_t,int> M;
    debug(length)
    REP(l,N){
        int r = l+length-1;
        if(r>=N) break;
        auto hash_ =  RH.get_hash(l,r+1);
        if(M.count(hash_) && M[hash_]<l) return true;
        if(not M.count(hash_)) M[hash_]=r;
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> S;

    RollingHash<string> RH(S);
    int ok = 0;
    int ng = N+1;
    while (ng-ok>1){
        int mid = (ok+ng)/2;
        if (is_ok(mid, RH)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}




// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// typedef long long ll;
// const int MOD = (int)1e9 + 7;
// const int INF = 1LL << 60;
// #define REP(i, n) for (int i = 0; i < (n); i++)
// #define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
// #define debug(x) cerr << #x << ": " << x << "\n";

// vector<int> z_algorithm(string S){
//     int N = S.size();
//     vector<int> A(N,0);
//     A[0] = N;
//     int left=1;
//     int len = 0;
//     while(left < N){
//         while(left+len < N && S[len]==S[left+len]){
//             len++;
//         } //文字列の頭からと、leftからの文字列の共通接頭辞の長さを求める
//         A[left] = len;
//         if(len == 0){
//             left ++;
//             continue;
//         }
//         int k=1;
//         while(left + k < N && k + A[k] < len){
//             A[left+k] = A[k];
//             k++;
//         }

//         left += k;
//         len-=k;
//     }
//     return A;
// }

// signed main(){
//     cin.tie(0);
//     ios::sync_with_stdio(false);
//     int N;
//     string S;
//     cin >> N >> S;
//     vector<int> res;
//     int ans = 0;
//     REP(i,N){
//         string sub = S.substr(i);
//         res = z_algorithm(sub);
//         REP(j,res.size()){
//             int len = res[j];
//             ans = max(ans, min(len, j));
//         }
//     }
//     cout << ans << endl;

// }
// /*
// #include <bits/stdc++.h>
// #include <iostream>

// using namespace std;
// #define int long long
// typedef long long ll;
// const int MOD = (int)1e9 + 7;
// const int INF = 1LL << 60;
// #define REP(i, n) for (int i = 0; i < (n); i++)
// #define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
// #define debug(x) cerr << #x << ": " << x << "\n";
// void print(T &x) { cout << x << "\n"; }

// int dp[5005][5005];
// signed main(){
//     cin.tie(0);
//     ios::sync_with_stdio(false);
//     int N;
//     string S;
//     cin >> N >> S;
//     cout << "a" << 'a';
//     exit(0);
//     for(int i=N-1; i>=0;i--){
//         for(int j=N-1;j>i;j--){
//             if (S[i] == S[j]){
//                 dp[i][j] = dp[i+1][j+1] + 1;
//             }
//         }
//     }
//     int ans = 0;
//     REP(i,N)REP(j,N){
//         int len = min(j-i, dp[i][j]);
//         ans = max(ans,len);
//     }
//     cout << ans << endl;

//     return 0;
// }




// int N;
// string S;
// bool is_ok(int l){
//     for(int i=0;i < N-l+1; i++){
//         string sub = S.substr(i,l);
//         string sub2 = S.substr(i+l,N);
//         if (sub2.find(sub) != string::npos){
 
//             return true;
//         }
//     }
//     return false    ;
// }
// int bis (int ok,int ng){
//     while(abs(ok-ng) > 1){
//         int mid = (ok+ng)/2;
//         if (is_ok(mid)){
//             ok = mid;
//         }else{
//             ng = mid;
//         }
//     }
//     return ok;
// }
// int main()
// {
// 	cin >> N;
//     cin >> S;
//     int ans = bis(0,N);
//     cout << ans << endl;
// }

// */