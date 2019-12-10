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
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using P = pair<ll, ll>;
typedef vector<int> vi;
const int MOD = (int)1e9 + 7;
const ll INF = 1LL << 60;
const int inf = 1<<30;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = s; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
#define mp make_pair
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
template <typename T>
ostream& operator<<(ostream& os, pair<T,T> const&P){
    os << "(";
    os << P.first;
    os << ",";
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
//符号付き面積
double signed_triangle_area(double a,double b,double c,double d,double e,double f){
    return (a*d + c*f + e*b -(b*c + d*e + f*a))/2.0;
}
//交差判定
int judge(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4){
    return (signed_triangle_area(x1,y1,x2,y2,x3,y3)*signed_triangle_area(x1,y1,x2,y2,x4,y4)<0) && (signed_triangle_area(x3,y3,x4,y4,x1,y1)*signed_triangle_area(x3,y3,x4,y4,x2,y2)<0);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Ax,Ay,Bx,By;
    cin >> Ax>>Ay>>Bx>>By;
    int N;
    cin >> N;
    double pre_x,pre_y;
    int x,y,cnt=0;
    REP(i,N){
        cin >> x >> y;
        if(i){
            cnt+=judge(x,y,pre_x,pre_y,Ax,Ay,Bx,By);
        }
        pre_x=x,pre_y=y;
    }
    cnt = (cnt+1)/2;
    int ans=1+cnt;




    cout << ans << endl;
}