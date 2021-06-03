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

#pragma region geometry
//https://tanakh.hatenablog.com/entries/2005/03/08
typedef complex<double> point;
const double eps = 1e-6;
//内積
double dot(point u, point v){
    return real(u*conj(v));
}
//外積
double cross(point u, point v){
    return imag(conj(u)*v);
}
//三角形の符号付き面積
double area(point a,point b,point c){
    return cross(b-a, c-a) / 2.0;
}

//比較
class Comp{
public:
    bool operator() (complex<double> const& a, complex<double> const& b){
        if(real(a)==real(b)) return imag(a)<imag(b);
        return real(a)<real(b);
    }
};
bool operator< (complex<double> const& a, complex<double> const& b){
    if(real(a)==real(b)) return imag(a)<imag(b);
    return real(a)<real(b);
}
//偏角ソート
void arg_sort(vector<point>& P){
    point l = *min_element(P.begin(), P.end(), Comp());
    sort(P.begin(), P.end(), [&](point& a, point& b)->bool{
        auto tmp = area(l,a,b);
        if(tmp == 0){
            if(real(a)==real(b)){
                return imag(a)<imag(b);
            }return real(a)<real(b);
        }
        return area(l,a,b) > 0;
    });
}

void arg_sort(vector<point>& P, point center){
    sort(P.begin(), P.end(), [&](point& a, point& b)->bool{
        return atan2(real(a-center), imag(a-center)) > atan2(real(b-center), imag(b-center));
    });
}
#pragma endregion

bool f89(point A, point B, point C){
    return area(A,B,C) > 0 and dot(B-A, C-A) > 0;
}

bool f90(point A, point B, point C){
    return area(A,B,C) > 0 and dot(B-A, C-A) >= 0;
}

void solve(vector<point> P, int center, int64& acute_angle_cnt, int64& right_angle_cnt){
    vector<point> points;
    int N = P.size();
    REP(i,N) if(center!=i) points.emplace_back(P[i]);

    arg_sort(points,P[center]); //偏角ソート(x最小を基準とかでなく、適当なところを基準点にしての外積でソートは死ぬのでatan2を使って偏角ソートする)
    N--;
    REP(i,N){ points.emplace_back(points[i]); }

    int r_89 = 0, r_90 = 0; //r_89:l以降でなす角90度未満にならないもっとも小さい添字, r_90:l以降でなす角90度以下にならないもっとも小さい添字
    //尺取法
    REP(l,N){
        chmax(r_89, l+1), chmax(r_90, l+1);
        while(r_89 < points.size() and f89(P[center], points[l], points[r_89])){
            r_89++;
        }   

        while(r_90 < points.size() and f90(P[center], points[l], points[r_90])){
            r_90++;
        }

        acute_angle_cnt+=r_89-(l+1);
        right_angle_cnt+=r_90 - r_89;
    }   

}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int64 N; cin >> N;
    vector<point> points;
    REP(i,N){
        int x,y; cin >> x >> y;
        points.emplace_back(x,y);
    }

    int64 acute_angle_cnt = 0, right_angle_cnt = 0;
    REP(i,N){
        solve(points, i, acute_angle_cnt, right_angle_cnt); //角iが鈍角/直角の場合の数を求める
    }

    int64 tri_cnt =  (N * (N-1) * (N-2))/6;
    int64 all_angle = 3*tri_cnt; //角の数
    int64 obtuse = all_angle - acute_angle_cnt - right_angle_cnt; //鈍角の数 = 鈍角三角形の数
    int64 acute = tri_cnt - obtuse - right_angle_cnt; //鋭角三角形
    cout << acute << " " << right_angle_cnt << " " << obtuse << bn;
}