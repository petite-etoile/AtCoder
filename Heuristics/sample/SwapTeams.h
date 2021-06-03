int get_partial_cost_of_rival_teams(vector<vector<int>> const& league_table, int team1, int team2, vector<vector<int>> const& dist_matrix){
    int cost = 0;
    int slot_num = league_table[0].size();
    for(int slot = 0; slot < slot_num; slot++){
        if(abs(league_table[team1][slot]) == team2 + 1) continue;  
        int rival = abs(league_table[team1][slot]) - 1; //対戦相手

        //(slot-1,slot)間のコスト
        if(slot > 0) cost += get_cost1(rival, league_table[rival][slot-1], league_table[rival][slot], dist_matrix);
        else cost += get_cost2(rival, league_table[rival][slot], dist_matrix);

        //(slot,slot+1)間のコスト
        if(slot < slot_num-1){
            if(abs(league_table[rival][slot+1]) != team2 + 1){ 
                cost += get_cost1(rival, league_table[rival][slot], league_table[rival][slot+1], dist_matrix);
            }//else cerr << "連続" << rival << " " << slot << " " << league_table[rival][slot] << " " << league_table[rival][slot+1] << "\n";
        }else{
            cost += get_cost2(rival, league_table[rival][slot], dist_matrix);
        }
    }
    // cerr << "\n";

    return cost;
}

int get_partial_cost_swap_teams(vector<vector<int>> const& league_table, int team1, int team2, vector<vector<int>> const& dist_matrix){
    //AとBのコストを算出
    int cost = calc_cost_of_team(league_table, dist_matrix, team1) + calc_cost_of_team(league_table, dist_matrix, team2); //AとBのコスト

    //AやBの対戦相手の変化する部分のコストを算出
    cost += get_partial_cost_of_rival_teams(league_table, team1, team2, dist_matrix);
    cost += get_partial_cost_of_rival_teams(league_table, team2, team1, dist_matrix);

    return cost;
}

void modify_league_table_swap_teams(vector<vector<int>>& league_table, int team1, int team2){
    int slot_num = league_table[0].size(), rival;
    for(int slot = 0; slot < slot_num; slot++){
        if(abs(league_table[team1][slot]) == team2 + 1) continue; 
        swap(league_table[team1][slot], league_table[team2][slot]);

        set_rival_slot(league_table, team1, slot);
        set_rival_slot(league_table, team2, slot);
    }
}

/* debug start 
int debug_cost_of_rival_team(vector<vector<int>> const& league_table, int team1, int team2, vector<vector<int>> const& dist_matrix, int target_team){
    int cost = 0;
    int slot_num = league_table[0].size();
    for(int slot = 0; slot < slot_num; slot++){
        if(abs(league_table[team1][slot]) == team2 + 1) continue;  
        int rival = abs(league_table[team1][slot]) - 1; //対戦相手
        if(rival != target_team) continue;

        
        //(slot-1,slot)間のコスト
        if(slot > 0){
            cost += get_cost(rival, league_table[rival][slot-1], league_table[rival][slot], dist_matrix);
            // printf("%dのスロット%dで%dと%d間のコスト%d\n", rival, slot, league_table[rival][slot-1], league_table[rival][slot], get_cost(rival, league_table[rival][slot-1], league_table[rival][slot], dist_matrix));

        }else{
            cost += get_cost_to(rival, league_table[rival][slot], dist_matrix);
            // printf("%dのスロット%d(最初)で%dと%d間のコスト%d\n", rival, slot, rival, league_table[rival][slot], get_cost_to(rival, league_table[rival][slot], dist_matrix));
        }

        //(slot,slot+1)間のコスト
        if(slot < slot_num-1){
            if(abs(league_table[rival][slot+1]) != team2 + 1){ 
                cost += get_cost(rival, league_table[rival][slot], league_table[rival][slot+1], dist_matrix);
                // printf("%dのスロット%dで%dと%d間のコスト%d\n", rival, slot, league_table[rival][slot], league_table[rival][slot+1], get_cost(rival, league_table[rival][slot], league_table[rival][slot+1], dist_matrix));
            }//else cerr << rival << " " << slot << " " << league_table[rival][slot] << " " << league_table[rival][slot+1] << "\n";
        }else{
            cost += get_cost_to(rival, league_table[rival][slot], dist_matrix);
            // printf("%dのスロット%d(最後)で%dと%d間のコスト%d\n", rival, slot, league_table[rival][slot], rival, get_cost_to(rival, league_table[rival][slot], dist_matrix));
        }
    }

    return cost;
}



int debug_cost_changes(vector<vector<int>> const& league_table, int team1, int team2, vector<vector<int>> const& dist_matrix, int target_team){
    int cost = 0;

    cost += debug_cost_of_rival_team(league_table, team1, team2, dist_matrix, target_team);
    cost += debug_cost_of_rival_team(league_table, team2, team1, dist_matrix, target_team);

    return cost;
}

 debug end */

// flag=trueのときは、許容解か判定が必要だが、そうでないときはいらない.
bool swap_teams(vector<vector<int>>& league_table, int team1, int team2, vector<vector<int>> const& dist_matrix, int& val, bool flag){
    int slot_num = league_table[0].size(), team_num = league_table.size();
    int cost_diff = 0;

    if(flag) cost_diff -= get_partial_cost_swap_teams(league_table, team1, team2, dist_matrix);

    /*------debug start------*/
    // vector<int> debug_cost(team_num);
    // for(int target=0; target<team_num; target++){
    //     if(target == team1 or target == team2){
    //         debug_cost[target] = calc_cost_of_team(league_table, dist_matrix, target);
    //         debug_cost[target] -= calc_cost_of_team(league_table, dist_matrix, target);
    //     }else{
    //         debug_cost[target] = calc_cost_of_team(league_table, dist_matrix, target);
    //         debug_cost[target] -= debug_cost_changes(league_table, team1, team2, dist_matrix, target);
    //     }
    // }
    /*------debug end------*/

    modify_league_table_swap_teams(league_table, team1, team2);

    if(not flag) return false;

    bool valid = true;
    
    int slot1, slot2;
    tie(slot1, slot2) = get_slots_AvsB(league_table, team1, team2);

    //Check AtMost
    if(not AtMost_ok(league_table, team1, slot1)) valid = false;
    if(not AtMost_ok(league_table, team2, slot1)) valid = false;
    if(not AtMost_ok(league_table, team1, slot2)) valid = false;
    if(not AtMost_ok(league_table, team2, slot2)) valid = false;

    if(not valid) return false;

    cost_diff += get_partial_cost_swap_teams(league_table, team1, team2, dist_matrix);

    val = val + cost_diff;

    /*------debug start------*/
    // for(int target=0; target<team_num; target++){
    //     if(target == team1 or target == team2){
    //         debug_cost[target] += calc_cost_of_team(league_table, dist_matrix, target);
    //     }else{
    //         debug_cost[target] += debug_cost_changes(league_table, team1, team2, dist_matrix, target);
    //     }
    //     assert(calc_cost_of_team(league_table, dist_matrix, target) == debug_cost[target]);
    // }
    /*------debug end------*/


    // assert(league_checker(league_table));
    // assert(calc_TTP_cost(league_table, dist_matrix) == val);

    // cerr << "\n\n\n\n\n\n\n\n\n\n";

    return true;

}