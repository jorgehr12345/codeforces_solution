#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define pf push_front
#define debug(x) cout << #x << " = " << x << '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> Nums(n); // number - index
        ll sum1 = 0, sum2 = 0;

        for (ll i = 0; i < n; i++) {
            ll a;
            cin >> a;
            sum2 += a;
            Nums[i].first = a;
            Nums[i].second = i;
        }
        sort(Nums.begin(), Nums.end());

        vl ans(n);
        for (ll i = 0; i < n; i++) {
            sum2 -= Nums[i].first;
            sum1 += Nums[i].first;
            ans[Nums[i].second] = n + Nums[i].first * (2 * (i + 1) - n) - sum1 + sum2;
        }
        for (auto answer : ans) {
            cout << answer << ' ';
        }
        cout << '\n';
    }

    return 0;
}