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
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)

string s1, s2;
vector <int> div1, div2;

bool is_divisor(string &s, int pl)
{
	string temp = s.substr(0, pl);
	for (int i = 1; i < s.length() / pl; ++i)
		if (temp.compare(s.substr(i * pl, pl)))
			return 0;
	return 1;
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
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		cin >> s1;
		int m = s1.length();
		int y = sqrt(m);

		for (int i = 1; i <= y; ++i)
		{
			if (m % i == 0)
			{
				if (is_divisor(s1, i))
					div1.push_back(i);
				if (i != m / i && is_divisor(s1, m / i))
					div1.push_back(m / i);
			}
		}	

		cin >> s2;
		m = s2.length();
		y = sqrt(m);

		for (int i = 1; i <= y; ++i)
		{
			if (m % i == 0)
			{
				if (is_divisor(s2, i))
					div2.push_back(i);
				if (i != m/ i && is_divisor(s2, m / i))
					div2.push_back(m / i);
			}
		}

		sort(div1.begin(), div1.end());
		sort(div2.begin(), div2.end());

		int i = 0, j = 0, ans = 0;
		while (i < div1.size() && j < div2.size())
		{
			if (div1[i] < div2[j])
				++i;
			else if (div1[i] > div2[j])
				++j;
			else
			{
				if (s1.compare(0, div1[i], s2, 0, div1[i]) == 0)
					++ans;
				++i, ++j;
			}
		}

		cout << ans << '\n'; 


		return 0;
	}