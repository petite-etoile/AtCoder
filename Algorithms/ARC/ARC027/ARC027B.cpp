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
    void unite(int x,int y){
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
        }
    }
    int size(int x){
        return -node[x];
    }
    bool same(int x,int y){
        return get_root(x) == get_root(y);
    }
};

bool is_number(char a){
    return '0' <= a and a <= '9';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    string S,T;
    cin >> S >> T;
    
    vector<int> dict_(26,-1);
    vector<bool> exist(26,false);
    UnionFind UF(26);
    REP(i,N){
        if(not is_number(S[i])) exist[S[i] - 'A'] = true;
        if(not is_number(T[i])) exist[T[i] - 'A'] = true;
        if(S[i]!=T[i]){
            if(is_number(S[i])){
                dict_[T[i] - 'A'] = S[i]-'0';
            }else if(is_number(T[i])){
                dict_[S[i] - 'A'] = T[i]-'0';
            }else{
                UF.unite(S[i]-'A', T[i]-'A');
            }
        }
    }

    REP(i,26){
        if(dict_[i]!=-1){
            if(dict_[UF.get_root(i)] != -1 and dict_[UF.get_root(i)] != dict_[i]){
                cout << 0 << bn;
            }else{
                dict_[UF.get_root(i)] = dict_[i];
            }
        }
    }


    int not_zero = -1;
    if(not is_number(S[0])){
        not_zero = UF.get_root(S[0]-'A');
    }
    if(not is_number(T[0])){
        not_zero = UF.get_root(T[0]-'A');
    }
    int64 ans = 1;
    REP(i,26){
        if(UF.get_root(i) == i and exist[i] and dict_[i]==-1){
            ans *= 10 - (not_zero == i);
        }
    }

    cout << ans << endl;
}