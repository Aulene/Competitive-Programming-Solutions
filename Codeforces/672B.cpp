#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair

map <char, int> m;

int main()
	{
		int n, i, j, k = 0, ans;
		string s;

		cin >> n >> s;

		for(i = 0; i < n; i++)
			{
				m[s[i]]++;
				if(m[s[i]] > 1)
					k++;
			}

		if(n > 26)
			ans = -1;
		else
			ans = k;

		cout << ans << endl;
		return 0;
	}