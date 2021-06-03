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

int64 pow(int a,int b,int mod){
    vector<bool> bit;
    for(b=b;b>0;b>>=1){
        bit.push_back(b&1);
    }
    vector<int64> fac(bit.size()); fac[0] = a;
    int64 res = 1;
    for(int i=1;i<bit.size();i++){
        fac[i] = (fac[i-1] * fac[i-1])%mod;
    }
    for(int i=0;i<bit.size();i++){
        if(bit[i]) res*=fac[i];
        res%=mod;
    }
    return res;
}


//mint
struct mint {
    int64 x;
    mint(int64 x=0):x((x+2*MOD)%MOD){}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(int64 t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime MOD
    mint inv() const {
        return pow(MOD-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};
ostream& operator<<(ostream& os, mint a){
    os << a.x;
    return os;
}

template <typename T>
struct Matrix{
    vector<vector<T>> matrix_data;
    Matrix(){}
    Matrix(const vector<vector<T>>& matrix_data):matrix_data(matrix_data){}

    //単位行列
    Matrix<T> Identity(size_t N){
        vector<vector<T>> res(N,vector<T>(N,0));
        for(size_t i=0; i<N; i++) res[i][i]=1;
        return Matrix<T>(res);
    }

    //累乗O(N^3 log k)
    Matrix<T> power(int64 k){
        Matrix<T> res = Matrix::Identity(matrix_data.size());
        Matrix<T> tmp = *this;

        while(k){
            if(k&1){res *= tmp;}
            tmp *= tmp;
            k >>= 1LL;
        }
        return res;
    }

    //T det(){}
    //Matrix<T> inv(){} 逆行列求めるやつあっても面白いね。正則(⇔det(A)!=0)じゃないといけないけど。
};


template <typename T>
Matrix<T> operator*(const Matrix<T>& mat_a, const Matrix<T>& mat_b){
    size_t A = mat_a.matrix_data.size();
    size_t B = mat_b.matrix_data.size();
    assert(B == mat_a.matrix_data[0].size());
    size_t C = mat_b.matrix_data[0].size();

    Matrix<T> res(vector<vector<T>>(A,vector<T>(C,0)));
    
    for(size_t i=0; i<A; i++){
        assert(mat_a.matrix_data[i].size() == B);
        for(size_t j=0; j<B; j++){
            for(size_t k=0; k<C; k++){
                res.matrix_data[i][j] += mat_a.matrix_data[i][k] * mat_b.matrix_data[k][j];
            }
        }
    }

    return res;
}

template <typename T>
Matrix<T>& operator*=(Matrix<T>& mat_a, Matrix<T>& mat_b){
    mat_a = mat_a*mat_b;
    return mat_a;
}

template <typename T>
ostream& operator<<(ostream& os, const Matrix<T>& M){
    os << M.matrix_data;
    return os;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int64 N;
    cin >> N;
    vector<vector<mint>> A = {{0,1,1},{1,0,1},{1,1,0}}, B = {{0,1,0},{1,0,0},{1,1,0}}; //A:(朝->昼, 昼->夜), B:(夜->朝)
    vector<vector<mint>> S = {{1,1,0}};
    Matrix<mint> MA(A), MB(B), MS(S); 
    
    auto M_day = MA * MA * MB; //1-day
    auto M_ans = MS * (M_day.power(N-1) * MA * MA);

    // debug(M_ans)
    mint ans = M_ans.matrix_data[0][0] + M_ans.matrix_data[0][1] + M_ans.matrix_data[0][2];
    cout << ans << endl;
}