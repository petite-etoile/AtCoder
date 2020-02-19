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

bool is_ok(int dif,string c1,string c2){
	if ((dif&1) ^ (c1==c2)) return true;
	return false;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	string c;
	int up,low;
	string c1,c2;
	cout << 0 << endl;
	cin >> c1;
	if (c1=="Vacant") return 0;
	cout << N/2 << endl;
	cin >> c2;
	if (c2=="Vacant") return 0;
	string L,H;
	if(is_ok(N/2-0,c1,c2)) up=N,low=N/2+1,L=c2,H=c1;
	else up=N/2,low=1,L=c1,H=c2;

	REP(i,20){
		int mid = (up+low)/2;
		cout << mid << endl;
		cin >> c;
		if (c=="Vacant") return 0;
		if (is_ok(mid-low+1,L,c)) low = mid+1, L=c;
		else up = mid, H=c;
	}
}