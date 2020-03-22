#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld  = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
const int INF=1e9+7;
const ll LINF=9223372036854775807;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld EPS = 1e-9; //微調整用（EPSより小さいと0と判定など）

//MODINT
//変数名.nでint型の数値を受け取る
struct mint {
  int n;
  mint(int n_ = 0) : n(n_) {}
};

mint operator+(mint a, mint b) { a.n += b.n; if (a.n >= MOD) a.n -= MOD; return a; }
mint operator-(mint a, mint b) { a.n -= b.n; if (a.n < 0) a.n += MOD; return a; }
mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }

int ii() { int x; scanf("%d", &x); return x; }
long long il() { long long x; scanf("%lld", &x); return x; }
string is() { string x; cin >> x; return x; }
char ic() { char x; cin >> x; return x; }
void oi(int x) { printf("%d ", x); }
void ol(long long x) { printf("%lld ", x); }
void od(double x) { printf("%.15f ", x); }
void os(const string &s) { printf("%s ", s.c_str()); }
void oc(const char &c) { printf("%c ", c); }
auto op = [&](auto p) -> void{ cout << p; };
auto ov = [&](auto vec) -> void{ cout << vec; };
#define o_map(v){cerr << #v << endl; for(const auto& xxx: v){cout << xxx.first << " " << xxx.second << "\n";}} //動作未確認
void br() { putchar('\n'); }

#define gcd __gcd //llは受け取ってくれない
int lcm(int a, int b){return a / gcd(a, b) * b;}
#define ALL(a) a.begin(),a.end() //sort(ALL(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define PB push_back
#define SZ(x) ((int)(x).size) //size()がunsignedなのでエラー避けに

//4近傍（上下左右） rep(i, 2) にすると右・下だけに進む
vector<int> dx_4 = {1, 0, -1, 0};
vector<int> dy_4 = {0, 1, 0, -1};

// coutによるpairの出力（空白区切り）
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << " " << p.second << ")";}
// 空白区切りだけ --> return s << "(" << p.first << " " << p.second << ")";
// 見やすくしたいとき --> return s << "(" << p.first << " " << p.second << ")";
// coutによるvectorの出力（空白区切り）
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << " "; //"\t"に変えるとTabで見やすく区切る
  }
  return s;
}
// coutによる多次元vectorの出力（空白区切り）
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i] << endl;
  }
  return s;
}

//最大値、最小値を更新する。aよりbのが大きい（小さい）か等しければaを更新してtrueを返す。そうでなければ何もせずfalseを返す chmax(nowmax,x);
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}

// -------- template end - //


// - global -------------- //



// ---------- global end - //


// - library ------------- //

// 決め打ち二分探索 with めぐる式二分探索

// 答えを key としたときに、問題が求める条件を満たせるかどうか
bool isOK(vector<vector<int>> &succ, vector<vector<ll>> &sum, ll key, ll n, ll k) {
  // 今回は...
  // key 回ジャンプしたとき、sumの合計がN*Kを超えないかどうか

  // 可否を評価（パターン色々。評価配列を作り直して貪欲に落とし込むことが多い？）
  // okを適当に大きめの値に設定した場合、配列外参照やコーナーケースに注意

  // key回ジャンプしてsumを合計する
  // A[0]から始めて、key個次の要素を求める
  ll sumofsum = 0;
  ll nowpos = 0;
  for(ll i = 0; (key >> i)>=1; i++){
    // key の全てのbitについてfor文を回して、
    // 各iについて、i番目のbitが立っていれば2^i回ずつジャンプしていく
    if(key & (1LL<<i)){
      // i番目のbitが立っていれば、2^i回ジャンプする
      sumofsum += sum[i][nowpos];
      nowpos = succ[i][nowpos];
    }
  }

  if (sumofsum <= n*k){
    return true;
  }
  else{
    return false;
  }

}

// 汎用的な二分探索のテンプレ
// 
ll BinarySearch(vector<vector<int>> &succ, vector<vector<ll>> &sum, ll n, ll k) {
  ll ng = 2LL * 1e17; //1e17+1でいいはずだが、不安なので大きくしておく
  ll ok = 0;
  // okは"1つも満たさない"場合があることに注意して設定。ex) = (ll)vec.size();
  // 二分探索はO(logN)なので大きめでもいいが、配列外参照やコーナーケースは注意

  // ok と ng のどちらが大きいかわからないことを考慮
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;

    if (isOK(succ, sum, mid, n, k)) ok = mid;
    else ng = mid;
  }
  return ok;
}

// --------- library end - //


// - main() -------------- //

