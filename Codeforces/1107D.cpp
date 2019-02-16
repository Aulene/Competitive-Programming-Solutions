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
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)

const int N = 5207;
bool a[N][N], b[N][N], fugg[N][N];

void HexToBin(int idx, string hexdec) 
{ 
    int i = 0, n = hexdec.size(); 
  	// string ans = "";
  	int j = 0;

    while (i < n) { 
        switch (hexdec[i]) { 
        case '0': 
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 0; j++;
            
            // ans += "0000"; 
            break; 
        case '1': 
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 1; j++;
            
            // ans += "0001"; 
            break; 
        case '2': 
        a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 0; j++;
            
            // ans += "0010"; 
            break; 
        case '3': 
        a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 1; j++;
            
            // ans += "0011"; 
            break; 
        case '4': 
        a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 0; j++;
            
            // ans += "0100"; 
            break; 
        case '5': 
        a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 1; j++;
            
            // ans += "0101"; 
            break; 
        case '6': 
        a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 0; j++;
            
            // ans += "0110"; 
            break; 
        case '7': 
        a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 1; j++;
            
            // ans += "0111"; 
            break; 
        case '8': 
        a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 0; j++;
            
            // ans += "1000"; 
            break; 
        case '9': 
        a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 1; j++;
            
            // ans += "1001"; 
            break; 
        case 'A': 
        case 'a': 
        a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 0; j++;
            
            // ans += "1010"; 
            break; 
        case 'B': 
        case 'b': 
        a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 1; j++;
            
            // ans += "1011"; 
            break; 
        case 'C': 
        case 'c': 
        a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 0; j++;
            
            // ans += "1100"; 
            break; 
        case 'D': 
        case 'd': 
        a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 0; j++;
            a[idx][j + 1] = 1; j++;
            
            // ans += "1101"; 
            break; 
        case 'E': 
        case 'e': 
        a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 0; j++;
            
            // ans += "1110"; 
            break; 
        case 'F': 
        case 'f': 
        a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 1; j++;
            a[idx][j + 1] = 1; j++;
            
            // ans += "1111"; 
            break; 
        // default: 
            // ans += "\nInvalid hexadecimal digit "
            //      << hexdec[i]; 
        } 
        i++; 
    } 

  //   for(int j = 0; j < ans.size(); j++) 
		// if(ans[j] == '0') a[idx][j + 1] = 0;
		// else a[idx][j + 1] = 1;
} 

vi factors(int n) {
	vi fax;
	for(int i = 1; i <= sqrt(n); i++)
		if(n % i == 0) {
			if(i == sqrt(n)) fax.pb(i);
			else fax.pb(i), fax.pb(n / i);
		}
	sort(fax.begin(), fax.end(), greater <int>());
	return fax;
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
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n, m, i, j, u, v;
		string s;

		cin >> n;

		vi divs = factors(n);

		for(i = 1; i <= n; i++) {
			cin >> s;
			HexToBin(i, s);
			// cout << bs << endl;		
		}

		int ans = n;


		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				if(j + 1 <= n && a[i][j] != a[i][j + 1]) ans = gcd(ans, j);
				if(i + 1 <= n && a[i][j] != a[i + 1][j]) ans = gcd(ans, i);
			}
		}

		cout << ans << endl;

		return 0;
	}