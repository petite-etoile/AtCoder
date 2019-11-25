#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD = (int)1e9 + 7;
const int INF = 1LL << 60;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";

vector<int> z_algorithm(string S){
    int N = S.size();
    vector<int> A(N,0);
    A[0] = N;
    int left=1;
    int len = 0;
    while(left < N){
        while(left+len < N && S[len]==S[left+len]){
            len++;
        } //文字列の頭からと、leftからの文字列の共通接頭辞の長さを求める
        A[left] = len;
        if(len == 0){
            left ++;
            continue;
        }
        int k=1;
        while(left + k < N && k + A[k] < len){
            A[left+k] = A[k];
            k++;
        }

        left += k;
        len-=k;
    }
    return A;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    string S;
    cin >> N >> S;
    vector<int> res;
    int ans = 0;
    REP(i,N){
        string sub = S.substr(i);
        res = z_algorithm(sub);
        REP(j,res.size()){
            int len = res[j];
            ans = max(ans, min(len, j));
        }
    }
    cout << ans << endl;

}
/*
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define int long long
typedef long long ll;
const int MOD = (int)1e9 + 7;
const int INF = 1LL << 60;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
void print(T &x) { cout << x << "\n"; }

int dp[5005][5005];
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    string S;
    cin >> N >> S;
    cout << "a" << 'a';
    exit(0);
    for(int i=N-1; i>=0;i--){
        for(int j=N-1;j>i;j--){
            if (S[i] == S[j]){
                dp[i][j] = dp[i+1][j+1] + 1;
            }
        }
    }
    int ans = 0;
    REP(i,N)REP(j,N){
        int len = min(j-i, dp[i][j]);
        ans = max(ans,len);
    }
    cout << ans << endl;

    return 0;
}




int N;
string S;
bool is_ok(int l){
    for(int i=0;i < N-l+1; i++){
        string sub = S.substr(i,l);
        string sub2 = S.substr(i+l,N);
        if (sub2.find(sub) != string::npos){
 
            return true;
        }
    }
    return false    ;
}
int bis (int ok,int ng){
    while(abs(ok-ng) > 1){
        int mid = (ok+ng)/2;
        if (is_ok(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ok;
}
int main()
{
	cin >> N;
    cin >> S;
    int ans = bis(0,N);
    cout << ans << endl;
}

*/