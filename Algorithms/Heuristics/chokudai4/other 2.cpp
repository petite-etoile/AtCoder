    #include <iostream>
    #include <vector>
    #include <cstdio>
    #include <cstring>
    #include <sstream>
    #include <map>
    #include <string>
    #include <algorithm>
    #include <queue>
    #include <cmath>
    #include <functional>
    #include <set>
    #include <ctime>
    #include <random>
    #include <chrono>
    #include <cassert>
    #include <tuple>
    #include <numeric>
    #include <utility>
    using namespace std;

    namespace {
    using Integer = long long; //__int128;
    template<class T, class S> istream& operator >> (istream& is, pair<T,S>& p){return is >> p.first >> p.second;}
    template<class T> istream& operator >> (istream& is, vector<T>& vec){for(T& val: vec) is >> val; return is;}
    template<class T> istream& operator ,  (istream& is, T& val){ return is >> val;}
    template<class T, class S> ostream& operator << (ostream& os, const pair<T,S>& p){return os << p.first << " " << p.second;}
    template<class T> ostream& operator << (ostream& os, const vector<T>& vec){for(size_t i=0; i<vec.size(); i++) os << vec[i] << (i==vec.size()-1?"":" "); return os;}
    template<class T> ostream& operator ,  (ostream& os, const T& val){ return os << " " << val;}

    template<class H> void print(const H& head){ cout << head; }
    template<class H, class ... T> void print(const H& head, const T& ... tail){ cout << head << " "; print(tail...); }
    template<class ... T> void println(const T& ... values){ print(values...); cout << endl; }

    template<class H> void eprint(const H& head){ cerr << head; }
    template<class H, class ... T> void eprint(const H& head, const T& ... tail){ cerr << head << " "; eprint(tail...); }
    template<class ... T> void eprintln(const T& ... values){ eprint(values...); cerr << endl; }

    class range{ Integer start_, end_, step_; public: struct range_iterator{ Integer val, step_; range_iterator(Integer v, Integer step) : val(v), step_(step) {} Integer operator * (){return val;} void operator ++ (){val += step_;} bool operator != (range_iterator& x){return step_ > 0 ? val < x.val : val > x.val;} }; range(Integer len) : start_(0), end_(len), step_(1) {} range(Integer start, Integer end) : start_(start), end_(end), step_(1) {} range(Integer start, Integer end, Integer step) : start_(start), end_(end), step_(step) {} range_iterator begin(){ return range_iterator(start_, step_); } range_iterator   end(){ return range_iterator(  end_, step_); } };

    inline string operator "" _s (const char* str, size_t size){ return move(string(str)); }
    constexpr Integer my_pow(Integer x, Integer k, Integer z=1){return k==0 ? z : k==1 ? z*x : (k&1) ? my_pow(x*x,k>>1,z*x) : my_pow(x*x,k>>1,z);}
    constexpr Integer my_pow_mod(Integer x, Integer k, Integer M, Integer z=1){return k==0 ? z%M : k==1 ? z*x%M : (k&1) ? my_pow_mod(x*x%M,k>>1,M,z*x%M) : my_pow_mod(x*x%M,k>>1,M,z);}
    constexpr unsigned long long operator "" _ten (unsigned long long value){ return my_pow(10,value); }

    inline int k_bit(Integer x, int k){return (x>>k)&1;} //0-indexed

    mt19937 mt(chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count());

    template<class T> string join(const vector<T>& v, const string& sep){ stringstream ss; for(size_t i=0; i<v.size(); i++){ if(i>0) ss << sep; ss << v[i]; } return ss.str(); }

    inline string operator * (string s, int k){ string ret; while(k){ if(k&1) ret += s; s += s; k >>= 1; } return ret; }
    }
    constexpr long long mod = 9_ten + 7;

    #define dump(x) eprintln("L#", __LINE__, ":", #x, "=", x)
    #define logger(x) eprintln("L#", __LINE__, ":", timer::get()*1000, "[ms]:", #x, "=", x)

    namespace timer{
    using namespace chrono;
    steady_clock::time_point start_time;

    unsigned long long begin_time;
    unsigned long long get_cycle();
    void init();
    double get_sec_per_cycle();
    double get();

    unsigned long long get_cycle(){
        unsigned int low, high;
        __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
        return ((unsigned long long)low) | ((unsigned long long)high << 32);
    }

    void init(){
        start_time = steady_clock::now();
        begin_time = get_cycle();
    }

    double get_sec_per_cycle(){
        auto end_time = steady_clock::now();
        double elapsed = duration_cast<nanoseconds>(end_time - start_time).count() * 1e-9;
        return elapsed / (get_cycle() - begin_time);
    }

    double get(){
        static double sec_per_cycle = get_sec_per_cycle();
        return (double)(get_cycle() - begin_time) * sec_per_cycle;
    }
    };

    struct xor_shift{
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t w;

    xor_shift(uint32_t seed = 88675123) : x(123456789), y(362436069), z(521288629), w(seed){
        for(int i=0; i<100; i++) next();
    }
    
    // [0..2^32)
    inline uint32_t next() {
        uint32_t t = x ^ (x << 11);
        x = y; y = z; z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
    }

    uint32_t operator () () {
        return next();
    }

    // [0, range)
    int operator () (int range){
        return (((long long)next()) * range) >> 32 ;
    }

    // [0, 1.0]
    double prob(){
        return (next()&0xfffffff) * 3.7252903123397e-9; // 0xfffffff = 268,435,455 = 2^28-1
    }

    // [first, last)
    template<class RandomIt>
    RandomIt operator() (RandomIt first, RandomIt last){
        int d = last - first;
        assert(d>0);
        return first + (*this)(d);
    }

    template<class T>
    T& operator()(vector<T>& v){
        return *(*this)(v.begin(), v.end());
    }
    };


