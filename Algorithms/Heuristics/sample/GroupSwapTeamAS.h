void group_swap_team_AS(vector<vector<int>>& league_table, int& obj_val, vector<vector<int>> const& dist_matrix, double temperature){
    int team_num = league_table.size(), slot_num = league_table[0].size();

    int team1, team2;
    do{
        team1 = xor128() % team_num;
        team2 = xor128() % team_num;
    }while(team1 == team2);

    vector<bool> searched(slot_num, false);
    for(int slot=0; slot<slot_num; slot++){
        if(searched[slot]) continue;
    
        int now_val = obj_val;
        if(group_swap_team(league_table, team1, team2, slot, searched, dist_matrix, now_val, true)){
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
            group_swap_team(league_table, team1, team2, slot, searched, dist_matrix, now_val, false); //焼きなましで遷移しないことが決まったので戻す
            

        }else group_swap_team(league_table, team1, team2, slot, searched, dist_matrix, now_val, false); //許容解ではなかったので戻す
        // assert(league_checker(league_table));
    }
    // assert(vector<bool>(slot_num,true) == searched);


}