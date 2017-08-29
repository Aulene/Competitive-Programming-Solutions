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
#define pb push_back

map<char, int> o;

int main()
	{
		int n, i, m;
		bool ans=1;

		string s;

		cin >> n >> s;

		if(n%4!=0)
			ans=0;


		for(i=0; i<n; i++)
			{
				if(s[i]!='?')
					o[s[i]]++;
				if(o[s[i]]>n/4)
					ans=0;
			}

		for(i=0; i<n; i++)
			if(s[i]=='?')
				{
					if(o['A']<n/4)
						s[i]='A';
					else if(o['G']<n/4)
						s[i]='G';
					else if(o['C']<n/4)
						s[i]='C';
					else
						s[i]='T';
					o[s[i]]++;
				}

		if(ans)
			cout << s << endl;
		else
			cout << "===" << endl;

		return 0;
	}