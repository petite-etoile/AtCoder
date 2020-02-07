#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>

using namespace std;

/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define ALL(x)					(x).begin(),(x).end()
#define REP(i, n)				for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n)			for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF						2e9
#define MOD						(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)				(((((x))+((n)-1))/n))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)				(((((x))+((n)-1))/n)*n)		/* Nの倍数に切り上げ */
#define FloorN(x, n)			((x)-(x)%(n))				/* Nの倍数に切り下げ */
#define IsOdd(x)				(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)				(!IsOdd((x)))						
#define M_PI					3.14159265358979323846
typedef long long				ll;
typedef pair<ll, ll>			P;

/*-----------------------------------------------------------------------------
　処理
 -----------------------------------------------------------------------------*/
ll execOne(ll n, ll keta)
{
	ll ans = 0;

	if (keta == 1) {
		return n;
	}
	while (0 != n) {
		ans += n % keta;
		n /= keta;
	}
	return ans;
}

int main()
{
	ll n, s;
	cin >> n >> s;

	if (s == n) {
		cout << n + 1 << endl;
		return 0;
	}
	if (s > n) {
		cout << -1 << endl;
		return 0;
	}
	
	for (ll b = 2; b <= sqrt(n); b++) {
		if (s == execOne(n, b)) {
			cout << b << endl;
			return 0;
		}
	}
	
	// pb + q = n;
	//  p + q = s;
	//p(b - 1) = n - s;
	ll ns = n - s;
	for (ll p = sqrt(n); p >= 1; p--) {
		if (ns % p == 0) {
			ll b = ns / p + 1;
			if (s == execOne(n, b)) {
                cout << p << endl;
				cout << b << endl;
				return 0;
			}
		}
	}

	cout << -1 << endl;
	return 0;
}

