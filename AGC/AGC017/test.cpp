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
typedef vector<int> vi;
const int MOD = (int)1e9 + 7;
const int64 INF = 1LL << 62;
const int inf = 1<<30;
const char bn = '\n';
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = s; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
#define mp make_pair
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

// Description: 区間をsetで管理するデータ構造(なお実装はmap)．各クエリO(log区間数)．

// #### attention! : [l, r] ( include r, not [l, r) )
class SegmentMap : public std::map<long long, long long> {
private:
    bool flagToMergeAdjacentSegment;
public:
    // if merge [l, c] and [c+1, r], set flagToMergeAdjacentSegment to true
    SegmentMap(bool flagToMergeAdjacentSegment) :
        flagToMergeAdjacentSegment(flagToMergeAdjacentSegment) {}
    // __exist -> iterator pair(l, r) (contain p)
    // noexist -> map.end()
    auto get(long long p) const {
        auto it = upper_bound(p);
        if (it == begin() || (--it)->second < p) return end();
        return it;
    }
    // insert segment [l, r]
    void insert(long long l, long long r) {
        auto itl = upper_bound(l), itr = upper_bound(r + flagToMergeAdjacentSegment);
        if (itl != begin()) {
            if ((--itl)->second < l - flagToMergeAdjacentSegment) ++itl;
        }
        if (itl != itr) {
            l = std::min(l, itl->first);
            r = std::max(r, std::prev(itr)->second);
            erase(itl, itr);
        }
        (*this)[l] = r;
    }
    // remove segment [l, r]
    void remove(long long l, long long r) {
        auto itl = upper_bound(l), itr = upper_bound(r);
        if (itl != begin()) {
            if ((--itl)->second < l) ++itl;
        }
        if (itl == itr) return;
        int tl = std::min(l, itl->first), tr = std::max(r, std::prev(itr)->second);
        erase(itl, itr);
        if (tl < l) (*this)[tl] = l - 1;
        if (r < tr) (*this)[r + 1] = tr;
    }
    // Is p and q in same segment?
    bool same(long long p, long long q) const {
        const auto&& it = get(p);
        return it != end() && it->first <= q && q <= it->second;
    }
};

// つかいかたhttps://satanic0258.github.io/snippets/data-structure/SegmentMap.html　

// // コンストラクタ．隣接区間をマージする
// SegmentMap map(true);

// // iを含む区間[l, r]のstd::map<int,int>::const_iteratorを返す, iを含む区間が無ければmap.end()を返す
// auto it = map.get(i);

// // 区間[l, r]を挿入する
// map.insert(l, r);

// // 全区間で[l, r]に重なる部分を全て消す
// map.remove(l, r);

// // iとjが同じ区間に属しているかのbool値を返す
// bool f = map.same(i, j);


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<pair<int,int>> A = {
        mp(-1,1), mp(3,3),mp(-2,4)
    };
    SegmentMap SM(true);
    for(auto e:A){
        SM.insert(e.first, e.second);
        debug(SM)
    }
}