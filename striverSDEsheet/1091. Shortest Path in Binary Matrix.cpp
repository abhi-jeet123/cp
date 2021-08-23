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
	int row[8] = {0, 0, -1, 1, 1, -1, -1, 1};
	int col[8] = { -1, 1, 0, 0, 1, -1, 1, -1};

	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		return bfs(grid, visited);
	}
	int bfs(vector<vector<int>>& graph, vector<vector<bool>>& visited) {
		int n = graph.size();
		if (graph[0][0] == 1 || graph[n - 1][n - 1] == 1)
			return -1;

		vector<vector<int>> dis(n, vector<int>(n, 0));

		queue<pair<int, int>> q;
		q.push({0, 0});
		visited[0][0] = true;
		dis[0][0] = 1;
		while (!q.empty()) {
			auto x = q.front();
			q.pop();
			int curRow = x.first;
			int curCol = x.second;

			if (curRow == n - 1 && curCol == n - 1)
				return dis[n - 1][n - 1];

			for (int i = 0; i < 8; i++) {
				int r = curRow + row[i];
				int c = curCol + col[i];

				if (isValid(r, c, n) && !visited[r][c] && graph[r][c] == 0) {
					q.push({r, c});
					dis[r][c] = dis[curRow][curCol] + 1;
					visited[r][c] = true;
				}
			}
		}
		return -1;
	}
	bool isValid(int i, int j, int n) {
		return (i >= 0 && i < n && j >= 0 && j < n);
	}
};

void solve() {

	int n; cin >> n;
	vector<vector<int>> graph(n, vector<int>(n));
	REP(i, 0, n - 1)
	REP(j, 0, n - 1)
	cin >> graph[i][j];

	cout << Solution().shortestPathBinaryMatrix(graph) << endl;

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