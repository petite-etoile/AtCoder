using namespace std;
#define debug(x) cerr << #x << ": " << x << "\n";


//validならtrue
bool league_checker(vector<vector<int>> const& league_table){
    set<pair<int,int>> matches;
    for(int team_a=0; team_a < league_table.size(); team_a++){
        int continuous = 0;
        bool away = false;
        int before = 0;
        for(int slot = 0; slot < league_table[team_a].size(); slot++){
            int team_b = league_table[team_a][slot];

            //No Repeater
            if(before == abs(team_b)){
                printf("%dの%d日目にRepeater(1-indexed)\n", team_a+1, slot+1);
                return false;
            } 
            before = abs(team_b);

            if(team_b < 0){
                if(away) continuous++;
                else continuous = 1;
                away = true;
            }else{
                if(away) continuous = 1;
                else continuous++;
                away = false;
            }
            
            //同じ試合は1試合まで
            if(matches.find(make_pair(team_a+1, team_b)) != matches.end()) return false;

            //A vs B?
            if(away && league_table[abs(team_b)-1][slot] != (team_a+1)) {
                printf("%dは%d日目に%dと戦うが, %dは%dと戦う\n", team_a+1,slot+1,abs(team_b),abs(team_b),abs(league_table[abs(team_b)-1][slot]));
                return false;
            }
            if(not away && league_table[abs(team_b)-1][slot] != -(team_a+1)) {
                printf("%dは%d日目に%dと戦うが, %dは%dと戦う\n", team_a+1,slot+1,abs(team_b),abs(team_b),abs(league_table[abs(team_b)-1][slot]));
                return false;
            }

            //At Most
            if(continuous > 3) {
                printf("%dの%d日目に4連続%sです(1-indexed)\n", team_a+1, slot+1, away ? "Away" : "Home");
                return false;
            }
        }
    }

    return true;
}

int calc_cost_of_team(vector<vector<int>> const& league_table, vector<vector<int>> const& dist_matrix, int team1){
    int cost = 0;
    int move_from = team1;
    for(int date = 0; date < league_table[team1].size(); date++){
        int team2 = abs(league_table[team1][date]) - 1, move_to;
        if(league_table[team1][date] > 0) move_to = team1; //Aのホームで
        else move_to = team2; //Bのホームで
        
        cost += dist_matrix[move_from][move_to];
        move_from = move_to;
    }
    cost += dist_matrix[move_from][team1]; 
    return cost;
}

int calc_TTP_cost(vector<vector<int>> const& league_table, vector<vector<int>> const& dist_matrix){
    int cost = 0;
    for(int team=0; team < league_table.size(); team++){
        cost += calc_cost_of_team(league_table, dist_matrix, team);
    }
    return cost;
}


bool AtMost_ok(vector<vector<int>>const& league_table, int team, int slot_i){
    int slot_num = league_table[0].size();
    for(int slot = max(0, slot_i-3); slot <= slot_i; slot++){
        if(slot+3 >= slot_num) break;

        int home_away_sum = 0;
        for(int i=0; i<4; i++) home_away_sum += (league_table[team][slot + i] > 0);
        if( home_away_sum == 4 or home_away_sum == 0) return false; //4連続Home or Away
    }
    return true;
}

bool NoRepeater_ok(vector<vector<int>>const& league_table, int team, int slot){
    int slot_num = league_table[0].size();
    if(slot > 0){
        if(abs(league_table[team][slot-1]) == abs(league_table[team][slot])) return false;
    }
    if(slot < slot_num - 1){
        if(abs(league_table[team][slot]) == abs(league_table[team][slot+1])) return false;
    }
    return true;
}

//teamがbeforeと戦って次の試合でnowと戦うときのコスト
int get_cost1(int team, int before, int now, vector<vector<int>>const& dist_matrix){
    int move_from;
    if(before < 0) move_from = abs(before) - 1;
    else move_from = team;

    int move_to;
    if(now < 0) move_to = abs(now) - 1;
    else move_to = team;

    return dist_matrix[move_from][move_to];
}

//自拠点にいるteamが次の試合でrivalと戦うときのコスト
int get_cost2(int team, int rival, vector<vector<int>>const& dist_matrix){
    int move_from = team;

    int move_to;
    if(rival < 0) move_to = abs(rival) - 1;
    else move_to = team;

    return dist_matrix[move_from][move_to];
}

int get_cost(int team, int slot, vector<vector<int>> const& league_table, vector<vector<int>> const& dist_matrix){
    int cost = 0;
    int slot_num = league_table[0].size();
    
    //(slot-1, slot)間のコスト
    if(slot > 0) cost += get_cost1(team, league_table[team][slot-1], league_table[team][slot], dist_matrix);
    else cost += get_cost2(team, league_table[team][slot], dist_matrix);
    
    //(slot, slot+1)間のコスト
    if(slot < slot_num -1) cost += get_cost1(team, league_table[team][slot], league_table[team][slot+1], dist_matrix);
    else cost += get_cost2(team, league_table[team][slot], dist_matrix);

    return cost;
}

//チームAとチームBが戦うスロット(2つ)をペアで返す関数
pair<int,int> get_slots_AvsB(vector<vector<int>> const& league_table, int team1, int team2){
    int slot1 = -1, slot2 = -1;
    int slot_num = league_table[0].size();
    for(int slot=0; slot<slot_num; slot++){
        if(abs(league_table[team1][slot]) == team2 + 1){
            if(slot1 < 0) slot1 = slot;
            else{ slot2 = slot; break; }
        }
    }

    return make_pair(slot1, slot2);
}

//teamのslotにおける相手を取得する(0-indexed)
int get_rival(vector<vector<int>> const& league_table, int team, int slot){
    return abs(league_table[team][slot]) - 1;
}

//teamのslotにおいて、戦う相手がteamと戦うようにleague_tableを修正
void set_rival_slot(vector<vector<int>>& league_table, int team, int slot){
    int rival = get_rival(league_table, team, slot);

    if(league_table[team][slot] > 0) league_table[rival][slot] = -(team+1);
    else league_table[rival][slot] = (team+1);
}