#include <bits/stdc++.h>
using namespace std;
using Long = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, d;
        cin >> n >> m >> d;
        vector<int> s(m);
        for (auto &x : s) cin >> x;
        int pre_index = 1, cookies = 1; // en el indice 1
        if (s[0] == 1) {
            pre_index = 0;
            cookies = 0;
        } // correccion para cuando el primer vendedor esta en el indice 1
        for (auto &x : s) {
            int cookies_between = (x - pre_index - 1) / d;
            cookies += cookies_between;
            pre_index = x;
            cookies++;
        }
        // calcular el numero de cookies desde s[m-1] hasta n
        int cookies_between = (n - pre_index) / d;
        cookies += cookies_between;
        // calcular el numero de opciones de vendedores a eliminar
        int cookies_before, cookies_after, cookies_without_seller, num_options = 0;
        for (int i = 1; i < m - 1; i++) {
            cookies_before = (s[i] - s[i - 1] - 1) / d;
            cookies_after = (s[i + 1] - s[i] - 1) / d;
            cookies_without_seller = (s[i + 1] - s[i - 1] - 1) / d;
            if (cookies_without_seller < cookies_before + cookies_after + 1) num_options++;
        }
        // Para desde el indice 1 hasta el s[0]
        if (s[0] != 1) {
            cookies_before = (s[0] - 2) / d;
            cookies_after = (s[1] - s[0] - 1) / d;
            cookies_without_seller = (s[1] - 2) / d;
            if (cookies_without_seller < cookies_before + cookies_after + 1) num_options++;
        }
        // Para desde el indice s[m-1] hasta el n
        cookies_before = (s[m - 1] - s[m - 2] - 1) / d;
        cookies_after = (n - s[m - 1]) / d;
        cookies_without_seller = (n - s[m - 2]) / d;
        if (cookies_without_seller < cookies_before + cookies_after + 1) num_options++;
        // Para dar la respuesta
        if (num_options == 0) cout << cookies << " " << m << "\n";
        else cout << cookies - 1 << " " << num_options << "\n";
    }
    return 0;
}
