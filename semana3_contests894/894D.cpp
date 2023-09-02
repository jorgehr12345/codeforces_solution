#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
const ll MX = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double INF_DOUBLE = 1e18 / 1.0;
const double EPS = 1e-8;
const double PI = acos(-1.0);

ll f(ll num) {
    return num * (num - 1) / 2;
}

int main() {
    inic;
    inic2;
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll inicio_binary_search = 1, fin_binary_search = 2e9;
        while (inicio_binary_search < fin_binary_search) {
            ll med = (inicio_binary_search + fin_binary_search) / 2;
            if (f(med) >= n) {
                fin_binary_search = med;
            } else {
                inicio_binary_search = med + 1;
            }
        }
        if (f(inicio_binary_search) == n) {
            cout << inicio_binary_search << endl;
        } else {
            inicio_binary_search--;
            cout << n - f(inicio_binary_search) + inicio_binary_search << endl;
        }
    }
    return 0;
}