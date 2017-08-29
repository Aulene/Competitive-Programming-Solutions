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

int main()
	{
		lli n, m, t, i, j, len;
		lli x;
		string a;

		cin >> t;

		while(t--)
			{
				string num (100, " ");

				lli pos=100;
				lli aps=0;

				cin >> a >> n >> m;
				len=a.size();

				while(pos>0)
					{
						for(i=a.size()-1; i>=0; i--)
							{
								num[pos]=a[i];
								pos--;

								if(!pos)
									break;
							}

						if(!pos)
							break;
						aps++;
						if(aps==n)
							break;
					}

				x=stoll(num);
				//cout << num << endl;
				cout << x%m << endl;
			}

		return 0;
	}