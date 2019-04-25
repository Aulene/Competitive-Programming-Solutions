#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
#define ll long long
#define ull unsigned long long
#define f first
#define s second
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define FOR(i, n, x) for(int i = x; i < n; i++)
#define OUT(a, s, e) FOR(i, e, s) cout << a[i] << ' '
 
using namespace std;
 
int main() {
	ull a, b; cin >> a >> b;
	ull ans = 0;
	ull rez = (a * b) / __gcd(a, b);
	FOR(i, 1e7, 1)
	{
		ull x = a + i, y = b + i;
		ull lcm = (x * y) / __gcd(x, y);
		if (lcm < rez)
		{
			rez = lcm;
			ans = i;
		}
	}
	cout << ans;
	return 0;
}