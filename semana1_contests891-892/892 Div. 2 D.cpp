#include <bits/stdc++.h>
using namespace std;
using Long = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n); // contains l and b only
        int l, r, a, b;
        for (int i = 0; i < n; i++) {
            cin >> l >> r >> a >> b;
            v[i] = {l, b};
        }
        // algorithm
        sort(v.begin(), v.end());
        // first optimization
        for (int i = 1; i < n; i++) v[i].second = max(v[i].second, v[i - 1].second);
        // second optimization
        for (int i = n - 2; i >= 0; i--) {
            if (v[i].second >= v[i + 1].first) v[i].second = v[i + 1].second;
        }
        // data insertion
        int q;
        cin >> q;
        while (q--) {
            int x;
            cin >> x;
            if (x < v[0].first) {
                cout << x << " ";
            } else {
                int low = 0, high = n, mid;
                while (low < high - 1) {
                    mid = low + (high - low) / 2;
                    if (v[mid].first <= x) {
                        low = mid;
                    } else {
                        high = mid;
                    }
                }
                cout << max(x, v[low].second) << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
