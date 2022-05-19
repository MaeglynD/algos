#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>>& adj){
  vector<vector<int>> tmp(adj.size());

  for (int i = 0; i < adj.size(); ++i)
    for (int& n : adj[i])
      tmp[n].push_back(i);

  adj = tmp;
}

void dfs(vector<bool>& visited, stack<int>& st, vector<vector<int>>& adj, int i){
  if (visited[i])
    return;

  visited[i] = true;

  for (int& n : adj[i])
    dfs(visited, st, adj, n);

  st.push(i);
}

void dfs2(vector<vector<int>>& components, vector<bool>& visited, vector<vector<int>>& adj, int i){
  if (visited[i])
    return;
  
  visited[i] = true;

  for (int& n : adj[i])
    dfs2(components, visited, adj, n);

  components.back().push_back(i);
}

vector<vector<int>> scc(vector<vector<int>>& adj){
  vector<vector<int>> components;
  vector<bool> visited(adj.size());
  stack<int> st;
  
  for (int i = 0; i < adj.size(); ++i)
    dfs(visited, st, adj, i);

  transpose(adj);
  fill(visited.begin(), visited.end(), false);

  while (!st.empty()){
    int i = st.top();

    st.pop();

    if (!visited[i]){
      components.push_back({});
      dfs2(components, visited, adj, i);
    }
  }
    
  return components;
}

int main(){
  vector<vector<int>> adj = {
    {2,3},
    {0},
    {1},
    {4},
    {}
  };

  auto res = scc(adj);

  for (auto& node : res){
    cout << "[";

    for (auto& x : node)
      cout << x << ", ";
    
    cout << "]" << endl;
  }

  return 0;
}
