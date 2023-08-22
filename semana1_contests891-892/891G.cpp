#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
const ll MX = 3e5 + 2;
const ll MOD = 998244353;
const ll INF = 1e18;
const double INF_DOUBLE = 1e18 / 1.0;
const double EPS = 1e-8;
const double PI = acos(-1.0);

ll tamanio[MX], lider[MX];
ll find_lider(ll nodo) {
    if (lider[nodo] == nodo) {
        return nodo;
    }
    lider[nodo] = find_lider(lider[nodo]);
    return lider[nodo];
}
void join(ll nodo_a, ll nodo_b) {
    nodo_a = find_lider(nodo_a);
    nodo_b = find_lider(nodo_b);
    if (nodo_a != nodo_b) {
        if (tamanio[nodo_a] >= tamanio[nodo_b]) {
            tamanio[nodo_a] += tamanio[nodo_b];
            lider[nodo_b] = nodo_a;
        } else {
            tamanio[nodo_b] += tamanio[nodo_a];
            lider[nodo_a] = nodo_b;
        }
    }
}

ll rest_mod(ll a, ll b, ll c) {
    return ((a % c) - (b % c) + c) % c;
}
ll sum_mod(ll a, ll b, ll c) {
    return (a % c + b % c) % c;
}
ll mult_mod(ll a, ll b, ll c) {
    return (((a % c) * (b % c)) % c);
}
ll fast_pow(ll a, ll b, ll c) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1 == 1) ans = mult_mod(ans, a, c);
        a = mult_mod(a, a, c);
        b >>= 1;
    }
    return ans;
}
ll mod_inverse(ll a, ll c) {
    return fast_pow(a, MOD - 2, c);
}
ll divide_mod(ll a, ll b, ll c) {
    return mult_mod(a, mod_inverse(b, c), c);
}

vector<pair<pair<ll, ll>, ll>> connections;
int main() {
    inic;
    inic2;
    ll t;
    cin >> t;
    while (t--) {
        connections.clear();
        ll n, s;
        cin >> n >> s;
        Rep1(i, n - 1) {
            ll a, b, w;
            cin >> a >> b >> w;
            connections.pb({{w, a}, b});
        }
        sort(connections.begin(), connections.end());
        fill(tamanio, tamanio + n + 1, 1);
        iota(lider, lider + n + 1, 0);
        ll lineas = 0;
        ll rp = 0;
        for (ll i = 0; i < connections.size(); i++) {
            ll component_a = connections[i].first.second;
            ll component_b = connections[i].second;
            ll lineas_actual =
                tamanio[find_lider(component_a)] * tamanio[find_lider(component_b)] - 1;
            ll aumento = s - connections[i].first.first - 1;

            ll edges_add =
                rest_mod(fast_pow(sum_mod(2, aumento, MOD), lineas_actual, MOD), 1, MOD);
            rp = sum_mod(rp, mult_mod(edges_add, sum_mod(rp, 1, MOD), MOD), MOD);
            join(component_a, component_b);
        }
        cout << sum_mod(rp, 1, MOD) << endl;
    }

    return 0;
}
