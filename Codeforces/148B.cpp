#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;

    if (vd <= vp) {
        cout << 0;
        return 0;
    }

    int p = vp*t, d = 0, ans = 0;
    while (p < c) {
        if (p == c)
            break;
        if (d >= p) {
            ans++;
            p += (int) (f)*vp;
            p += ((int) ((double) (d / vd))) * vp;
            d = 0;
            continue;
        }
        d += vd;
        p += vp;
    }

    cout << ans;



    return 0;
}