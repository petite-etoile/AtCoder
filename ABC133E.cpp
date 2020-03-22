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

class BigCombination{
private:
	const int MAX = 510'000;
	mint fac[510000], inv[510000];
public:
	BigCombination(){
		fac[0] = fac[1] = 1;
		for(int i=2; i<MAX; i++){
			fac[i] = fac[i-1] * i;
		}
		inv[MAX-1] = fac[MAX-1].inv();
		for(int i=MAX-1;i>0;i--){
			inv[i-1] = inv[i] * i;
		}
	}

	mint combination(int n,int r){
		if(n<r) return 0;
		if(n<0 || r<0) return 0;
		if(n==r) return 1;
		return fac[n] * inv[r] * inv[n-r];
	}

	mint permutation(int n, int r){
		if(n<r) return 0;
		if(n<0 || r<0) return 0;
		return fac[n] * inv[n-r];
	}
};

BigCombination B;

int K;
vector<vector<int>> edge;
mint dfs(int v,int pre){
	if(edge[v].size()-(pre!=-1) == 0) return 1;

	mint res = 1;
	for(auto to:edge[v]){
		if(pre == to) continue;
		res *= dfs(to, v);
	}
	res *= B.permutation(K - ((pre != -1) + 1), edge[v].size() - (pre != -1));
	return res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N >> K;
	edge.resize(N);
	int a,b;
	REP(i,N-1){
		cin >> a >> b;
		edge[--a].emplace_back(--b);
		edge[b].emplace_back(a);
	}

	auto ans = dfs(0,-1);
	cout << ans*K << endl;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// typedef long long ll;
// const int MOD = (int)1e9 + 7;
// const int INF = 1LL << 60;
// template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
// template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
// #define REP(i, n) for (int i = 0; i < (n); i++)
// #define FOR(i,s,n) for (int i = s; i < (n); i++)
// #define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
// #define debug(x) cerr << #x << ": " << x << "\n";
// struct mint {
//   ll x;
//   mint(ll x=0):x(x%MOD){}
//   mint& operator+=(const mint a) {
//     if ((x += a.x) >= MOD) x -= MOD;
//     return *this;
//   }
//   mint& operator-=(const mint a) {
//     if ((x += MOD-a.x) >= MOD) x -= MOD;
//     return *this;
//   }
//   mint& operator*=(const mint a) {
//     (x *= a.x) %= MOD;
//     return *this;
//   }
//   mint operator+(const mint a) const {
//     mint res(*this);
//     return res+=a;
//   }
//   mint operator-(const mint a) const {
//     mint res(*this);
//     return res-=a;
//   }
//   mint operator*(const mint a) const {
//     mint res(*this);
//     return res*=a;
//   }
//   mint pow(ll t) const {
//     if (!t) return 1;
//     mint a = pow(t>>1);
//     a *= a;
//     if (t&1) a *= *this;
//     return a;
//   }
 
//   // for prime MOD
//   mint inv() const {
//     return pow(MOD-2);
//   }
//   mint& operator/=(const mint a) {
//     return (*this) *= a.inv();
//   }
//   mint operator/(const mint a) const {
//     mint res(*this);
//     return res/=a;
//   }
// };
// template <typename T>
// ostream& operator<<(ostream& os, vector<T> &V){
//     int N = V.size();
//     REP(i,N){
//         os << V[i];
//         if (i!=N-1) os << " ";
//     }
//     os << "\n";
//     return os;
// }
// template <typename T>
// ostream& operator<<(ostream& os, pair<T,T> &P){
//     os << P.first;
//     os << " ";
//     os << P.second;
//     os << "\n";
//     return os;
// }
// mint dfs(int now,int from);
// //fixed<<setprecision(10)<<ans<<endl;
// int N,K;
// vector<vector<int>> edge;
// signed main(){
//     cin.tie(0);
//     ios::sync_with_stdio(false);
//     cin >> N >> K ;
//     edge.resize(N);
//     REP(i,N-1){
//         int a,b;
//         cin >> a >> b;
//         a--;b--;
//         edge[a].push_back(b);
//         edge[b].push_back(a);
//     }
//     mint ans = dfs(0,-1)*K;

//     cout << ans.x << endl;
// }

// mint dfs(int now,int from){
//     if (edge[now].size() >=K) return 0;
//     int can_color_num; //nowの子に使える色の種類
//     if(from==-1){//親がいないならnowに使った色以外使える
//         can_color_num = K-1;
//     }else{//nowとnowの親以外の色を使える
//         can_color_num = K-2;
//     }

//     mint res = 1;
//     for(auto to:edge[now]){
//         if(to==from) continue;
//         res*=can_color_num--;
//         res*=dfs(to,now);
//     }
//     return res;
// }