#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
const ll MX = 2e5 + 2;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double INF_DOUBLE = 1e18 / 1.0;
const double EPS = 1e-8;
const double PI = acos(-1.0);

set<ll> valores_usados_permutacion;
int main() {
    inic;
    inic2;
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        Rep1(i, n) {
            if (valores_usados_permutacion.find(i) == valores_usados_permutacion.end()) {
                ll valores__posibles_i = i;
                while (valores__posibles_i <= n) {
                    valores_usados_permutacion.insert(valores__posibles_i);
                    cout << valores__posibles_i << " ";
                    valores__posibles_i *= 2;
                }
            }
        }
        valores_usados_permutacion.clear();
        cout << endl;
    }
    return 0;
}