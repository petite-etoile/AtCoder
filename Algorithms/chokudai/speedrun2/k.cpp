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
template <typename T,typename S,typename U>
ostream& operator<<(ostream& os, tuple<T,S,U> const& P){
    os << "(";
    os << get<0>(P);
    os << ", ";
    os << get<1>(P);
    os << ", ";
    os << get<2>(P);
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

struct UnionFind{
    int N;
    vector<int> node;
    UnionFind(){}
    UnionFind(int N):N(N){
        node.assign(N,-1);
    }
    int get_root(int x){
        if (node[x]<0){
            return x;
        }
        node[x] = get_root(node[x]);
        return node[x];
    }
    bool unite(int x,int y){
        int root_x = get_root(x);
        int root_y = get_root(y);
        int larger,smaller;
        if(root_x != root_y){
            if(node[root_x] < node[root_y]){ //size of x is lager than one of y
                larger  = root_x;
                smaller = root_y;
            }else{
                larger  = root_y;
                smaller = root_x;
            }
            node[larger] += node[smaller];
            node[smaller] = larger;
            return true;
        }return false;
    }
    int size(int x){
        return -node[x];
    }
    bool same(int x,int y){
        return get_root(x) == get_root(y);
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<pair<int64,int64>> AB;
    vector<int64> C;
    REP(i,N){
        int64 a,b; cin >> a >> b;
        if(a>b) swap(a,b);
        AB.emplace_back(a,b);
        C.emplace_back(a); C.emplace_back(b);
    }

    sort(ALL(C));
    C.erase(unique(ALL(C)), C.end());

    map<int64,int> enc;
    REP(i,C.size()){ enc[C[i]] = i; }

    int M = C.size();
    vector<bool> can_all(M,false);
    set<pair<int,int>> exist;

    UnionFind UF(M);
    for(auto& e:AB){
        e.first = enc[e.first];
        e.second = enc[e.second];
        int a,b; tie(a,b) = e;
        if(not UF.unite(a,b)){
            can_all[a] = true;
        }
    }

    int ans=0;
    REP(i,M){
        if(can_all[i]) can_all[UF.get_root(i)] = true;
    }

    REP(i,M){
        if(UF.get_root(i) == i){
            ans += UF.size(i) - 1 + can_all[i];
        }
    }

    cout << ans << endl;
}