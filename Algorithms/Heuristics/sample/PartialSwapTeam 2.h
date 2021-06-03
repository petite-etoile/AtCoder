int get_partial_cost_partial_swap_team(vector<vector<int>> const& league_table, vector<int> const& slots, int team1, int team2, vector<vector<int>> const& dist_matrix){
    int cost = 0, slot_num = league_table[0].size();
    
    // debug(slots)

    for(int i=0; i<slots.size(); i++){
        int slot = slots[i];
        int team3 = get_rival(league_table, team1, slot), team4 = get_rival(league_table, team2, slot);

        if((i+1 == slots.size()) or (slots[i+1] != slot+1)){
            // debug(slot)
            cost += get_cost(team1, slot, league_table, dist_matrix);
            cost += get_cost(team2, slot, league_table, dist_matrix);
            cost += get_cost(team3, slot, league_table, dist_matrix);
            cost += get_cost(team4, slot, league_table, dist_matrix);
        }else{
            //(slot-1,slot)間のコスト
            if(slot > 0) cost += get_cost1(team1, league_table[team1][slot-1], league_table[team1][slot], dist_matrix) + get_cost1(team2, league_table[team2][slot-1], league_table[team2][slot], dist_matrix);
            else cost += get_cost2(team1, league_table[team1][slot], dist_matrix) + get_cost2(team2, league_table[team2][slot], dist_matrix);

            //最後のスロットのときのみ帰還コスト
            if(slot == slot_num-1) get_cost2(team1, league_table[team1][slot], dist_matrix) + get_cost2(team2, league_table[team2][slot], dist_matrix);


            //team3(team4)が連続するスロットが変更されるパティーン
            int rival_of_next_rival;
            
            rival_of_next_rival = get_rival(league_table, team3, slot+1);
            if(rival_of_next_rival == team1 or rival_of_next_rival == team2) {
                if(slot > 0) cost += get_cost1(team3, league_table[team3][slot-1], league_table[team3][slot], dist_matrix);
                else cost += get_cost2(team3, league_table[team3][slot], dist_matrix);
            }else cost += get_cost(team3, slot, league_table, dist_matrix);

            rival_of_next_rival = get_rival(league_table, team4, slot+1);
            if(rival_of_next_rival == team1 or rival_of_next_rival == team2) {
                if(slot > 0) cost += get_cost1(team4, league_table[team4][slot-1], league_table[team4][slot], dist_matrix);
                else cost += get_cost2(team4, league_table[team4][slot], dist_matrix);
            }else cost += get_cost(team4, slot, league_table, dist_matrix);

        }
    }
    return cost;
}

int get_debug_cost_diff(vector<vector<int>> const& league_table, vector<int> const& slots, int team1, int team2, vector<vector<int>> const& dist_matrix, int target_team){
    int cost = 0, slot_num = league_table[0].size();
    
    for(int i=0; i<slots.size(); i++){
        int slot = slots[i];
        int team3 = get_rival(league_table, team1, slot), team4 = get_rival(league_table, team2, slot);
        if(team3 == target_team or team4 == target_team) cost += get_cost(target_team, slot, league_table, dist_matrix);

        // if((i+1 == slots.size()) or (slots[i+1] != slot+1)){
        //     cost += get_cost(team1, slot, league_table, dist_matrix);
        //     cost += get_cost(team2, slot, league_table, dist_matrix);
        // }else{
        //     //(slot-1,slot)間のコスト
        //     if(slot > 0) cost += get_cost1(team1, league_table[team1][slot-1], league_table[team1][slot], dist_matrix) + get_cost1(team2, league_table[team2][slot-1], league_table[team2][slot], dist_matrix);
        //     else cost += get_cost2(team1, league_table[team1][slot], dist_matrix) + get_cost2(team2, league_table[team2][slot], dist_matrix);

        //     //最後のスロットのときのみ帰還コスト
        //     if(slot == slot_num-1) get_cost2(team1, league_table[team1][slot], dist_matrix) + get_cost2(team2, league_table[team2][slot], dist_matrix);

        // }
    }

    return cost;
}


void modify_league_table_partial_swap_team(vector<vector<int>>& league_table, vector<int> const& slots, int team1, int team2){
    for(auto slot:slots){
        swap(league_table[team1][slot], league_table[team2][slot]);

        set_rival_slot(league_table, team1, slot);
        set_rival_slot(league_table, team2, slot);
    }
}

