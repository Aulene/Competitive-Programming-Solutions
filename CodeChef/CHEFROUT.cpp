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

map < char, bool > enc;

int main()
	{
		int t, n, i;
		bool encC, encE, encS;

		string s;

		cin >> t;

		while(t--)
			{
				bool ans=1;

				enc.clear();

				cin >> s;
				n = s.size();

				for(i=0; i<n; i++)
					{
						//if(enc[s[i]])
							{
								if(s[i]=='C')
									{
										if(enc['S'] || enc['E'])
											ans=0;
									}
								else if(s[i]=='E')
									{
										if(enc['S'])
											ans=0;
									}
							}

						enc[s[i]]=1;
					}

				if(ans)
					cout << "yes" << endl;
				else
					cout << "no" << endl;
			}	

		return 0;
	}