
#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
const int MOD = (int)1e9 + 7;
const ll INF = 1LL << 60;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
template <typename T>
ostream& operator<<(ostream& os, vector<T> &V){
    int N = V.size();
    REP(i,N){
        os << V[i];
        if (i!=N-1)
            os << " ";
    }
    os << "\n";
    return os;
}
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<pair<int,int>> A(N);
    REP(i,N){
        cin >> A[i].first;
        A[i].second=i;
    }
    sort(ALL(A),greater<pair<int,int>>() );

    int ans=N;
    int cnt =0;
    REP(i,N){
        ans+= cnt*A[i].first;
        cnt++;  
    }
    cout << ans << endl;;

    vector<int> B(N);
    REP(i,N){
        int index = A[i].second + 1;
        B[i] = index;
    }
    cout << B;

    return 0;
}