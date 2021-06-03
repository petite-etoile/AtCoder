int get_partial_cost_partial_swap_round(vector<vector<int>> const& league_table, vector<int> const& teams, int slot1, int slot2, vector<vector<int>> const& dist_matrix){
    int cost = 0;
    for(auto team:teams){
        cost += get_cost(team, slot1, league_table, dist_matrix);
        cost += get_cost(team, slot2, league_table, dist_matrix);
    }
    return cost;
}

void modify_league_table_partial_swap_round(vector<vector<int>>& league_table, vector<int> const& teams, int slot1, int slot2){
    for(auto team:teams){
        swap(league_table[team][slot1], league_table[team][slot2]);
    }
}

bool AtMost_ok_partial_swap_round(vector<vector<int>> const& league_table, vector<int> const& teams, int slot1, int slot2){
    for(auto team:teams){
        if( (not AtMost_ok(league_table, team, slot1)) or (not AtMost_ok(league_table, team, slot2)) ) return false;
    }
    return true;
}

bool NoRepeater_ok_partial_swap_round(vector<vector<int>>& league_table, vector<int> const& teams, int slot1, int slot2){
    for(auto team:teams){
        if( (not NoRepeater_ok(league_table, team, slot1)) or (not NoRepeater_ok(league_table, team, slot2)) ) return false;
    }
    return true;
}

vector<int> get_teams_changed_partial_swap_round(vector<vector<int>> const& league_table, int team1, int slot1, int slot2){
    vector<int> teams = {team1};
    vector<int> slots = {slot1, slot2};
    int slot_switch = 0;
    int now_team = get_rival(league_table, team1, slots[slot_switch]);
    while(team1 != now_team){
        teams.emplace_back(now_team);
        slot_switch ^= 1;
        // cerr << now_team + 1 << "のスロット" << slots[slot_switch] + 1 << "の相手は" << get_rival(league_table, now_team, slots[slot_switch]) + 1 << "(1-indexed)" << endl;
        now_team = get_rival(league_table, now_team, slots[slot_switch]);
    }
    return teams;
}


bool group_swap_round(vector<vector<int>>& league_table, int slot1, int slot2, int team1, vector<bool>& searched, vector<vector<int>> const& dist_matrix, int& val, bool flag){
    int cost_diff = 0;
    // cerr << "team1, slot1, slot2 :" << team1 << " " << slot1 << " " << slot2 << endl;

    vector<int> teams = get_teams_changed_partial_swap_round(league_table, team1, slot1, slot2);

    if(flag) {
        cost_diff -= get_partial_cost_partial_swap_round(league_table, teams, slot1, slot2, dist_matrix); 
        for(auto team:teams) {
            // assert(searched[team] == false);
            searched[team] = true;
        }
    }


    modify_league_table_partial_swap_round(league_table, teams, slot1, slot2);



    if(not flag) return false;

    bool valid = true;
    int team_num = league_table.size();
    //Check AtMost
    if( not AtMost_ok_partial_swap_round(league_table, teams, slot1, slot2)) valid = false;

    //Check NoRepeater
    if( not NoRepeater_ok_partial_swap_round(league_table, teams, slot1, slot2)) valid = false;

    if(not valid) return false;

    cost_diff += get_partial_cost_partial_swap_round(league_table, teams, slot1, slot2, dist_matrix);
    val = val + cost_diff;

    // assert(league_checker(league_table));
    // assert(calc_TTP_cost(league_table, dist_matrix) == val);

    return true;


}