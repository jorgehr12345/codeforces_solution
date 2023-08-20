#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define pf push_front
#define debug(x) cout << #x << " = " << x << '\n'

ll new_sqrt(ll num) {
    ll l = 0, r = 3e9;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (m * m <= num) l = m;
        else r = m;
    }
    if (l * l != num) return -1;
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        map<ll, ll> cont;
        for (ll i = 0; i < n; i++) {
            ll a;
            cin >> a;
            cont[a]++;
        }
        ll q;
        cin >> q;
        while (q--) {
            // w^2 - x*w + y= 0
            ll x, y;
            cin >> x >> y;
            ll Disc = x * x - 4 * y;
            if (Disc < 0) cout << 0 << ' ';
            else {
                ll sqrt_Disc = new_sqrt(Disc);
                if (sqrt_Disc == -1) {
                    cout << 0 << ' ';
                    continue;
                }
                if ((x + sqrt_Disc) % 2 != 0) {
                    cout << 0 << ' ';
                    continue;
                }
                ll w1 = (x + sqrt_Disc) / 2, w2 = (x - sqrt_Disc) / 2;
                // TLE using count:
                // ll cont_w1 = count(v.begin(), v.end(), w1),
                //    cont_w2 = count(v.begin(), v.end(), w2);
                if (w1 == w2) cout << cont[w1] * (cont[w1] - 1) / 2 << ' ';
                else cout << cont[w1] * cont[w2] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}