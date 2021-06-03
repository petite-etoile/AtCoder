/*
　　　∫ ∫ ∫
　　　ノヽ
　　（＿　 ）
　（＿　　　 ）
（＿＿＿＿＿＿ ）
　ヽ(´･ω･)ﾉ　
　　 |　 /
　　 UU
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using P = pair<ll, ll>;
typedef vector<int> vi;
const int MOD = (int)1e9 + 7;
const ll INF = 1LL << 62;
const int inf = 1<<30;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = s; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
#define mp make_pair
template <typename T>
ostream& operator<<(ostream& os, vector<T> &V){
    int N = V.size();
    REP(i,N){
        os << V[i];
        if (i!=N-1) os << " ";
    }
    os << "\n";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, pair<T,T> const&P){
    os << P.first;
    os << " ";
    os << P.second;
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
template <typename T>
ostream& operator<<(ostream& os, deque<T> &q){
    for(auto it=q.begin();it<q.end();it++){
        os<<*it;
        os<<" ";
    }
     os<<endl;
    return os;
}
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
//fixed<<setprecision(10)<<ans<<endl;



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,Q,S,T;
    cin >> N>>Q>>S>>T;
    vector<ll> A(N+1);
    vector<ll> B(N);
    REP(i,N+1){
        cin >> A[i];
    }
    REP(i,N){
        B[i] = A[i+1]-A[i];
    }

    ll ans=0;
    for(auto b:B){
        if(b>0) ans+=b*S;
        else ans+=b*T;
    }
    ll l,r,h;
    REP(i,Q){
        cin>>l>>r>>h;
        if ((B[l-1]!=0) && (B[l-1]+h!=0) && !((B[l-1]<0) ^ (B[l-1]+h<0)))
            if (B[l-1]>=0)
                ans+=h*S;
            else
                ans+=h*T;
        else{
            if (B[l-1]<0){
                ans+=abs(B[l-1])*T;
                ans+=abs(B[l-1]+h)*S;
            }
            else if (B[l-1]>0){
                ans-=abs(B[l-1])*S;
                ans-=abs(B[l-1]+h)*T;
            }
            else{
                if (h>0)
                    ans+=h*S;
                else
                    ans+=h*T;
            }
        }
        h*=-1;
        if (r<B.size()){
            //((B[l-1]!=0) && (B[l-1]+h!=0)   (B[l-1]<0) ^ (B[l-1]+h<0))
            if ((B[r]!=0)&&(B[r]+h!=0)&&((B[r]<0) ^ ((B[r]+h)>0)))
                if (B[r]>=0)
                    ans+=h*S;
                else
                    ans+=h*T;
            else{
                if (B[r]>0){
                    ans-=abs(B[r])*S;
                    ans-=abs(B[r]+h)*T;
                }
                else if (B[r]){
                    ans+=abs(B[r])*T;
                    ans+=abs(B[r]+h)*S;
                }else{
                    if (h>0)
                        ans+=h*S;
                    else
                        ans+=h*T;
                }
            }
        }
            
        h*=-1;
        B[l-1] += h;
        if (r<B.size())
            B[r] -= h;
        cout << -ans << endl;
    }
}