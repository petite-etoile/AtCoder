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

typedef tuple<int,int,int,int> Rect;
ostream& operator<<(ostream& os, Rect const& P){
    os << "(";
    os << get<0>(P);
    os << ", ";
    os << get<1>(P);
    os << ", ";
    os << get<2>(P);
    os << ", ";
    os << get<3>(P);
    os << ")";
    return os;
}

const int HEIGHT = 10000;
const int WIDTH  = 10000;

unsigned long xor128() {
    static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
    unsigned long t=(x^(x<<11));
    x=y; y=z; z=w;
    return ( w=(w^(w>>19))^(t^(t>>8)) );
}

double get_temp(clock_t now, clock_t start_time, clock_t end_time, double start_temp, double end_temp){
    return double(start_temp * (end_time - now) + end_temp * (now - start_time)) / (end_time - start_time);
}

void set_ans(vector<Rect>const& XYRi, vector<pair<int,int>>const& LT, vector<pair<int,int>>const& WH, vector<Rect>& ans);
long double get_score(vector<Rect>& XYRi, vector<Rect>& ans);

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
bool is_overlap(Rect LRTB1, Rect LRTB2){
    int L1,L2,R1,R2,T1,T2,B1,B2;
    tie(L1,R1,T1,B1) = LRTB1;
    tie(L2,R2,T2,B2) = LRTB2;

    return (is_cross(make_pair(L1,R1),make_pair(L2,R2)) and is_cross(make_pair(T1,B1),make_pair(T2,B2)));
}

//指定した長方形が他の広告と重なっているかどうか 重なっていないならtrue;
bool check_board(int idx, Rect LRTB, vector<pair<int,int>> const& LT, vector<pair<int,int>> const& WH, vector<bool>const& scored){
    int L,R,T,B,W,H; 
    int N = LT.size();
    REP(i,N){
        if(i==idx) continue;
        tie(L,T) = LT[i];
        tie(W,H) = WH[i];
        if(W==0) continue;
        R = L+W; B = T+H;

        Rect ad = make_tuple(L,R,T,B);
        if(is_overlap(LRTB, ad)){
            // cerr << i << "と" << idx << "が重なっています" << endl;
            // cerr << mp(L,T) << " " << mp(R,B) << endl;
            // cerr << mp(get<0>(LRTB), get<2>(LRTB)) << " " << mp(get<1>(LRTB), get<3>(LRTB)) << endl;
            if(scored[i])return false;
        }
    }

    return true;
}

vector<int> get_coverd_mini_ad(int idx, Rect LRTB, vector<pair<int,int>> const& LT, vector<pair<int,int>>& WH, vector<bool>& scored){
    int L,R,T,B,W,H; 
    int N = LT.size();
    vector<int> res;
    REP(i,N){
        if(i==idx) continue;
        tie(L,T) = LT[i];
        tie(W,H) = WH[i];
        if(W==0) continue;
        R = L+W; B = T+H;

        Rect ad = make_tuple(L,R,T,B);
        if(is_overlap(LRTB, ad)){
            res.emplace_back(i);
        }
    }
    // debug(res)
    return res;
}