int main(){

  // REPをllに変えてあるので、後で戻すこと

  ll n = il();
  ll k = il();
 
  // 数列を2倍に拡張
  vector<int> a(n*2); rep(i, n) cin >> a[i], a[i+n] = a[i];

  // succ[k][i]:「Aiの前で空」の状態から、2^k回空になった時に目の前にいるAjのidx(j)
  vector<vector<int>> succ(58, vector<int>(n));

  // sum[k][i]:「Aiの前で空」の状態から、2^k回空になるまでに通り過ぎた数字の数
  // sum[k][0]がN*Kを超えないような最大のsucc[k][0], sum[k][0]を探すのが目的
  vector<vector<ll>> sum(58, vector<ll>(n));

  // バケツ pos（各Aiが直前に出たときの 拡張数列上のidx）を使って 下記2つを求める
  // succ[0][i] : 各Aiと同じ数字が出てきた直後のidx（Aiからどこにジャンプするか）
  // sum[0][i] : 各Aiの直前から同じ数字の直後までジャンプした時の、飛び超えた数
  vector<int> pos(200001, -1);
  rep(i, n*2) {
    if (pos[a[i]]!=-1 && pos[a[i]]<n) {
      // 前に同じ数字が出ていたら、「前の同じ数字」からのジャンプ情報を書き込む
      // ただし、「前の同じ数字」がn以降なら、2週目なのでもう無視する
      succ[0][pos[a[i]]] = (i + 1) % n;
      sum[0][pos[a[i]]] = i + 1 - pos[a[i]];
    }
    pos[a[i]] = i;   
  }
  // ここまでで 各Aiから1回ジャンプするとどうなるか が分かった
  
  // ということは、あとはダブリングでいける
  ll TMPINF = 1e18; //sumが10^17を超えたらどうせinvalidなので、オーバーフロー対策のために適当にsumの上限を10^18としておく
  REP(i, 1, 58){
    // k : 1~57 について計算（最小でも2歩以上ジャンプするので、最大でも2*10^5*10^12/2回のジャンプ。底2でlogをとりceilすると57。）
    rep(j, n){
      // j : 0~n-1 から2^k回ジャンプしたときの情報を書き込む
      // オーバーフロー対策は？
      succ[i][j] = succ[i-1][succ[i-1][j]]; //jから2^i-1回ジャンプしたところ から更に2^i-1回ジャンプ
      sum[i][j] = min(TMPINF, sum[i-1][j] + sum[i-1][succ[i-1][j]]); //jから2^i-1回ジャンプした時に飛び越えた数 + jから2^i-1回ジャンプしたところから2^i-1回ジャンプした時に飛び越えた数
    }
  }


  // N*Kを超えない範囲で最大のsumをもたらすスタート地点からのジャンプ回数を、ジャンプ回数を決め打つ　決め打ちにぶたんで求める
  ll jumps = BinarySearch(succ, sum, n, k);

  // ちょっと冗長になるが、jumps回ジャンプした時のsumの合計を再度求める
  ll sumofsum = 0;
  ll nowpos = 0;
  for(ll i = 0; (jumps >> i)>=1; i++){
    // key の全てのbitについてfor文を回して、
    // 各iについて、i番目のbitが立っていれば2^i回ずつジャンプしていく
    if(jumps & (1LL<<i)){
      // i番目のbitが立っていれば、2^i回ジャンプする
      sumofsum += sum[i][nowpos];
      nowpos = succ[i][nowpos];
    }
  }

  // 求めたジャンプ回数分だけジャンプした後は、愚直にシミュレーション
  // ジャンプの最大距離はNなので、シミュレーションのループは最大でも2*10^5

  vector<ll> temochi(n, -1);
  ll len = 0; // temochiのサイズ（答えとなる数列の現在の長さ）を管理
  vector<int> pos_in_temochi(200001, -1);

  while(sumofsum < n * k){
    if(pos_in_temochi[a[nowpos]]==-1){
      //まだ登場していなければ、そのままtemochiに入れる
      temochi[len] = a[nowpos];
      pos_in_temochi[a[nowpos]] = len; //len==3の配列に入れたなら、入る場所は[3]
      len++;
    }
    else{
      //既に登場していれば、その登場場所から先を消さなくてはいけない
      int repend = len;
      len = pos_in_temochi[a[nowpos]]; //数列の長さが短くなる
      REP(i, pos_in_temochi[a[nowpos]], repend){
        pos_in_temochi[temochi[i]] = -1; //消す数字はバケツからも消す
        temochi[i] = -1; //数字を消す
      }
    }
    sumofsum++;
    nowpos++;
  }

  //答えの出力
  rep(i, len){
    ol(temochi[i]);
  }

// ---------- main() end - //
}
