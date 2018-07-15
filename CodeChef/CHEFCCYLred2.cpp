#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

const int CYCLE = 1e5 + 5;

int dC[CYCLE][3]; // dC[i] = distance i and (i+1)%n
int pathCin[CYCLE];
int pathCout[CYCLE];
 
struct Cycle {
    int vv0, vv1;
    int siz;
    vector<int> a; // a[i] = distance i and (i+1)%siz
    vector<int> sum_a;
    void init() {
        sum_a.resize(siz);
        sum_a[0] = a[0];
        for(int i = 1; i < siz; ++i)
            sum_a[i] = sum_a[i-1] + a[i];
    }
    int getD(int u, int v) {
        if(u == v) return 0;
        if(u > v) swap(u, v);
        int tmp = sum_a[v-1] - (u == 0 ? 0 : sum_a[u-1]);
        return min(tmp, sum_a[siz-1] - tmp);
    }
    int inArc() {
        return getD(vv1, vv0);
    }
};
 
Cycle C[CYCLE];
int test, n, q;
int all_sum;
 
int incycle_d(int c, int u, int v) {
    return C[c].getD(u, v);
}
 
int cycle_d(int c1, int c2, int t) {
    if(c1 > c2) swap(c1, c2);
    if(t == 0) {
        return pathCin[c2-1] - (c1 == 0 ? 0 : pathCin[c1-1]) + pathCout[c2-1] - pathCout[c1];
    } else {
        return all_sum - C[c1].inArc() - C[c2].inArc() - (pathCin[c2-1] - (c1 == 0 ? 0 : pathCin[c1-1]) + pathCout[c2-1] - pathCout[c1]);
    }
    return 0;
}
 
int main() {
    cin >> test;
    while(test--) {
        cin >> n >> q;
        int ai;
        for(int i = 0; i < n; ++i) {
            cin >> ai;
            C[i].a.resize(ai);
            C[i].siz = ai;
            for(int j = 0; j < ai; ++j)
                cin >> C[i].a[j];
            C[i].init();
        }
        all_sum = 0;
        for(int i = 0; i < n; ++i) {
            int v0, v1;
            cin >> dC[i][0] >> dC[i][1] >> dC[i][2];
            dC[i][0]--;
            dC[i][1]--;
        }
        for(int i = 0; i < n; ++i) {
            if(i == 0) {
                C[i].vv0 = dC[n-1][1];
                C[i].vv1 = dC[i][0];
            } else {
                C[i].vv0 = dC[i-1][1];
                C[i].vv1 = dC[i][0];
            }
            all_sum += C[i].inArc() + dC[i][2];
        }
        pathCout[0] = C[0].inArc();
        pathCin[0] = dC[0][2];
        for(int i = 1; i < n; ++i) {
            pathCin[i] = pathCin[i-1] + dC[i][2];
            pathCout[i] = pathCout[i-1] + C[i].inArc();
        }
 		
 		// cout << all_sum << endl;

        for(int i = 0; i < q; ++i) {
            int v1, c1, v2, c2;
            cin >> v1 >> c1 >> v2 >> c2;
            c1--; c2--;
            v1--;
            v2--;
            if(c1 > c2) {
                swap(c1, c2);
                swap(v1, v2);
            }
        	
        	// cout << incycle_d(c1, v1, C[c1].vv1)
         //                + cycle_d(c1, c2, 0)
         //                + incycle_d(c2, v2, C[c2].vv0) << " " << incycle_d(c1, v1, C[c1].vv0)
         //                + cycle_d(c1, c2, 1)
         //                + incycle_d(c2, v2, C[c2].vv1) << endl;

	        cout << incycle_d(c1, v1, C[c1].vv0)
	                    << " " << cycle_d(c1, c2, 1)
	                     << " " << incycle_d(c2, v2, C[c2].vv1) << endl;

            cout << min(incycle_d(c1, v1, C[c1].vv1)
                        + cycle_d(c1, c2, 0)
                        + incycle_d(c2, v2, C[c2].vv0),
                        incycle_d(c1, v1, C[c1].vv0)
                        + cycle_d(c1, c2, 1)
                        + incycle_d(c2, v2, C[c2].vv1)) << endl;
        }
    }
    return 0;
}