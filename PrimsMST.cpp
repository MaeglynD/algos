#include <bits/stdc++.h>
using namespace std;

template<typename QueueT>
void addEdges(int i, vector<vector<int>> *adj, bool *visited, QueueT &pq) {
  visited[i] = true;

  for (auto& edge : adj[i]) {
    if (!visited[edge[0]]) {
      pq.push(edge);
    }
  }
}

int spanningTree(int V, vector<vector<int>> adj[]) {
  int ans = 0;
  int edgeCount = 0;
  bool visited[V];

  fill(visited, visited+V, false);

  auto cmp = [](vector<int> a, vector<int> b) {
    return a[1] > b[1]; 
  };

  priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

  addEdges(0, adj, visited, pq);

  while(!pq.empty() && edgeCount < V-1) {
    vector<int> edge = pq.top();

    pq.pop();

    if (!visited[edge[0]]) {
      ans += edge[1];
      edgeCount++;

      addEdges(edge[0], adj, visited, pq);
    }
  }

  return ans;
}

int main() {

  auto cmp = [](vector<int> a, vector<int> b) {
    return a[0] > b[0]; 
  };

  priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

  pq.push({ 0, 5});
  pq.push({ 2, 10});
  pq.push({ 9, 4});
  pq.push({ 1, 3});
  
  while (!pq.empty()) {
    auto test = pq.top();
    pq.pop();
    cout << test[0] << ", " << test[1] << endl;
  }
  // 
  return 0;
}