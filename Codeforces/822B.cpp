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
		string s, t;
		lli n, m, i, j;
		lli replacedMin = 10000000;
		vector<int> ans;

		cin >> m >> n;
		cin >> s >> t;
		

		for(i = 0; i < n; i++)
			{
				lli replacedHere = 0;
				vector <int> hereAns;
				string x = "";

				if(i+m-1 < t.size())
					{
						//cout << "OPEN" << endl;
						for(j = 0; j < m; j++)
							{
								//cout << "COMPARISON BW " << t[i+j] << " AND " << s[j] << endl;
								if(t[i+j] != s[j])
									{
										hereAns.pb(j+1);
										replacedHere++;
										x+="?";
									}
								else
									x += t[j];
							}

						if(replacedHere < replacedMin)
							{
								replacedMin = replacedHere;
								ans = hereAns;
							}

						//cout << x << " " << replacedHere << endl; 
						//cout << "CLOSED" << endl;
					}
			}

		cout << replacedMin << endl;
		for(vector<int> :: iterator it = ans.begin(); it != ans.end(); it++)
			cout << *it << " ";

		return 0;
	}