void search_partial_swap_team_neighbors_AS(vector<vector<int>>& league_table, int& obj_val, vector<vector<int>> const& dist_matrix, double temperature){
    int team_num = league_table.size(), slot_num = league_table[0].size();

    int slot1 = xor128() % slot_num;
    int team1, team2;
    do{
        team1 = xor128() % team_num;
        team2 = xor128() % team_num;
    }while(team1 == team2);


    int now_val = obj_val;
    if(partial_swap_team(league_table, team1, team2, slot1, dist_matrix, now_val, true)){
        if(now_val < obj_val){
            obj_val = now_val;
            return;
        }else{ //悪くなる遷移でも確率で遷移する(焼きなまし)
            double prob = exp((obj_val - now_val) / temperature);
            cerr << "prob:" << prob << endl;
            cerr << "obj_val, val :" << obj_val << " " << now_val << endl;
            cerr << "temp:" << temperature << endl << endl;
            if(prob > rand()/(double)RAND_MAX){
                obj_val = now_val;
                return;
            }
        }
        partial_swap_team(league_table, team1, team2, slot1, dist_matrix, now_val, false); //焼きなましで遷移しないことが決まったので戻す

    }else partial_swap_team(league_table, team1, team2, slot1, dist_matrix, now_val, false); //許容解ではなかったので戻す

    // assert(obj_val == calc_TTP_cost(league_table, dist_matrix));
    // assert(league_checker(league_table));
}
