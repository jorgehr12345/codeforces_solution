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
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double INF_DOUBLE = 1e18 / 1.0;
const double EPS = 1e-8;
const double PI = acos(-1.0);

vector<ll> arreglo_a, arreglo_b;
vector<pair<ll, ll>> resta_arreglos_posiciones;
int main() {
    inic;
    inic2;
    ll t;
    cin >> t;
    while (t--) {
        arreglo_a.clear();
        arreglo_b.clear();
        resta_arreglos_posiciones.clear();
        ll n;
        cin >> n;
        Rep1(i, n) {
            ll l;
            cin >> l;
            arreglo_a.pb(l);
        }
        Rep1(i, n) {
            ll l;
            cin >> l;
            arreglo_b.pb(l);
            resta_arreglos_posiciones.pb({arreglo_a[i - 1] - arreglo_b[i - 1], i});
        }
	//Ordenamiento de acuerdo a la resta de cada posicion de los arreglos
        sort(resta_arreglos_posiciones.begin(), resta_arreglos_posiciones.end());
        ll mayor = resta_arreglos_posiciones[resta_arreglos_posiciones.size() - 1].first;
        ll cant = 0;
        vector<ll> rp;
        for (ll i = resta_arreglos_posiciones.size() - 1; i >= 0; i--) {
            if (resta_arreglos_posiciones[i].first == mayor) {
                cant++;
                rp.pb(resta_arreglos_posiciones[i].second);
            }
        }
        sort(rp.begin(), rp.end());
        cout << cant << endl;
        for (ll i = 0; i < rp.size(); i++) {
            cout << rp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}