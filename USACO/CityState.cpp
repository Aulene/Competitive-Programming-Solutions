#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>
#include<fstream>

using namespace std;

#define lli long long int
#define mod 1000000007
#define pb push_back

struct st
{
	string state;
	string code;
};

map< string, map <string, lli> > pairs;
st a[200007];

int main()
	{
		ifstream fin ("citystate.in");
		ofstream fout ("citystate.out");

		lli n, i, ans=0, u;
		string s1, s2, s;
		fin >> n;

		for(i=0; i<n; i++)
			{
				fin >> a[i].state >> a[i].code;
				a[i].state=a[i].state.substr(0, 2);
				a[i].code=a[i].code.substr(0, 2);

				pairs[a[i].state][a[i].code]++;
			}

		for(i=0; i<n; i++)
			{
				ans+=pairs[a[i].code][a[i].state];
				pairs[a[i].state][a[i].code]--;
			}

		fout << ans << endl;
		return 0;
	}