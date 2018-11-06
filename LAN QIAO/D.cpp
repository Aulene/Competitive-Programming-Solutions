#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int> 
#define zp mp(0, 0)
  
vector < pair <char, char> > vs;
int ansv[17];

void hanoi(int n, char fr, char tr, char r) 
{ 
    if(n == 1)  {
        vs.pb({fr, tr});
        return; 
    } 

    hanoi(n - 1, fr, r, tr);
    vs.pb({fr, tr});
    hanoi(n - 1, r, tr, fr); 
} 

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, u, v;

		cin >> n >> u >> v;

		hanoi(n, 'A', 'C', 'B'); 

		// for(auto it : vs) cout << it.f << " " << it.s << endl;
		
		for(i = u - 1; i <= v - 1; i++) {
			char x = vs[i].f, y = vs[i].s;

			if(x == 'A' && y == 'B') ansv[0]++;
			else if(x == 'A' && y == 'C') ansv[1]++;
			else if(x == 'B' && y == 'A') ansv[2]++;
			else if(x == 'B' && y == 'C') ansv[3]++;
			else if(x == 'C' && y == 'A') ansv[4]++;
			else ansv[5]++;
		}

		for(i = 0; i < 6; i++) cout << ansv[i] << endl;
		return 0;
	}