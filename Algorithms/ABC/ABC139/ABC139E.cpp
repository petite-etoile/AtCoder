#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <fstream>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

char ToUpper(char cX) { return toupper(cX); }
char Tolower(char cX) { return tolower(cX); }


const long long INF = 1LL << 60;
const long long MOD = 1000000007LL;
const long long MAX = 500000LL;
using namespace std;
typedef unsigned long long ull;
typedef  long long ll;
using T = tuple<ll, ll, ll>;

int main()
{
    int N;
	cin >> N ;
    vector<vector<int>> A(N, vector<int>(N));
 
    // 入力 (2重ループを用いる)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A.at(i).at(j);
        }
    }

    indexes = vector<int>(N,0);
    int cnt = 0;
    set<int>match;
    for(int i=0; i<N*N; N++){
        int update = 0;
        set<int>today_players;
        for(int k=0;k<N;k++){
            int index = indexes[k];
            if(index >= N-1){
                continue;
            }
            int rival = A[k][index];
            decltype(match)::iterator it = match.find((k,rival));
            if (it != s.end()) {
                // 発見した
        }

    }



	g.resize(N);
	p = vector<ll>(N, 0);
	res = vector<ll>(N, 0);
	for (ll i = 0; i < N - 1; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (ll i = 0; i < Q; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		p[a] += b;
	}

	dfs(0, -1, 0);
	for (ll i = 0; i < N; i++) {
		cout << res[i];
		if (i == N - 1)
			cout << endl;
		else
			cout << " ";
	}
	return 0;

}

