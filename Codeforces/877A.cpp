#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <string> fs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		fs.pb("Danil");
		fs.pb("Olya");
		fs.pb("Slava");
		fs.pb("Ann");
		fs.pb("Nikita");

		string s;
		int n, i, j;
		bool ansx = 1;
		int fx = 0;

		cin >> s; n = s.size();
		s = "_"+s;
		cout << s.find("Danil") << endl;
		

		if(fx == 1) cout << "YES\n";
		else cout << "NO\n";
		return 0;
	}