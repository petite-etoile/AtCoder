#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

int mod;
struct mint
{
    ll x;
    mint(ll x = 0) : x(x % mod) {}
    mint &operator+=(const mint a)
    {
        (x += a.x) %= mod;
        return *this;
    }
    mint &operator-=(const mint a)
    {
        (x += mod - a.x) %= mod;
        return *this;
    }
    mint &operator*=(const mint a)
    {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const
    {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const
    {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const
    {
        mint res(*this);
        return res *= a;
    }
};

ll b, ten;

mint pow_(mint x, ll t)
{
    if (t == 0)
        return 1;
    if (t % 2 == 1)
    {
        return pow_(x, t - 1) * x;
    }
    else
    {
        mint y = pow_(x, t / 2);
        return y * y;
    }
}

mint f(ll l)
{
    if (l == 0)
        return 0;
    if (l % 2 == 1)
    {
        ll pl = l - 1;
        mint x = f(pl);
        return x * ten + 1;
    }
    else
    {
        ll pl = l / 2;
        mint x = f(pl);
        return x * pow_(ten, pl) + x;
    }
}
mint g(ll l)
{
    if (l == 0)
        return 0;
    if (l % 2 == 1)
    {
        ll pl = l - 1;
        mint x = g(pl);
        return x * ten + mint(b) * pl;
    }
    else
    {
        ll pl = l / 2;
        mint x = g(pl);
        return x * pow_(ten, pl) + x + mint(b) * pl * f(pl);
    }
}

int main()
{
    ll L, a;
    cin >> L >> a >> b >> mod;
    ll last = a + b * (L - 1);
    mint ans = 0;
    ten = 10;
    for (int i = 1; i <= 18; ++i, ten *= 10)
    {
        ll l = ten / 10, r = ten - 1;
        //cerr << l << " " << r << endl;
        if (last < l)
            continue;
        if (a > r)
            continue;
        ll na = 0; // 初項
        ll nl = 0; // 長さ
        {
            if (a >= l)
            {
                cout << "a" << endl;
                na = a;
            }
            else
            {
                na = ((l - a) + (b - 1)) / b * b + a;
                na = min(na, last);
            }
            //cerr << i << " " << na << endl;
        }
        {
            ll nlast = 0;
            if (last <= r)
                nlast = last;
            else
            {
                nlast = (r - a) / b * b + a;
            }
            nl = (nlast - na) / b + 1;
        }
        // cerr << i << ' ' << na << " " << nl << endl;
        //cerr << "i" << i << endl;
        ans *= pow_(ten, nl);
        cerr << "popopoo" << pow_(ten, nl).x << "       N  " << nl << endl;
        cerr << "          " << ans.x << endl;
        ans += f(nl) * na;
        ans += g(nl);
        cerr << ans.x << endl;

        // cerr << f(nl).x << endl;
        // cerr << g(nl).x << endl;
        // cerr << ans.x << endl;
    }
    cout << ans.x << endl;
    return 0;
}
