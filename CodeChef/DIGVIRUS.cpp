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

map<char, bool> m;
map<int, bool> changed;

string s;

int strength(int x)
{
	int str = s[x]-'0';
	//cout << str << endl;
	return str;
}

int main()
	{
		int t, n, i, j, str;
		bool diffchars;

		cin >> t;

		while(t--)
			{
				int ans=0;
				bool diffchars=1;
				int numdiff;
				int minval, maxval;

				cin >> s;
				n=s.size();

				while(true)
					{
						numdiff=0;

						for(i=0; i<n; i++)
							if(!m[s[i]])
								{
									numdiff++;
									m[s[i]]=1;
								}

						if(numdiff < 2)
							break;

						for(i=0; i<n; i++)
							if(!changed[i])
								{
									str = s[i]-'0';

									//cout << i << " " << s[i] << endl;
									minval=min(i+str, n-1);
									maxval=max(i-str, 0);

									//cout << minval << " " << maxval << endl;

									for(j=i; j<=minval; j++)
										{
											int dist = max(j, i)-min(j, i);
											//cout << j << " " << strength(j) << endl;
											if(strength(i)-strength(j) >= dist)
												{
													//cout << i << " " << j << " " << s[i] << " " << s[j] << endl;
													s[j]=s[i];
													changed[j]=1;
												}
										}
									
									for(j=maxval; j<=i; j++)
										{
											int dist = i-j;
											if(strength(i)-strength(j) >= dist)
												{
													//cout << i << " " << j << " " << s[i] << " " << s[j] << endl;
													s[j]=s[i];
													changed[j]=1;
												}
										}
								}

						m.clear();
						changed.clear();
						cout << s << endl;
						ans++;
					}

				cout << ans << endl;
			}

		return 0;
	}