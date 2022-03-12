#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void printAdjList (int V, vector<int> adj[]) {
	for (int i = 0; i < V; ++i) {
		cout << i << " [";
		
		for (auto& x : adj[i]) {
			cout << x << ", ";
		}

		cout << "]" << endl;
	}
}

class Solution {
  public:
		bool dfs(int v, vector<int> *adj, bool *visited, bool* path){
    	visited[v] = true;
    	path[v] = true;
    
    	for (int& n : adj[v]) {
    		if (path[n] || (!visited[n] && dfs(n, adj, visited, path))) {
    			return true;
    		}
    
				path[n] = false;
    	}

			path[v] = false;
    
    	return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
			bool visited[V];
    	bool path[V];
    
    	fill(visited, visited+V, false);
    	fill(path, path+V, false);

			for (int i = 0; i < V; ++i) {
				if (!visited[i] && dfs(i, adj, visited, path)) {
					return true;	
				}
			}
    
    	return false;
    }
};

int main() {
	int V = 10;

	vector<pair<int, int>> test = {
		{ 6, 5 },
		{ 5, 3 },
		{ 3, 1 },
		{ 1, 2 },
		{ 2, 4 },
		{ 4, 0 },
	};

	vector<int> adj[V];

	for (auto& x : test) {
		adj[x.first].push_back(x.second);
	}

	Solution obj;
	cout << obj.isCyclic(V, adj) << "\n";

	return 0;
}