template<size_t N, int ID = -1>
struct FastSet{
    array<int, N> data;
    array<int, N> index;
    int cnt;
    FastSet(){
        fill(index.begin(), index.end(), -1);
        cnt = 0;
    }
    void insert(int x){
        if(index[x] == -1){
            data[cnt] = x;
            index[x] = cnt++;
        }
    }
    void erase(int x){
        if(index[x] != -1){
            data[index[x]] = data[cnt-1];
            index[data[cnt-1]] = index[x];
            index[x] = -1;
            cnt--;
        }
    }
    inline int size(){
        return cnt;
    }
    int operator [] (int at){
        assert(at < cnt);
        return data[at];
    }

    bool has (int x){
        return index[x] != -1;
    }

    struct Itr {
        array<int, N>* data;
        int pos;

        int operator * () {
        return (*data)[pos];
        }
        bool operator != (const Itr& itr) const {
        return pos != itr.pos;
        }

        void operator ++ () {
        pos++;
        }
    };

    Itr begin() {
        return Itr{&data, 0};
    }

    Itr end() {
        return Itr{&data, cnt};
    }
};


struct State {
    array<char, 30*30> data;
    double raw_score;

    void init(){
        raw_score = 0.0;
        memset(data.data(), 0, 30*30);
    }
};

struct Move {
    int from;
    int val;
    double score;
};

array<State, 20000> pool;
FastSet<20000> pool_idx;

void init_pool(){
    for(int i=0; i<20000; i++){
        pool_idx.insert(i);
    }
}

int get_idx(){
    int res = pool_idx[pool_idx.size()-1];
    pool_idx.erase(res);
    pool[res].init();
    return res;
}

