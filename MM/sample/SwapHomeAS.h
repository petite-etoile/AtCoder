using namespace std;
#define debug(x) cerr << #x << ": " << x << "\n";



void search_swap_home_neighbors_AS(vector<vector<int>>& league_table, int& obj_val, vector<vector<int>> const& dist_matrix, double temperature){
    int team_num = league_table.size();

    int team1, team2;
    do{
        team1 = xor128() % team_num;
        team2 = xor128() % team_num;
    }while(team1 == team2);

    int slot1, slot2;
    tie(slot1, slot2) = get_slots_AvsB(league_table, team1, team2);
    assert(slot1 != slot2);

    int now_val = obj_val;
    if(swap_home(league_table, team1, team2, slot1, slot2, dist_matrix, now_val, true)){
        // assert(now_val == calc_TTP_cost(league_table, dist_matrix));
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
        swap_home(league_table, team1, team2, slot1, slot2, dist_matrix, now_val, false); //焼きなましで遷移しないことが決まったので戻す
        

    }else swap_home(league_table, team1, team2, slot1, slot2, dist_matrix, now_val, false); //許容解ではなかったので戻す


    // assert(league_checker(league_table));
}
