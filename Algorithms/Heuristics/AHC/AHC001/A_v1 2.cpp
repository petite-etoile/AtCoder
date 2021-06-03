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

const int HEIGHT = 10000;
const int WIDTH  = 10000;

unsigned long xor128() {
    static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
    unsigned long t=(x^(x<<11));
    x=y; y=z; z=w;
    return ( w=(w^(w>>19))^(t^(t>>8)) );
}

//他の広告と(X+0.5, Y+0.5)を含んでいるか調べる関数
bool check(int X, int Y, vector<pair<int,int>> const& LT, vector<pair<int,int>> const& WH){
    int N = LT.size();
    REP(i,N){
        int x,y; tie(x,y) = LT[i];
        int w,h; tie(w,h) = WH[i];
        if(w==0) continue;

        if(x<=X and X<x+w and y<=Y and Y<y+h) {
            return false;
        }
    }
    
    return true;
}

//長方形を線分上に落とし込んだときに交差しているか
bool is_cross(pair<int,int> LR1, pair<int,int> LR2){
    /*
        mid1 = (R1+L1)/2, mid2 = (R2+L2)/2
        len1_half = (R1-L1)/2, len2_half = (R2-L2)/2;

        len1_half + len2_half > abs(mid2 - mid1) なら重なり

        ⇒ (R1+R2)-(L1+L2) > |(R2+L2) - (R1+L1)| なら重なる
    */
    int L1,L2,R1,R2;
    tie(L1,R1)=LR1; tie(L2,R2)=LR2;
    return (R1+R2)-(L1+L2) > abs((R2+L2)-(R1+L1));
}

//２つの長方形が重なっているならtrue;
bool is_overlap(tuple<int,int,int,int> LRTB1, tuple<int,int,int,int> LRTB2){
    int L1,L2,R1,R2,T1,T2,B1,B2;
    tie(L1,R1,T1,B1) = LRTB1;
    tie(L2,R2,T2,B2) = LRTB2;

    return (is_cross(make_pair(L1,R1),make_pair(L2,R2)) and is_cross(make_pair(T1,B1),make_pair(T2,B2)));
}

//指定した長方形が他の広告と重なっているかどうか 重なっていないならtrue;
bool check_board(int idx, tuple<int,int,int,int> LRTB, vector<pair<int,int>> const& LT, vector<pair<int,int>> const& WH){
    int L,R,T,B,W,H; 
    int N = LT.size();
    REP(i,N){
        if(i==idx) continue;
        tie(L,T) = LT[i];
        tie(W,H) = WH[i];
        if(W==0) continue;
        R = L+W; B = T+H;

        tuple<int,int,int,int> ad = make_tuple(L,R,T,B);
        if(is_overlap(LRTB, ad)){
            // cerr << i << "と" << idx << "が重なっています" << endl;
            // cerr << mp(L,T) << " " << mp(R,B) << endl;
            // cerr << mp(get<0>(LRTB), get<2>(LRTB)) << " " << mp(get<1>(LRTB), get<3>(LRTB)) << endl;
            return false;
        }
    }

    return true;

}

//初期解step1
void set_step1(vector<tuple<int,int,int,int>>& XYRi, vector<pair<int,int>>& LT, vector<pair<int,int>>& WH, vector<bool>& scored){
    int N = XYRi.size();
    int last_x = 0;
    REP(i,N){
        int x,y,r,_; tie(x,y,r,_)=XYRi[i];
        LT[i] = make_pair(x,y);
        
        if(last_x<=x){
            int width  = (r+HEIGHT-1)/HEIGHT; //とりあえずceil(r/10,000)列つかった広告を貼る. 
            chmax(width, x+1-last_x); //ただし左がまるまる1列空いてしまう場合はそうならないように横幅を広げる
            if(width+last_x >= WIDTH){
                width = WIDTH-last_x;
            }
            int height = r/width;
            chmin(height, HEIGHT);

            int left = last_x;
            int top = max(0, y + 1 - height);

            
            LT[i] = make_pair(left,top);
            WH[i] = make_pair(width,height);
            
            last_x = left + width;
            
            scored[i] = true;
        }else continue; //同じ列に複数個　今は貼らないことにする
    }
}

void set_step2(vector<tuple<int,int,int,int>>& XYRi, vector<pair<int,int>>& LT, vector<pair<int,int>>& WH, vector<bool>& scored, vector<tuple<int,int,int,int>>& ans){
    int N = XYRi.size();
    REP(i,N){
        int idx = get<3>(XYRi[i]);

        if(WH[i] == make_pair(0,0)){ //置く場所なかった広告は適当にあれする(とりあえず)
            int X,Y,_; tie(X,Y,_,_) = XYRi[i]; //とりあえず, 広告の場所
            if(check(X, Y, LT, WH)){
                LT[i] = make_pair(X, Y);
                WH[i] = make_pair(1, 1);
                debug("\n") ///////////////////////////////////////////////
                scored[i] = true;
            }else{
                while(true){
                    X = xor128() % WIDTH; Y = xor128() % HEIGHT;
                    if(check(X, Y, LT, WH)){
                        LT[i] = make_pair(X, Y);
                        WH[i] = make_pair(1, 1);
                        break;
                    }
                }
            }
        }

        int l,r,t,b; tie(l,t) = LT[i];
        r = l + WH[i].first;
        b = t + WH[i].second;

        check_board(i, make_tuple(l,r,t,b), LT, WH); //最後には消す
        ans[idx] = make_tuple(l,t,r,b);
        // cout << l << " " << t << " " << r << " " << b << bn;
    }
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N; cin >> N;

    vector<tuple<int,int,int, int>> XYRi;

    REP(i,N) {
        int x,y,r;
        cin >> x >> y >> r;
        XYRi.emplace_back(x,y,r,i);
    }

    sort(ALL(XYRi));

    vector<pair<int,int>> LT(N); //広告のleft,topを表す.
    vector<pair<int,int>> WH(N); //WH[i]:(0,0) ならその広告はおいてなかったことにする。
    vector<bool> scored(N); //指定地を含んでいるかどうか


    set_step1(XYRi, LT, WH, scored); //step1の配置

    vector<tuple<int,int,int,int>> ans(N);

    set_step2(XYRi, LT, WH, scored, ans);

    


    REP(i,N){
        int l,t,r,b; tie(l,t,r,b) = ans[i];
        // cerr << i << " : ";
        cout << l << " " << t << " " << r << " " << b << bn;
    }
    
    // cerr << bn;

    // sort(ALL(ans));
    // REP(i,N){
    //     int l,t,r,b; tie(l,t,r,b) = ans[i];
    //     assert((0<=l and l<r and r<=WIDTH));
    //     assert((0<=t and t<b and b<=HEIGHT));
    //     cout << l << " " << t << " " << r << " " << b << bn;
    // }

    return 0;
}