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
#include<iostream>
#include<fstream>
#include<vector>
#include<utility>
#include<string>
#include<cassert>
#include<set>
#include<tuple>
#include<time.h>
#include<unistd.h>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<cstdlib>
#include"IO.h"
#include"league_func.h"
#include"SwapHome.h"
#include"Annealing.h"
#include"SwapHomeAS.h"
typedef long long int64;
using namespace std;
#define debug(x) cerr << #x << ": " << x << "\n";
#define mp make_pair


void annealing_search(vector<vector<int>>& league_table, int& obj_val, vector<vector<int>> const& dist_matrix){
    vector<vector<int>> best_sol = league_table;
    int best_val = obj_val;

    clock_t start_time = clock();
    int sec = 6; //何秒間回すか
    clock_t end_time = start_time + (sec * CLOCKS_PER_SEC);
    double start_temp = get_max_modify(dist_matrix),  end_temp = 0;
    // start_temp = 1000;
    debug(mp(start_temp, end_temp))
    debug(start_time);
    debug(end_time);

    while(true){
        clock_t now = clock();
        // assert(obj_val == calc_TTP_cost(league_table, dist_matrix));
        // debug(mp(now, end_time))
        if(now >= end_time) break;
        double temp = get_temp(now, start_time, end_time, start_temp, end_temp);
        for(int _=0; _<100; _++){
            search_swap_home_neighbors_AS(league_table, obj_val, dist_matrix, temp);
            // assert(league_checker(league_table));
            if(obj_val < best_val){
                best_val = obj_val;
                best_sol = league_table;
                debug(best_val)
            }
        }
    }

    //今までの中での最適解を返す
    obj_val = best_val;
    league_table = move(best_sol);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    //入力
    vector<vector<int>> league_table = input_league_table("./data/league_table.csv");
    vector<vector<int>> dist_matrix = input_matrix("./data/matrix.txt");
    // debug(league_table)
    debug(dist_matrix)
    assert(dist_matrix.size() == dist_matrix[0].size());

    assert(league_checker(league_table));

    int obj_val = calc_TTP_cost(league_table, dist_matrix); //初期解の目的関数値
    cerr << "初期解の目的関数値:" << (obj_val) << endl;
    annealing_search(league_table, obj_val, dist_matrix); //局所探索
    assert(league_checker(league_table)); assert(obj_val ==  calc_TTP_cost(league_table, dist_matrix));
    cerr << "局所最適値:" << (obj_val) << endl;
    output_schedule(league_table, "./data/test_table.csv");
}