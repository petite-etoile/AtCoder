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
    os << P.first;
    os << " ";
    os << P.second;
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
double Cx,Cy,Dx,Dy;
double A1,B1;
double square(double a,double b,double c,double d,double e,double f){
    cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << "############################" << (a*d + c*f + e*b -(b*c + d*e + f*a))/2.0<< endl;

    return (a*d + c*f + e*b -(b*c + d*e + f*a))/2.0;
}
int judge(double x,double y,double pre_x,double pre_y){
  cout<<"A\n";
  return (square(x,y,pre_x,pre_y,Cx,Cy)*square(x,y,pre_x,pre_y,Dx,Dy)<0) && (square(x,y,Cx,Cy,Dx,Dy)*square(pre_x,pre_y,Cx,Cy,Dx,Dy)<0);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> Cx>>Cy>>Dx>>Dy;
    int N;
    cin >> N;
    double pre_x,pre_y;
    int x,y,cnt=0;

    REP(i,N){
        cin >> x >> y;
        if(i){
            cnt+=judge(x,y,pre_x,pre_y);
        }
        pre_x=x,pre_y=y;
    }
    cnt = (cnt+1)/2;
    int ans=1+cnt;




    cout << ans << endl;
}
