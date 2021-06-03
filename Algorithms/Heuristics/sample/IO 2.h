#pragma region IO
using namespace std;
#define debug(x) cerr << #x << ": " << x << "\n";
template <typename T>
ostream& operator<<(ostream& os, const vector<T> &V){
    int N = V.size();
    for(int i=0; i<N; i++){
        os << V[i];
        if (i!=N-1) os << " ";
    }
    os << "\n";
    return os;
}
template <typename T,typename S>
ostream& operator<<(ostream& os, pair<T,S> const&P){
    os << "(";
    os << P.first;
    os << " , ";
    os << P.second;
    os << ")";
    return os;
}
template <typename T,typename S,typename U>
ostream& operator<<(ostream& os, tuple<T,S,U> const& P){
    os << "(";
    os << get<0>(P);
    os << ", ";
    os << get<1>(P);
    os << ", ";
    os << get<2>(P);
    os << ")";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T> &S){
    auto it=S.begin();
    while(it!=S.end()){
        os << *it;
        os << " ";
        it++;
    }
    os << "\n";
    return os;
}





vector<string> split(string S, char key_word = ' '){
    string now = "";
    vector<string> res;
    S += key_word; //番兵
    for(auto s:S){
        if(s==key_word){
            if(now != ""){
                res.emplace_back(now);
                now = "";
            }
        }else{
            now += s;
        }
    }
    return res;
}

vector<int> cast_to_int(vector<string> Sv){
    vector<int> res;
    for(auto S:Sv) res.emplace_back(stoi(S));
    return res;
}

vector<vector<int>> input_matrix(string file_path){
    ifstream ifs(file_path);
    assert(!ifs.fail());
    string str;
    vector<vector<int>> matrix;
    while(getline(ifs, str)){
        vector<string> tmp = split(str, ' ');
        vector<int> row = cast_to_int(tmp);
        matrix.emplace_back(row);
    }
    return move(matrix);
}

vector<vector<int>> input_league_table(string file_path){
    ifstream ifs(file_path);
    assert(!ifs.fail());
    string str;
    vector<vector<int>> table;
    while(getline(ifs, str)){
        vector<string> tmp = split(str, ',');
        vector<int> row = cast_to_int(tmp);
        table.emplace_back(row);
    }
    return move(table);
}

string join(vector<int> const& V, char key = ','){
    string res;
    for(int i=0; i<V.size(); i++){
        if(i) res += key;
        res += to_string(V[i]);
    }
    return res;
}

void output_schedule(vector<vector<int>> const& table, string file_path){
    ofstream ofs(file_path);
    for(auto row:table){
        ofs << join(row) << "\n";
    }
}
#pragma endregion