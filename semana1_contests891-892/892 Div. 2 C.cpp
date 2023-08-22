#include <bits/stdc++.h>
using namespace std;
using Long = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = i + 1;
        for (int i = 0; i < n; i++) {
            vector<int> b = a;
            reverse(b.begin() + i, b.end());
            int cur = 0, mx = 0;
            for (int j = 0; j < n; j++) {
                cur += b[j] * (j + 1);
                mx = max(mx, b[j] * (j + 1));
            }
            ans = max(ans, cur - mx);
        }
        cout << ans << endl;
    }
    return 0;
}
