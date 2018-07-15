#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

set <int> one, zero;
vector < vector <int> > ansv(200007);

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string s;
		int n, i, j, u, v, idx, prev, rem = 0;
		bool req;
		set <int> :: iterator it;

		cin >> s;

		for(i = 0; i < s.size(); i++)
			if(s[i] == '0') zero.insert(i + 1);
			else one.insert(i + 1);

		req = 0, prev = 0;
		idx = 0;

		while(!one.empty() || !zero.empty())
			{
				// cout << idx << " " << one.size() << " " << zero.size() << " " << req << endl;

				if(!one.empty() && zero.empty()) break;

				if(req == 0)
					{
						it = lower_bound(zero.begin(), zero.end(), prev);
						// cout << *it << endl;

						if(it != zero.end())
							{
								ansv[idx].pb(*it);
								zero.erase(it);
								rem++;
								prev = *it;
								req = 1;
							}
						else
							{
								idx++;
								prev = 0;
							}
					}
				else
					{
						it = lower_bound(one.begin(), one.end(), prev);
						
						// cout << *it << endl;

						if((it != one.end()))
							{
								ansv[idx].pb(*it);
								one.erase(it);
								rem++;
								prev = *it;
							}
						else
							{
								prev = 0;
								idx++;
							}

						req = 0;
					}
			}

		if(rem < s.size()) cout << -1 << endl;
		else
			{
				cout << idx + 1 << endl;
				for(int i = 0; i <= idx; i++)
					{
						cout << ansv[i].size() << " "; 
						for(int j = 0; j < ansv[i].size(); j++) cout << ansv[i][j] << " "; 
						cout << endl; 
					}
			}
		

		return 0;
	}