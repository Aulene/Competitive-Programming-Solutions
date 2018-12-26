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
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)

int block_size;

const int N = 500007;

int a[N];

map <int, int> comp;
set <int> sx[N];
multiset <int> ov;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

void remove(int idx) {

	int v = a[idx];

	auto cur = sx[v].lower_bound(idx);

	if(cur == sx[v].begin()) {
		auto rt = sx[v].upper_bound(idx);

		// cout << "OVREM " << v << " " << idx << " " << *cur << " " << *rt << endl;
		// cout << abs(*rt - *cur) << endl;
		
		auto itr = ov.find(*rt - *cur);
		if(itr != ov.end())
		    ov.erase(itr);
	}
	else {
		auto lt = cur;
		advance(lt, -1);

		// cout << "OVREM " << v << " " << idx << " " << *cur << " " << *lt << endl;
		// cout << abs(*lt - *cur) << endl;

		auto itr = ov.find(abs(*lt - *cur));
		if(itr != ov.end())
		    ov.erase(itr);
	}

	// cout << "REM " << v << " " << idx << endl;
	sx[v].erase(cur);
}

void add(int idx) {
	int v = a[idx];

	sx[v].insert(idx);
	
	// cout << "INS " << v << " " << idx << endl;

	auto cur = sx[v].lower_bound(idx);

	if(cur == sx[v].begin()) {
		auto rt = sx[v].upper_bound(idx);

		if(rt != sx[v].end() && *cur != *rt) {
			// cout << "OVINS " << v << " " << idx << " " << *cur << " " << *rt << endl;
			// cout << abs(*rt - *cur) << endl;
			ov.insert(abs(*rt - *cur));
		}
	}
	else {
		auto lt = cur;
		advance(lt, -1);

		if(*cur != *lt) {
			// cout << "OVINS " << v << " " << idx << " " << *cur << " " << *lt << endl;
			// cout << abs(*lt - *cur) << endl;
			ov.insert(abs(*lt - *cur));
		}
	}
}

int get_answer() {
	if(ov.empty())
		return -1;
	return *ov.begin();
}

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
    	// cout << "QUERY " << q.l << " " << q.r << endl;

        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
            // cout << "OV = ";
        	// for(auto it : ov) cout << it << " "; cout << endl;
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
            // cout << "OV = ";
        	// for(auto it : ov) cout << it << " "; cout << endl;
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
            // cout << "OV = ";
        	// for(auto it : ov) cout << it << " "; cout << endl;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
           	// cout << "OV = ";
        	// for(auto it : ov) cout << it << " "; cout << endl;
        }
        answers[q.idx] = get_answer();

        // cout << "OV = ";
        // for(auto it : ov) cout << it << " "; cout << endl;
    }
    return answers;
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
		
		int n, m, i, j, u, v, x = 1;
		vector <Query> qv;
		vi ansv;

		cin >> n >> m;

		block_size = sqrt(n);

		for(i = 0; i < n; i++) {
			cin >> a[i];
			if(comp[a[i]] == 0) 
				comp[a[i]] = x++;
			a[i] = comp[a[i]];
		}

		for(i = 0; i < m; i++) {
			cin >> u >> v;
			u--, v--;

			Query q;
			q.l = u, q.r = v, q.idx = i;
			qv.pb(q);
		}

		ansv = mo_s_algorithm(qv);

		for(auto it : ansv) cout << it << endl;

		return 0;
	}