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

vector<int> instd;
vector<int> instr;

int main()
	{
		int n, i, j, prev, prevd;
		string s;

		cin >> n >> s;

		for(i=0; i<n; i++)
			if(s[i]=='D')
				instd.pb(i);
			else
				instr.pb(i);

		i=0;
		j=0;
		prevr=0;
		prevd=0;

		while(true)
			{
				if(i==instr.size())
					i=prevr;
				if(i==instd.size())
					j=prevd;

				if(instr[i]<instd[j])
					{
						if(j==instd.size()-1)
							{
								cout << "R" << endl;
								exit(0);
							}
						prevd=j;
					}
				else
					{
						if(i==instr.size()-1)
							{
								cout << "D" << endl;
								exit(0);
							}
						prevr=i;
					}
				i++;
				j++;
			}

		return 0;
	}