//step1(初期解)
void set_step1(vector<Rect>& XYRi, vector<pair<int,int>>& LT, vector<pair<int,int>>& WH, vector<bool>& scored){
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

//step2(初期解)
void set_step2(vector<Rect>& XYRi, vector<pair<int,int>>& LT, vector<pair<int,int>>& WH, vector<bool>& scored, vector<Rect>& ans){
    int N = XYRi.size();
    REP(i,N){
        int idx = get<3>(XYRi[i]);

        if(WH[i]==mp(0,0) or not scored[i]){ //置く場所なかった広告は適当にあれする(とりあえず)
            /* begin for debug 
            set_ans(XYRi, LT, WH, ans);
            int before_score = get_score(XYRi, ans);
                end for debug */
            int X,Y,R,_; tie(X,Y,R,_) = XYRi[i]; //広告の場所におけるなら置く
            if(check(X, Y, LT, WH)){
                Rect LRTB = make_tuple(X,X+1,Y,Y+1);
                int left_l = -1, left_r = X;

                //左側どこまでいけるか
                while(abs(left_r - left_l) > 1){
                    int mid = (left_r + left_l) / 2;
                    get<0>(LRTB) = mid;
                    if(check_board(i,LRTB,LT,WH,scored)) left_r = mid;
                    else left_l = mid;
                }

                get<0>(LRTB) = left_r;

                
                //上側どこまでいけるか
                int top_u = -1, top_d = Y;
                while(abs(top_d - top_u) > 1){
                    int mid = (top_d + top_u) / 2;
                    get<2>(LRTB) = mid;
                    if(check_board(i,LRTB,LT,WH,scored)) top_d = mid;
                    else top_u = mid;
                }

                get<2>(LRTB) = top_d;

                //右側どこまでいけるか
                int right_l = X+1, right_r = WIDTH+1;
                while(abs(right_r - right_l) > 1){
                    int mid = (right_r + right_l) / 2;
                    get<1>(LRTB) = mid;
                    if(check_board(i,LRTB,LT,WH,scored)) right_l = mid;
                    else right_r = mid;
                }

                get<1>(LRTB) = right_l;

                //下側どこまでいけるか
                int bottom_u = Y+1, bottom_d = HEIGHT+1;
                // debug(mp(bottom_u, bottom_d))
                while(abs(bottom_d - bottom_u) > 1){
                    int mid = (bottom_d + bottom_u) / 2;
                    get<3>(LRTB) = mid;
                    if(check_board(i,LRTB,LT,WH,scored)) bottom_u = mid;
                    else bottom_d = mid;
                }
                get<3>(LRTB) = bottom_u;

                // debug(mp(bottom_u, bottom_d))
                // if(i==35) debug(LRTB);

                int left = left_r; int top = top_d;
                int width = X+1-left; int height = Y+1-top;
                // debug(R)
                // debug(width*height)
                // debug(mp(X,Y))
                if(width*height > R){
                    if(width>height) width = R/height;
                    else height = R/width;
                    left = X+1-width;
                    top = Y+1-height;
                }else{
                    int right = right_l; int bottom = bottom_u;
                    width = right-left; height = bottom-top;
                    if(width>height){
                        chmin(width, R/height);
                        chmax(left, X+1-width);
                    }else {
                        chmin(height, R/width);
                        chmax(top, Y+1-height);
                    }
                }
                LT[i] = make_pair(left, top);
                WH[i] = make_pair(width, height);
                scored[i] = true;
                /* begin for debug 
                set_ans(XYRi, LT, WH, ans);
                int after_score = get_score(XYRi, ans);
                assert(after_score > before_score);
                    end for debug */
            }
        }

    }
}

//step3(初期解)
void set_step3(vector<Rect>& XYRi, vector<pair<int,int>>& LT, vector<pair<int,int>>& WH, vector<bool>& scored, vector<Rect>& ans){
    int N = XYRi.size();
    REP(i,N){
        int idx = get<3>(XYRi[i]);
        int X,Y;
        if(WH[i] == make_pair(0,0)){ //置く場所なかった広告は適当に配置
            while(true){
                X = xor128() % WIDTH; Y = xor128() % HEIGHT;
                if(check(X, Y, LT, WH)){
                    LT[i] = make_pair(X, Y);
                    WH[i] = make_pair(1, 1);
                    break;
                }
            }
            int l,r,t,b; tie(l,t) = LT[i];
            r = l + WH[i].first;
            b = t + WH[i].second;

            ans[idx] = make_tuple(l,t,r,b);
        }
    }
}

//左側いけるところまで伸ばす
void extend_left_to_lim(int i,Rect& LRTB, int X, int Y, vector<pair<int,int>> const& LT, vector<pair<int,int>> const& WH, vector<bool>& scored){
    int left_l = -1, left_r = X;
    while(abs(left_r - left_l) > 1){
        int mid = (left_r + left_l) / 2;
        get<0>(LRTB) = mid;
        if(check_board(i,LRTB,LT,WH,scored)) left_r = mid;
        else left_l = mid;
    }
    get<0>(LRTB) = left_r;
    // WH[i].first = get<1>(LRTB) - get<0>(LRTB);
}

//上側いけるところまで伸ばす
void extend_top_to_lim(int i,Rect& LRTB, int X, int Y, vector<pair<int,int>> const& LT, vector<pair<int,int>> const& WH, vector<bool>& scored){
    int top_u = -1, top_d = Y;
    while(abs(top_d - top_u) > 1){
        int mid = (top_d + top_u) / 2;
        get<2>(LRTB) = mid;
        if(check_board(i,LRTB,LT,WH,scored)) top_d = mid;
        else top_u = mid;
    }
    get<2>(LRTB) = top_d;
    // WH[i].second = get<3>(LRTB) - get<2>(LRTB);
}

//右側いけるところまで伸ばす
void extend_right_to_lim(int i,Rect& LRTB, int X, int Y, vector<pair<int,int>> const& LT, vector<pair<int,int>> const& WH, vector<bool>& scored){
    int right_l = X+1, right_r = WIDTH+1;
    while(abs(right_r - right_l) > 1){
        int mid = (right_r + right_l) / 2;
        get<1>(LRTB) = mid;
        if(check_board(i,LRTB,LT,WH,scored)) right_l = mid;
        else right_r = mid;
    }
    get<1>(LRTB) = right_l;
    // WH[i].first = get<1>(LRTB) - get<0>(LRTB);
}

//下側いけるところまで伸ばす
void extend_bottom_to_lim(int i,Rect& LRTB, int X, int Y, vector<pair<int,int>> const& LT, vector<pair<int,int>> const& WH, vector<bool>& scored){
    int bottom_u = Y+1, bottom_d = HEIGHT+1;
    while(abs(bottom_d - bottom_u) > 1){
        int mid = (bottom_d + bottom_u) / 2;
        get<3>(LRTB) = mid;
        if(check_board(i,LRTB,LT,WH,scored)) bottom_u = mid;
        else bottom_d = mid;
    }
    get<3>(LRTB) = bottom_u;
    // WH[i].second = get<3>(LRTB) - get<2>(LRTB);
}

//step4(改善)
void set_step4(vector<Rect>& XYRi, vector<pair<int,int>>& LT, vector<pair<int,int>>& WH, vector<bool>& scored, vector<Rect>& ans, vector<int> const& indices1, vector<int> const& indices2){
    int N = XYRi.size();
    
    for(auto i:indices1){
        int idx = get<3>(XYRi[i]);

        if(WH[i]==mp(0,0) or not scored[i]){ //まだ置いてない or 指定地点に置かれてない広告をどうにかする
            int X,Y,R,_; tie(X,Y,R,_) = XYRi[i]; 
            if(check(X, Y, LT, WH)){ //広告の場所におけるなら置く
                /* begin for debug 
                set_ans(XYRi, LT, WH, ans);
                int before_score = get_score(XYRi, ans);
                    end for debug */
                Rect LRTB = make_tuple(X,X+1,Y,Y+1);
                for(auto j:indices2){ 
                    if(j==0){
                        extend_left_to_lim(i,LRTB,X,Y,LT,WH,scored);
                    }else if(j==1){
                        extend_right_to_lim(i,LRTB,X,Y,LT,WH,scored);
                    }else if(j==2){
                        extend_top_to_lim(i,LRTB,X,Y,LT,WH,scored);
                    }else if(j==3){
                        extend_bottom_to_lim(i,LRTB,X,Y,LT,WH,scored);
                    }

                    int width  = get<1>(LRTB) - get<0>(LRTB);
                    int height = get<3>(LRTB) - get<2>(LRTB);

                    if(width*height > R){
                        if(width>height) width = R/height;
                        else height = R/width;

                        chmax(get<0>(LRTB), X+1-width);
                        get<1>(LRTB) = get<0>(LRTB) + width;

                        chmax(get<2>(LRTB), Y+1-height);
                        get<3>(LRTB) = get<2>(LRTB) + height;
                        break;
                    }else{}
                }

                //上の操作で1x1の広告がかぶったら,どける.
                vector<int> coverd_mini_ad = get_coverd_mini_ad(i, LRTB, LT, WH, scored);
                for(auto remove_idx:coverd_mini_ad){ WH[remove_idx] = mp(0,0); }

                LT[i] = make_pair(get<0>(LRTB), get<2>(LRTB));
                WH[i] = make_pair(get<1>(LRTB) - get<0>(LRTB), get<3>(LRTB) - get<2>(LRTB));
                ans[idx] = make_tuple(get<0>(LRTB), get<2>(LRTB) , get<1>(LRTB), get<3>(LRTB));
                scored[i] = true;

                /* begin for debug
                set_ans(XYRi, LT, WH, ans);
                int after_score = get_score(XYRi, ans);
                assert(after_score > before_score);
                    end for debug */
            }
        }

    }
}

//ansにLT,WHのデータを格納する.
void set_ans(vector<Rect>const& XYRi, vector<pair<int,int>>const& LT, vector<pair<int,int>>const& WH, vector<Rect>& ans){
    int N = XYRi.size();
    REP(i,N){
        int idx = get<3>(XYRi[i]);
        
        int l,r,t,b; tie(l,t) = LT[i];
        r = l + WH[i].first;
        b = t + WH[i].second;

        ans[idx] = make_tuple(l,t,r,b);
    }
}

long double get_score(vector<Rect>& XYRi, vector<Rect>& ans){
    int l,t,r,b,w,h; 
    int N = XYRi.size();
    long double score = 0; 
    REP(i,N){
        int X,Y,R,idx; tie(X,Y,R,idx) = XYRi[i];
        tie(l,t,r,b) = ans[idx];
        w = r-l; h = b-t;

        if(l<=X and X<r and t<=Y and Y<b) {
            score += 1-(1-(long double)min(R,w*h)/max(R,w*h))*(1-(long double)min(R,w*h)/max(R,w*h));   
        }else{ }
    }
    score *= 1e9 / N;
    return score;
}

void remove_ad(int idx, vector<pair<int,int>>& WH, vector<bool>& scored){
    WH[idx] = mp(0,0);
    scored[idx] = false;
}

void delete_neighbor_AS(vector<Rect>& XYRi, vector<pair<int,int>>& LT, vector<pair<int,int>>& WH, vector<bool>& scored, vector<Rect>& ans, double temp, vector<int> const& indices1, vector<int> const& indices2){

}

//step4(改善)
void random_change(vector<Rect>& XYRi, vector<pair<int,int>>& LT, vector<pair<int,int>>& WH, vector<bool>& scored, vector<Rect>& ans, clock_t start_time, clock_t end_time){
    auto best_sol = ans;
    auto best_score = get_score(XYRi, ans);
    auto now_score = best_score;
    int N = LT.size();
    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    double start_temp = 1e9,  end_temp = 0;
    while(true){
        clock_t now = clock();
        if(now > end_time){
            break;
        }
        double temp = get_temp(now, start_time, end_time, start_temp, end_temp);


        vector<int> indices1; REP(i,N) indices1.emplace_back(i); shuffle(ALL(indices1), engine); //中に入れたりする
        REP(_,2000){
            vector<int> indices2; REP(i,N) indices2.emplace_back(i); shuffle(ALL(indices2), engine);
            auto old_XYRi=XYRi; auto old_LT=LT; auto old_WH=WH; auto old_scored=scored;

            remove_ad(xor128() % N, WH, scored);

            set_step4(XYRi,LT,WH,scored,ans,indices1, indices2);

            set_step3(XYRi,LT,WH,scored,ans);


            // 制約チェック(デバッグ用)
            // REP(i,N){
            //     int l,t; tie(l,t) = LT[i];
            //     int width,height; tie(width,height) = WH[i];
            //     int r,b; tie(r,b) = mp(l+width, t+height);

            //     assert(check_board(i, make_tuple(l,r,t,b), LT, WH, vector<bool>(N,true)));
            // }
            
            auto new_score = get_score(XYRi, ans);
            bool change = false;
            double prob = exp((now_score - new_score) / temp);
            if(prob >= rand()/(double)RAND_MAX){ //採用

            }else{
                // assert(new_score > now_score);
                XYRi = old_XYRi; LT = old_LT; WH = old_WH; scored = old_scored; //戻す
            }

            if(best_score < new_score){
                best_sol = ans;
                best_score = new_score;
                // debug(best_score)
            }

        }
    }
    ans = best_sol;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    clock_t start_time = clock();
    double sec = 4.8; //何秒間回すか
    clock_t end_time = start_time + (sec * CLOCKS_PER_SEC);


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

    vector<Rect> ans(N);

    set_step2(XYRi, LT, WH, scored, ans);

    set_step3(XYRi, LT, WH, scored, ans);
    
    set_ans(XYRi, LT, WH, ans);

    random_change(XYRi, LT, WH, scored, ans, start_time, end_time);  //これの最後でansを過去ベストに更新してるのでLT, WHはこの時点でansとは一致する保証はない.

    REP(i,N){
        int l,t,r,b; tie(l,t,r,b) = ans[i];

        // cerr << i << " : ";
        cout << l << " " << t << " " << r << " " << b << bn;
    }
    
    // sort(ALL(ans));
    // REP(i,N){
    //     int l,t,r,b; tie(l,t,r,b) = ans[i];
    //     if(true){
    //         debug("A")
    //         cout << l << "\t" << t << "\t" << r << "\t" << b << endl;
    //     }
    //     assert((0<=l and l<r and r<=WIDTH));
    //     assert((0<=t and t<b and b<=HEIGHT));
    // }

    return 0;
}