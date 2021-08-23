// never the same!!
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

#define int long long
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e5 + 5;

class Solution {
public:
	int minReorder(int n, vector<vector<int>>& connections) {
		vector<vector<int>> graph(n);
		vector<bool> vis(n, false);
		map <P, int> edges;
		int cnt = 0;
		for (auto x : connections) {
			int u = x[0], v = x[1];
			edges[ {u, v}] = 1;
			graph[u].pb(v);
			graph[v].pb(u);
		}
		dfs(0, graph, vis, edges, cnt);
		return cnt;
	}
	void dfs(int src, vector<vector<int>>& graph, vector<bool>& vis,
	         map<P, int>& edges, int &cnt) {
		vis[src] = true;
		for (auto to : graph[src]) {
			if (!vis[to]) {
				if (edges[ {src, to}]) {
					cnt++;
				}
				dfs(to, graph, vis, edges, cnt);
			}
		}
	}
};

void solve() {

	int n; cin >> n;
	vector<vector<int>> edges;

	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		edges.pb({u, v});
	}
	cout << Solution().minReorder(n, edges);

	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}