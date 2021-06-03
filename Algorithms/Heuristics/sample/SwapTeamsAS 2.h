using namespace std;
#define debug(x) cerr << #x << ": " << x << "\n";

void search_swap_teams_neighbors_AS(vector<vector<int>>& league_table, int& obj_val, vector<vector<int>>const& dist_matrix, double temperature){
    int team_num = league_table.size();

    int team1, team2;
    do{
        team1 = xor128() % team_num;
        team2 = xor128() % team_num;
    }while(team1 == team2);

    int now_val = obj_val;

    if(swap_teams(league_table, team1, team2, dist_matrix, now_val, true)){
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
        swap_teams(league_table, team1, team2, dist_matrix, now_val, false);
    }else swap_teams(league_table, team1, team2, dist_matrix, now_val, false);

}

