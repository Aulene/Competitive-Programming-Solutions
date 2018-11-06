#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int> 
#define zp mp(0, 0)

int days(int m, int y) {
	if(m == 2) {
		if(y % 4 == 0) {
			if(y % 100 == 0) {
				if(y % 400 == 0) return 29;
				return 28;
			}
			return 29;
		}
		return 28;
	}

	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
	return 30;
}

char atoi(int idx) {
	if(idx == 0) return '0';
	if(idx == 1) return '1';
	if(idx == 2) return '2';
	if(idx == 3) return '3';
	if(idx == 4) return '4';
	if(idx == 5) return '5';
	if(idx == 6) return '6';
	if(idx == 7) return '7';
	if(idx == 8) return '8';
	if(idx == 9) return '9';
}

bool isans(string s) {
	for(int i = 0; i < 6; i++) {
		if(s[i] == s[i + 1] && s[i + 1] == s[i + 2]) return 1;
	}
	return 0;
}
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v;

		cin >> n >> m;

		int d, d1, m1, y1, d2, m2, y2, ans = 0;

		d1 = n % 100;
		n /= 100;
		m1 = n % 100;
		n /= 100;
		y1 = n;

		d2 = m % 100;
		m /= 100;
		m2 = m % 100;
		m /= 100;
		y2 = m;
		

		// cout << d1 << " " << m1 << " " << y1 << endl;
		// cout << d2 << " " << m2 << " " << y2 << endl;

		while(true) {

			int mdays = days(m1, y1);

			for(d = d1; d <= mdays; d++) {

				int dx = d, m = m1, y = y1;
				string s = "";
				// cout << d << " " << m1 << " " << y1 << endl;
				
				s += atoi(y / 1000);
				y %= 1000;
				s += atoi(y / 100);
				y %= 100;
				s += atoi(y / 10);
				y %= 10;
				s += atoi(y);
				s += atoi(m / 10);
				m %= 10;
				s += atoi(m);
				s += atoi(dx / 10);
				dx %= 10;
				s += atoi(dx);

				// cout << s << endl;
				
				if(isans(s)) {
					 // cout << " " << s << " " << endl;
					 ans++;
				}
				
				if(d == d2 && m1 == m2 && y1 == y2) break;
			}

			if(d == d2 && m1 == m2 && y1 == y2) break;

			m1++;
			if(m1 == 13) {
				d1 = 1;
				m1 = 1;
				y1++;
			}

		}

		cout << ans << endl;

		return 0;
	}