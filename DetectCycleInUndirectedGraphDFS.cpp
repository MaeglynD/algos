#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, int parent, vector<int> *adj, bool *visited) {
  visited[v] = true;

  for (int& n : adj[v]) {
    if (visited[n]) {
      if (n != parent) {
        return true;
      }
    } else if (dfs(n, v, adj, visited)) {
      return true;
    }
  }

  return false;
}

bool ans(int V, vector<int> adj[]) {
  bool visited[V];

  fill(visited, visited+V, false);

  for (int i = 0; i < V; ++i) {
    if(!visited[i] && dfs(i, -1, adj, visited)) {
      return true;
    }
  }

  return false;
}

int main() {
  
  return 0;
}