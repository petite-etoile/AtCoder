#include <climits>
using namespace std;
typedef long long int64;
double get_temp(clock_t now, clock_t start_time, clock_t end_time, double start_temp, double end_temp){
    return double(start_temp * (end_time - now) + end_temp * (now - start_time)) / (end_time - start_time);
}

// double get_temp(clock_t now, clock_t start_time, clock_t end_time, double start_temp, double end_temp){
//     return double(start_temp * (end_time - now) + end_temp * (now - start_time)) / (end_time - start_time);
// }


int64 get_max_modify(vector<vector<int>> dist_matrix){
    int64 res = 0;
    for(auto& row: dist_matrix){
        sort(row.begin(), row.end(), greater<int>());
        res = max(res, accumulate(row.begin(), row.begin()+1, 0LL)); //とりあえずすべての和の最大値を目的関数値更新の最大とする
    }
    return res;
}

unsigned long xor128() {
    static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
    unsigned long t=(x^(x<<11));
    x=y; y=z; z=w;
    return ( w=(w^(w>>19))^(t^(t>>8)) );
}
const unsigned long rand_max = ULONG_MAX; //これを確率の部分で使うと微妙だった(MAXがちょっと違う？不明)
