#include <bits/stdc++.h>
using namespace std;

void dfs(int i, bool* visited, vector<int>& recStack, vector<int>* adj) {
  visited[i] = true;

  for (int& n : adj[i]) {
    if (!visited[n]) {
      dfs(n, visited, recStack, adj);
    }
  }
  
  recStack.push_back(i);
}

vector<int> topologicalSort (int V, vector<int> adj[]) {
  vector<int> recStack;
  bool visited[V];

  fill(visited, visited+V, false);

  for (int i = 0; i < V; ++i) {
    if (!visited[i]) {
      dfs(i, visited, recStack, adj);
    }
  }

  reverse(recStack.begin(), recStack.end());

  return recStack; 
}

int main() {
  // 
  return 0;
}