bool AtMost_ok_partial_swap_team(vector<vector<int>> const& league_table, vector<int> const& slots, int team1, int team2){
    for(auto slot:slots){
        if( (not AtMost_ok(league_table, team1, slot)) or (not AtMost_ok(league_table, team2, slot)) ) return false;

        int team3 = get_rival(league_table, team1, slot), team4 = get_rival(league_table, team2, slot);
        if( (not AtMost_ok(league_table, team3, slot)) or (not AtMost_ok(league_table, team4, slot)) ) return false;
    }
    return true;
}

bool NoRepeater_ok_partial_swap_team(vector<vector<int>>& league_table, vector<int> const& slots, int team1, int team2){
    for(auto slot:slots){
        if( (not NoRepeater_ok(league_table, team1, slot)) or (not NoRepeater_ok(league_table, team2, slot)) ) return false;
        
        int team3 = get_rival(league_table, team1, slot), team4 = get_rival(league_table, team2, slot);
        if( (not NoRepeater_ok(league_table, team3, slot)) or (not NoRepeater_ok(league_table, team4, slot)) ) return false;
    }
    return true;
}

vector<int> get_slot_changed_partial_swap_team(vector<vector<int>> const& league_table, int team1, int team2, int slot1){
    if(get_rival(league_table, team1, slot1) == team2) return {}; //team1 と team2の対戦のslotの場合は、SwapHomeと同じなので無視する.(実装がめんどいだけ)

    int slot_num = league_table[0].size(), team_num = league_table.size();

    vector<int> slot_of(team_num*2+1, -1);
    for(int slot=0; slot<slot_num; slot++) slot_of[league_table[team1][slot] + team_num] = slot;

    vector<int> slots;
    int now_slot = slot1;

    do{
        slots.emplace_back(now_slot);
        int next_ = league_table[team2][now_slot];
        now_slot = slot_of[next_ + team_num];
    }while(now_slot != slot1);

    return slots;
}



bool partial_swap_team(vector<vector<int>>& league_table, int team1, int team2, int slot1, vector<vector<int>> const& dist_matrix, int& val, bool flag){
    int cost_diff = 0;
    int team_num = league_table.size(), slot_num = league_table[0].size();

    vector<int> slots = get_slot_changed_partial_swap_team(league_table, team1, team2, slot1);
    sort(slots.begin(), slots.end());
    // debug(slots)

    // vector<int> debug_cost(team_num);
    // for(int i=0; i<team_num; i++){
    //     debug_cost[i] = calc_cost_of_team(league_table, dist_matrix, i);
    //     debug_cost[i] -= get_debug_cost_diff(league_table, slots, team1, team2, dist_matrix, i);
    // }

    if(flag) cost_diff -= get_partial_cost_partial_swap_team(league_table, slots, team1, team2, dist_matrix); 

    // cerr << "team1, team2, slot1 :" << team1 << " " << team2 << " " << slot1 << endl;

    // if(flag) output_schedule(league_table, "test1.csv");
    modify_league_table_partial_swap_team(league_table, slots, team1, team2);
    // if(flag) output_schedule(league_table, "test2.csv");

    if(not flag) return false;



    bool valid = true;
    //Check AtMost
    if( not AtMost_ok_partial_swap_team(league_table, slots, team1, team2)) valid = false;

    //Check NoRepeater
    if( not NoRepeater_ok_partial_swap_team(league_table, slots, team1, team2)) valid = false;

    if(not valid) return false;

    cost_diff += get_partial_cost_partial_swap_team(league_table, slots, team1, team2, dist_matrix);
    val = val + cost_diff;

    // for(int i=0; i<team_num; i++){
    //     if(i == team1 or i == team2) continue;
    //     debug_cost[i] += get_debug_cost_diff(league_table, slots, team1, team2, dist_matrix, i);
    //     debug(i)
    //     debug(make_pair(debug_cost[i] , calc_cost_of_team(league_table, dist_matrix, i)))
    //     assert(debug_cost[i] == calc_cost_of_team(league_table, dist_matrix, i));
    // }

    // assert(league_checker(league_table));
    // assert(calc_TTP_cost(league_table, dist_matrix) == val);

    return true;
}