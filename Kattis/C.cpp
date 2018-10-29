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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		string s1, s2, s3, s4, s5;

		cin >> s1 >> s2 >> s3;
		cin >> s4 >> s5;

		reverse(s1.begin(), s1.end());
		reverse(s3.begin(), s2.end());
		reverse(s5.begin(), s3.end());

		for(i = 0; i < max(s1.size(), s2.size())) 
			if(i >= s3.size()) s3 += '0';

		
		return 0;
	}	