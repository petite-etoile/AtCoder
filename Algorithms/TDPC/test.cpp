#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long INF = 1LL<<60;
void add(long long &a, long long b) { a += b; if (a >= INF) a = INF; }

int main() {
    string S; long long K;
    cin >> S >> K;
    int n = (int)S.size();

    // DP
    vector<vector<long long> > dp(n+1, vector<long long>(26, 0));
    dp[n-1][S[n-1] - 'a'] = 1;
    for (int i = n-2; i >= 0; --i) {
        for (int c = 0; c < 26; ++c) {
            if (c != (int)(S[i] - 'a')) {
                add(dp[i][c], dp[i+1][c]);
            }
            else {
                add(dp[i][c], 1); // c を採用した後は何も採用しないケース
                for (int c2 = 0; c2 < 26; ++c2)
                    add(dp[i][c], dp[i+1][c2]);
            }
        }
    }

    // 復元
    long long sum = 0;
    for (int c = 0; c < 26; ++c) add(sum, dp[0][c]);

    // 部分文字列の個数が K に満たない場合
    if (sum < K) {
        cout << "Eel" << endl;
    }
    else {
        string res = "" ;
        for (int i = 0; i < n; ++i) {
            // 次の文字が何かを決める
            int j;
            for (j = 0; j < 26; ++j) {
                if (K - dp[i][j] <= 0) break;
                K -= dp[i][j];
            }
            char c = 'a' + j; // 次の文字は c
            res += c;
            --K; // c をとって終了し、残りは何も取らないような文字列を除外
            if (K <= 0) break; // K <= 0  になるなら c で終了
            while (S[i] != c) ++i;
            
        }
        cout << res << endl;
    }
}