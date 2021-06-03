#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (long long i = 0; i < n; i++)
#define REP1(i, n) for (long long i = 1; i <= n; i++)
#define PER(i, n) for (long long i = ((n)-1); i >= 0; i--)
#define PER1(i, n) for (long long i = (n); i > 0; i--)
#define FOR(i, a, b) for (long long i = (a); i < (b); i++)
#define FORE(i, a, b) for (long long i = (a); i <= (b); i++)
#define ITE(arr) for (auto ite = (arr).begin(); ite != (arr).end(); ite++)
#define ALL(a) (a.begin()), (a.end())
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, 0xff, sizeof(a))
#define YNPRT(b) cout << ((b) ? "Yes" : "No") << endl
#define REV(arr) reverse(ALL(arr))
#define mod(x) ((x) % MOD)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF_INT = 2147483647;
const ll INF_LL = 9223372036854775807LL;
const ull INF_ULL = 18446744073709551615Ull;
const ll P = 92540646808111039LL;
const int Move[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
const int Move_[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};

//---------------------
#define MAXN 100000
ll MOD = 1;
//---------------------

using namespace std;

struct mat
{
    ll m[3][3];
    mat()
    {
        memset(m, 0, sizeof(m));
    }
    mat(ll a00, ll a01, ll a02,
        ll a10, ll a11, ll a12,
        ll a20, ll a21, ll a22)
    {
        m[0][0] = a00;
        m[0][1] = a01;
        m[0][2] = a02;
        m[1][0] = a10;
        m[1][1] = a11;
        m[1][2] = a12;
        m[2][0] = a20;
        m[2][1] = a21;
        m[2][2] = a22;
    }
} src, ans, unit;

void init()
{
    memset(unit.m, 0, sizeof(unit.m));
    memset(src.m, 0, sizeof(src.m));
    unit.m[0][0] = unit.m[1][1] = unit.m[2][2] = 1;
}

mat operator*(mat m1, mat m2)
{
    mat t;
    ll r;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            r = 0;
            for (int k = 0; k < 3; k++)
            {
                r = mod(r * 1ll + mod(mod(m1.m[i][k]) * 1ll * mod(m2.m[k][j])));
            }
            t.m[i][j] = r;
        }
    }
    return t;
}

mat quick_pow(ll x)
{
    mat t = unit;
    while (x)
    {
        if (x & 1)
        {
            t = t * src;
        }
        src = src * src;
        x >>= 1;
    }
    return t;
}

ll l, a, b, m, maxelement;
ll numketa[19];
int main()
{
    init();
    cin >> l >> a >> b >> m;
    MOD = m;
    numketa[0] = 0;
    ll lastmaxid = -1;
    /*
    REP1(i,18){
      ll maxnum=pow(10,i)-1;
      ll lastmaxnum=ll(pow(10,i-1))-1;
      ll maxid=min(l-1,(maxnum-a)/b-((maxnum-a<0)?1:0));
      ll minid=max(ll(0),(lastmaxnum-a)/b-((lastmaxnum-a<0)?1:0)+1);
      if(minid>=l || maxid<0) continue;
      if(maxid<minid) continue;
      if(lastmaxid>=maxid) continue;
      lastmaxid=maxid;
     	numketa[i]=maxid-minid+1; 
    }
    REP(i,19) cout<<i<<" - "<<numketa[i]<<endl;*/
    for (int i = 18; i >= 1; i--)
    {
        ll maxnum = pow(10, i) - 1;
        ll minnum = pow(10, i - 1) - 1;
        if (maxnum - a < 0)
            break;
        ll maxsum = min(l, (maxnum - a) / b + 1);
        ll minsum = (minnum - a) < 0 ? 0 : min(l, (minnum - a) / b + 1);
        numketa[i] = maxsum - minsum;
    }

    ll ret = 0;
    ll s = a % MOD;
    mat finalm = unit;
    mat vecm(0, s, 1, 0, 0, 0, 0, 0, 0);
    REP(i, 19)
    {
        if (!numketa[i])
            continue;
        init();
        src = mat(
            ll(pow(10, i)) % MOD, 0, 0,
            1, 1, 0,
            0, b % MOD, 1);
        mat curm = quick_pow(numketa[i]);
        vecm = vecm * curm;
    }
    /*REP(i,3){
 		REP(j,3){
 			cout<<vecm.m[i][j]<<"      ";
 		}
 		cout<<endl;
 	}*/
    cout << vecm.m[0][0] % MOD << endl;
}
