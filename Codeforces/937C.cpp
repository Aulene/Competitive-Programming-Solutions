#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

ld k, d, t, i, j;
ld a, b, c, e, f, g, h;
ld ans, ans1, ans2, check;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		cin >> k >> d >> t;

		a = ceil(k / d);
	   	b = a * d;
	   	c = b - k;
	   	e = 1 / (2 * t);
	   	e *= c;
	   	f = k / t;
	   	g = e + f;

	   	ans1 = floor(1.0 / g);
	   	ans = (ans1 * b);
	   	ans2 = ans1 * g;

	   	check = 1.0 - ans2;

	   	if(check <= 0.000000000) {}
	   	else if(check <= f)
		   	{
		   		ans += (((ld) check / f) * k);
		   		check = 0.0;
		   	}
	   	else if (check > f)
		   	{
		   		ans += k;
		   		check -= f;
		   	}

	   	if(check <= 0.000000000) {}
	   	else if(check <= e)
		   	{
		   		ans += (((ld) check / e) * c);
		   		check = 0.0;
		   	}

	   	cout << fixed << setprecision(11) << ans << endl;
		return 0;
	}