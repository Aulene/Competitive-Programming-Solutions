#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
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
#define vpi vector < pair < set <int>, int > >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map <string, int> feature_to_num;
vector < pair < set <int>, int > > hors, verts; 
// hors = horizontal pics, verts = vert pics. 
// stored as a vector of set<int> (the types) and an int (the number of the picture)
vector < pi > cur_ans, over_ans;

int compute_min_of_three(set <int> a, set <int> b) { // computes score for two consec. slides

	set<int> intersect;
	set_intersection(a.begin(),a.end(),b.begin(),b.end(),
	                  std::inserter(intersect,intersect.begin()));

	int int_sz = (int) intersect.size();
	int d1 = ((int) a.size() - int_sz);
	int d2 = ((int) b.size() - int_sz);

	int ans = min(int_sz, d1);
	ans = min(ans, d2);
	return ans;
}

// randomized vector computation
int get_score() {
	int res = 0;

	int i = 0, j = 0;
	int h_size = (int) hors.size();
	int v_size = (int) verts.size();

	set <int> prev, cur;
	cur_ans.clear();

	while((j < v_size || i < h_size)) {

		int toss = rng() % 2;
		cur.clear();

		if(toss == 0) {
			if(i >= h_size) continue;

			cur = hors[i].f;
			cur_ans.pb({hors[i].s, -1});
			i++;

			res += compute_min_of_three(prev, cur);
			prev = cur;
		}
		else {
			if(j >= v_size) continue;

			set <int> m = verts[j].f;
			m.insert(verts[j + 1].f.begin(), verts[j + 1].f.end());

			cur_ans.pb({verts[j].s, verts[j + 1].s});
			j += 2;

			res += compute_min_of_three(prev, cur);
			prev = cur;
		}
	}

	return res;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/HCODE/a_example.txt");
		// ofstream cout ("/Users/Aulene/Desktop/HCODE/a_output.txt");

		// ifstream cin ("/Users/Aulene/Desktop/HCODE/b_lovely_landscapes.txt");
		// ofstream cout ("/Users/Aulene/Desktop/HCODE/b_output.txt");
		
		ifstream cin ("/Users/Aulene/Desktop/HCODE/c_memorable_moments.txt");
		ofstream cout ("/Users/Aulene/Desktop/HCODE/c_output.txt");
		
		// ifstream cin ("/Users/Aulene/Desktop/HCODE/d_pet_pictures.txt");
		// ofstream cout ("/Users/Aulene/Desktop/HCODE/d_output.txt");

		// ifstream cin ("/Users/Aulene/Desktop/HCODE/e_shiny_selfies.txt");
		// ofstream cout ("/Users/Aulene/Desktop/HCODE/e_output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n, m, i, j, u, v, num = 1;
		int score, ans_score = 0;
		string s;
		char hv;

		cin >> n;

		for(i = 0; i < n; i++) {
			cin >> hv >> m;

			set <int> features;

			for(j = 0; j < m; j++) {
				cin >> s;
				if(feature_to_num[s] == 0) feature_to_num[s] = num++;
				features.insert(feature_to_num[s]);
			}

			if(hv == 'H') hors.pb({features, i});
			else verts.pb({features, i});
		}

		// randomization shit, erasable
		while (clock() < 100.0 * CLOCKS_PER_SEC) {

			shuffle(hors.begin(), hors.end(), rng);
			shuffle(verts.begin(), verts.end(), rng);

			// for(auto it : hors) {
			// 	for(auto it2 : it.f) cout << it2 << " "; cout << endl;
			// }

			// for(auto it : verts) {
			// 	for(auto it2 : it.f) cout << it2 << " "; cout << endl;
			// }
		
			score = get_score();

			// cout << score << endl;

			if(score > ans_score) {
				ans_score = score;
				over_ans = cur_ans;
			}
		}

		cout << over_ans.size() << endl;
		for(i = 0; i < over_ans.size(); i++) {
			pi pz = over_ans[i];
			if(pz.s == -1) cout << pz.f << endl;
			else cout << pz.f << " " << pz.s << endl;
		}



		return 0;
	}