#include <bits/stdc++.h>
using namespace std;
using dagAdj = vector<vector<pair<int, int>>>;

void dfs(int v, vector<int>& s, dagAdj& adj, bool* visited) {
  if (visited[v]) return;

  visited[v] = true;

  for (auto& [vertex, cost] : adj[v]) {
    dfs(vertex, s, adj, visited);
  }

  s.push_back(v);
}

vector<int> topologicalSort(dagAdj& adj, int v) {
  vector<int> s;
  bool visited[v];

  fill(visited, visited+v, false);

  for (int i = 0; i < v; ++i) {
    dfs(i, s, adj, visited);
  }

  reverse(s.begin(), s.end());

  return s; 
}

vector<int> shortestPaths(dagAdj& adj, int v, int start) {
  vector<int> sorted = topologicalSort(adj, v);
  vector<int> paths(v, INT_MAX);
  int i = 0;

  while (sorted[i] != start) {
    i++;
  }

  paths[i] = 0;

  for (; i < v; ++i) {
    for (auto& [vertex, cost] : adj[sorted[i]]) {
      paths[vertex] = min(paths[vertex], paths[sorted[i]]+(cost*-1));
    }
  }

  return paths;
}

int main() {
  dagAdj adj = {
    {{1, 3}, {2, 6}},
    {{4, 11}, {3, 4}, {2, 4}},
    {{3, 8}, {6, 11}},
    {{4, -4}, {5, 5}, {6, 2}},
    {{7, 9}},
    {{7, 1}},
    {{7, 2}},
    {}
  };

  vector<int> test = shortestPaths(adj, adj.size(), 0);
  string alph = "abcdefgh";

  for (int i = 0; i < test.size(); ++i) {
    cout << alph[i] << ": " << (test[i]*-1) << endl;
  }

  return 0;
}