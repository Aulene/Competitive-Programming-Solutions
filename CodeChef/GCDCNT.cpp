#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
 
using namespace std;
// using namespace __gnu_pbds;
 
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
 
// typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set;
 
vector < vector <int> > primes(100007);
vector < order_set > divs (100007);
int a[100007];
int ans = 0;
 
void pdivs()
{
	for(int n = 2; n <= 100000; n++)
		{
			if(primes[n].size() == 0)
				{
					for(int i = n; i <= 100000; i += n)
						primes[i].pb(n);
				}
		}
}
 
void subsets(int n, int vsidx, int idx, int num)
{
    if(idx >= primes[n].size())
        {
            if(num > 1) 
                {
                    // cout << "ADDING " << num << " " << vsidx << endl;
                    divs[num].insert(vsidx);
                }
            return;
        }
    
    subsets(n, vsidx, idx + 1, num);
    subsets(n, vsidx, idx + 1, num * primes[n][idx]);
    return;
}
 
void addSubsets(int n, int idx, int vsidx, int num)
{
	if(idx >= primes[n].size()) 
		{
			if(num > 1) 
			    {
			     //   cout << "ADDING " << num << " " << vsidx << endl;
			        divs[num].insert(vsidx);
			    }
			    
			return;
		}
 
// 	cout <<  n << " " << idx << " " << primes[n][idx] << " " << num << endl;
 
	addSubsets(n, idx + 1, vsidx, num * primes[n][idx]);
	addSubsets(n, idx + 1, vsidx, num);
}
 
void removeSubsets(int n, int idx, int vsidx, int num)
{
	if(idx >= primes[n].size()) 
		{
			divs[num].erase(vsidx);
// 			cout << "REMOVING " << num << " " << vsidx << endl;
 
			return;
		}
 
 
	removeSubsets(n, idx + 1, vsidx, num * primes[n][idx]);
	removeSubsets(n, idx + 1, vsidx, num);
}
 
void findAns(int n, int idx, int num, int l, int r, int lvl)
{
	if(idx >= primes[n].size()) 
		{
			if(num == 1) return;
			
			int x = divs[num].order_of_key(r + 1) - divs[num].order_of_key(l);
			
// 			cout << num << " " << lvl << " " << x << endl;
// 			cout << divs[num].order_of_key(r + 1) << " " << divs[num].order_of_key(l) << endl;
			if(lvl % 2 == 1) ans += x;
			else ans -= x;
			return;
		}
 
	findAns(n, idx + 1, num * primes[n][idx], l, r, lvl + 1);
	findAns(n, idx + 1, num, l, r, lvl);
}
 
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
 
		pdivs();
 
		int n, m, q, i, j, l, r, g, val, pos;
 
		cin >> n;
 
		for(i = 1; i <= n; i++) cin >> a[i];
 
		for(i = 1; i <= n; i++)
			subsets(a[i], i, 0, 1);
 
		cin >> m;
 
		for(i = 1; i <= m; i++)
			{
				cin >> q;
 
				if(q == 1)
					{
						cin >> pos >> val;
                        removeSubsets(a[pos], 0, pos, 1);
                        a[pos] = val;
                        addSubsets(a[pos], 0, pos, 1);
					}
				else
					{
						ans = 0;
						cin >> l >> r >> g;
                        
                        findAns(g, 0, 1, l, r, 0);
						cout << r - l + 1 - ans << endl;
					}
			}
 
		return 0;
	} 