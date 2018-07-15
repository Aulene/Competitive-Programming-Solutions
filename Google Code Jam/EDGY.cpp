#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 100000000000007
#define double long double
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < pair <double, double> > vs;
int n;
double p;
double ansdiff, ans;

void recur(double perimeter, int idx)
{
	if(idx >= n)
		{
			if(perimeter <= p) {
				double diff = p - perimeter;
				if(diff < ansdiff) {
					ans = perimeter;
					ansdiff = diff;
				}
			}

			return;			
		}

	double px, h, w, w2, h2, hyp;
	h = vs[idx].f, w = vs[idx].s;

	w2 = (double) w / 2;
	h2 = (double) h / 2;
	hyp = sqrt(w * w + h * h);

	px = (double) perimeter + 2 * (h + w);
	recur(px, idx + 1);

	px = (double) perimeter + 4 * (h + w2);
	recur(px, idx + 1);

	px = (double) perimeter + 4 * (h2 + w);
	recur(px, idx + 1);

	px = (double) perimeter + 2 * (h + w + hyp);
	recur(px, idx + 1);

	return;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, T = 1;
		double h, w;

		cin >> t;

		while(T <= t)
			{
				ansdiff = 100000000007;
				
				vs.clear();

				cin >> n >> p;

				for(int i = 0; i < n; i++)
					{
						cin >> h >> w;
						vs.pb(mp(h, w));
					}

				recur((double) 0, 0);

				printf("Case #%lld: %.9Lf\n", T, ans);
				T++;
			}

		return 0;
	}