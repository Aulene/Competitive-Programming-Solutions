#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define num 2000000000

vector <string> sq;
string s;

const int m = 57;

struct TrieNode
{
    struct TrieNode *children[m];
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEndOfWord = false;
 
    for (int i = 0; i < m; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}

void insert(struct TrieNode *root, string S)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < S.size(); i++)
    {
        int index = S[i] - '0';
        if(!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
 
    pCrawl->isEndOfWord = true;
}
 
bool search(struct TrieNode *root, string S)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < S.size(); i++)
	    {
	        int index = S[i] - '0';
	        if(!pCrawl->children[index])
	            return false;
	 
	        pCrawl = pCrawl->children[index];
	    }
	 
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}


TrieNode *root;

int recur(string sp, int idx)
{
	if(idx >= s.size())
		{
			// cout << sp << " " << sp.size() << endl;
			insert(root, sp);
			return 0;
		}

	string sx = sp + s[idx];
	string sf = sp;

	recur(sx, idx + 1);
	recur(sf, idx + 1);

	return 0;
}


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, ans = -1;

		cin >> n;
		s = to_string(n);

		for(int i = 1;; i++)
			{
				if(i * i <= num) sq.pb(to_string(i * i));
				else break;
			}

		root = getNode();
		// u = '0';
		// cout << u << endl;
		// cout << sq.size() << endl;

		// cout << s << " " << s.size() << endl;
		recur("", 0);
		
		for(int i = 0; i < sq.size(); i++)
			{
				if(search(root, sq[i]))
					ans = max(ans, (int) sq[i].size());
			}

		if(ans == -1) cout << ans << endl;
		else
			{
				ans = s.size() - ans;
				cout << ans << endl;
			}

		return 0;
	}