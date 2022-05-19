#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transposeGraph(vector<vector<int>>& adj){
  vector<vector<int>> transposition(adj.size(), vector<int>());

  for (int i = 0; i < adj.size(); ++i)
    for (int& connection : adj[i])
      transposition[connection].push_back(i);

  return transposition;
}

int main(){
  vector<vector<int>> adj = {
    {1, 4, 3},
    {}, 
    {0},
    {2},
    {1},
    {3} 
  };

  auto res = transposeGraph(adj);

  for (auto& node : res){
    cout << "[";

    for (auto& x : node)
      cout << x << ", ";
    
    cout << "]" << endl;
  }

  return 0;
}