void pop_idx(int idx){
    pool_idx.insert(idx);
    return;
}

    int main(){
    timer::init();
    int n;
    cin >> n;

    vector<int> b(3);
    cin >> b;

    vector<vector<int>> lb(n, vector<int>(n));
    cin >> lb;
    vector<vector<int>> ub(n, vector<int>(n));
    cin >> ub;

    init_pool();

    constexpr int BEAM_WIDTH = 4000;

    array<array<int, 10000>, 2> beam;
    array<int, 2> beam_size{};
    int beam_id = 0;

    for(int v=lb[0][0]; v<=ub[0][0]; v++){
        int id = get_idx();
        auto& s = pool[id];
        beam[beam_id][beam_size[beam_id]++] = id;
        s.data[0] = v;
    }

    // for(int d=1; d<=2*(n-1); d++){
    //   for(int r=0; r<n; r++){
    //     int c = d-r;
    //     if(c>=n || c<0) continue;
    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
        // for(int c=(r%2==0)?0:n-1; (r%2==0)?c<n:c>=0; (r%2==0)?c++:c--){
        int cur = beam_id;
        int nex = beam_id^1;

        vector<Move> tmp;
        tmp.reserve(500);

        for(int ii=0; ii<beam_size[cur]; ii++){
            int id = beam[cur][ii];
            array<int, 40> tate{};
            array<int, 40> yoko{};

            array<int, 40> tate_acc{};
            array<int, 40> yoko_acc{};
            auto& s = pool[id];
            // if(r%2 == 0){
            for(int x=c-1, sum=0; x>=0 && sum<b[2]; x--){
                sum += s.data[r*30 + x];
                if(sum > b[2]) break;
                yoko[sum]++;
            }
            // }else{
            //   for(int x=c+1, sum=0; x<n && sum<b[2]; x++){
            //     sum += s.data[r*30 + x];
            //     if(sum > b[2]) break;
            //     yoko[sum]++;
            //   }
            // }
            for(int y=r-1, sum=0; y>=0 && sum<b[2]; y--){
            sum += s.data[y*30 + c];
            if(sum > b[2]) break;
            tate[sum]++;
            }

            for(int v=1; v<40; v++){
            tate_acc[v] = tate_acc[v-1] + tate[v];
            yoko_acc[v] = yoko_acc[v-1] + yoko[v];
            }
            for(int val=lb[r][c]; val<=ub[r][c]; val++){
            double delta = 0;
            delta += b[0] * (tate[b[0] - val] + yoko[b[0] - val]);
            delta += b[1] * (tate[b[1] - val] + yoko[b[1] - val]);
            delta += b[2] * (tate[b[2] - val] + yoko[b[2] - val]);

            double adj_score = 0;
            adj_score += (tate_acc[b[0] - 3] - tate_acc[b[0] - 7]) * b[0] * 0.0001;
            adj_score += (tate_acc[b[1] - 3] - tate_acc[b[1] - 7]) * b[1] * 0.0001;
            adj_score += (tate_acc[b[2] - 3] - tate_acc[b[2] - 7]) * b[2] * 0.0001;

            adj_score += (yoko_acc[b[0] - 3] - yoko_acc[b[0] - 7]) * b[0] * 0.0002;
            adj_score += (yoko_acc[b[1] - 3] - yoko_acc[b[1] - 7]) * b[1] * 0.0002;
            adj_score += (yoko_acc[b[2] - 3] - yoko_acc[b[2] - 7]) * b[2] * 0.0002;

            tmp.push_back(Move{
                .from = id,
                .val = val,
                .score = s.raw_score + delta + adj_score
            });
            }
        }

        struct Comp{
            vector<Move>* tmp;
            bool operator () (const Move& a, const Move& b) const {
            return a.score > b.score;
            }
        };
        Comp comp{&tmp};

        int next_width = min<int>(BEAM_WIDTH, tmp.size());
        if(next_width < tmp.size()){
            nth_element(begin(tmp), begin(tmp) + next_width, end(tmp), comp);
        }

        for(int i=0; i<next_width; i++){
            auto& move = tmp[i];
            auto& s = pool[move.from];
            int next_id = get_idx();
            auto& s_next = pool[next_id];
            beam[nex][beam_size[nex]++] = next_id;
            s_next.data = s.data;
            s_next.data[r*n + c] = move.val;
            s_next.raw_score = floor(move.score);
        }

        while(beam_size[cur] > 0){
            pop_idx(beam[cur][beam_size[cur]--]);
        }

        beam_id ^= 1;
        }
    }

    pair<double,int> best = {-1, -1};
    for(int i=0; i<beam_size[beam_id]; i++){
        int id = beam[beam_id][i];
        auto& s = pool[id];
        if(s.raw_score > best.first){
        best = {s.raw_score, id};
        }
    }

    auto& s = pool[best.second];

    logger(s.raw_score);

    vector<vector<int>> res(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
        res[i][j] = s.data[i*n + j];
        }
    }

    println(join(res, "\n"));

    return 0;
    }

