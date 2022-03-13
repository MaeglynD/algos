#include <bits/stdc++.h>
using namespace std;

void dfs(int v, bool *visited, stack<int>& sortStack, vector<int> *adj) {
  visited[v] = true;

  for (int& n : adj[v]) {
    if (!visited[n]) {
      dfs(n, visited, sortStack, adj);
    }
  }

  sortStack.push(v);
}

vector<int> topologicalSort(int V, vector<int> adj[]) {
  vector<int> ans;
  stack<int> sortStack;
  bool visited[V];

  fill(visited, visited+V, false);

  for (int i = 0; i < V; ++i) {
    if (!visited[i]) {
      dfs(i, visited, sortStack, adj);
    }
  }

  while(!sortStack.empty()) {
    ans.push_back(sortStack.top());
    sortStack.pop();
  }

  return ans;
}

int main() {
  // 
  return 0;
}