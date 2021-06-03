void group_swap_round_AS(vector<vector<int>>& league_table, int& obj_val, vector<vector<int>> const& dist_matrix, double temperature){
    int team_num = league_table.size(), slot_num = league_table[0].size();

    int slot1, slot2;
    do{
        slot1 = xor128() % slot_num;
        slot2 = xor128() % slot_num;
    }while(slot1 == slot2);

    vector<bool> searched(team_num, false);
    for(int team=0; team<team_num; team++){
        if(searched[team]) continue;
    
        int now_val = obj_val;
        if(group_swap_round(league_table, slot1, slot2, team, searched, dist_matrix, now_val, true)){
            if(now_val < obj_val){
                obj_val = now_val;
                return;
            }else{ //悪くなる遷移でも確率で遷移する(焼きなまし)
                double prob = exp((obj_val - now_val) / temperature);
                // cerr << "prob:" << prob << endl;
                // cerr << "obj_val, val :" << obj_val << " " << val << endl;
                // cerr << "temp:" << temperature << endl << endl;
                if(prob > rand()/(double)RAND_MAX){
                    obj_val = now_val;
                    return;
                }
            }
            group_swap_round(league_table, slot1, slot2, team, searched, dist_matrix, now_val, false); //焼きなましで遷移しないことが決まったので戻す
            

        }else group_swap_round(league_table, slot1, slot2, team, searched, dist_matrix, now_val, false); //許容解ではなかったので戻す
        // assert(league_checker(league_table));
    }
    // assert(vector<bool>(team_num,true) == searched);


}