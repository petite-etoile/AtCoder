// int neighbor_cnt = 0;

int get_partial_cost_swap_home(vector<vector<int>> const& league_table, int team1, int team2, int slot1, int slot2, vector<vector<int>> const& dist_matrix){
    int cost = 0, slot_num = league_table[0].size();

    cost += get_cost(team1, slot1, league_table, dist_matrix);
    cost += get_cost(team1, slot2, league_table, dist_matrix);
    cost += get_cost(team2, slot2, league_table, dist_matrix);
    cost += get_cost(team2, slot1, league_table, dist_matrix);

    return cost;
}

// flag=trueのときは、許容解か判定が必要だが、そうでないときはいらない.
bool swap_home(vector<vector<int>>& league_table, int team1, int team2, int slot1, int slot2, vector<vector<int>> const& dist_matrix, int& val, bool flag){
    // cerr << "SWAP HOME" << flag <<  endl;
    int cost_diff = 0;
    if(flag) cost_diff -= get_partial_cost_swap_home(league_table, team1, team2, slot1, slot2, dist_matrix);
    
    league_table[team1][slot1] *= -1; league_table[team1][slot2] *= -1;
    league_table[team2][slot1] *= -1; league_table[team2][slot2] *= -1;

    if(not flag) return false;
    
    // Check AtMost
    bool valid = AtMost_ok(league_table, team1, slot1) & AtMost_ok(league_table, team2, slot1) & AtMost_ok(league_table, team1, slot2) & AtMost_ok(league_table, team2, slot2);

    if(not valid) return false;

    cost_diff += get_partial_cost_swap_home(league_table, team1, team2, slot1, slot2, dist_matrix);
    val = val + cost_diff; 
    
    // assert(league_checker(league_table));
    // assert(calc_TTP_cost(league_table, dist_matrix) == val);
    return true;

}   

