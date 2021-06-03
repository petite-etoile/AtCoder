int get_partial_cost_swap_round(vector<vector<int>> const& league_table, int slot1, int slot2, vector<vector<int>> const& dist_matrix){
    int cost = 0, slot_num = league_table[0].size(), team_num = league_table.size();
    for(int team=0; team < team_num; team++){
        cost += get_cost(team, slot1, league_table, dist_matrix);
        cost += get_cost(team, slot2, league_table, dist_matrix);
    }
    return cost;
}

void modify_league_table_swap_round(vector<vector<int>>& league_table, int slot1, int slot2){
    int team_num = league_table.size();
    for(int team=0; team<team_num; team++){
        swap(league_table[team][slot1],league_table[team][slot2]);
    }
}

bool swap_round(vector<vector<int>>& league_table, int slot1, int slot2, vector<vector<int>> const& dist_matrix, int& val,bool flag){
    int cost_diff = 0;
    if(flag) cost_diff -= get_partial_cost_swap_round(league_table, slot1, slot2, dist_matrix); 

    modify_league_table_swap_round(league_table, slot1, slot2);

    if(not flag) return false;

    bool valid = true;
    int team_num = league_table.size();
    //Check AtMost
    for(int team=0; team<team_num; team++){
        if(not AtMost_ok(league_table, team, slot1)) valid = false;
        if(not AtMost_ok(league_table, team, slot2)) valid = false;
        if(not valid) break;
    }

    //Check NoRepeater
    for(int team=0; team<team_num; team++){
        if(not NoRepeater_ok(league_table, team, slot1)) valid = false;
        if(not NoRepeater_ok(league_table, team, slot2)) valid = false;
        if(not valid) break;
    }

    if(not valid) return false;

    cost_diff += get_partial_cost_swap_round(league_table, slot1, slot2, dist_matrix);
    val = val + cost_diff;

    // assert(league_checker(league_table));
    // assert(calc_TTP_cost(league_table, dist_matrix) == val);

    return true;
}