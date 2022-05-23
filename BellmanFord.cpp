#include <bits/stdc++.h>
using namespace std;

bool hasNegativeCycle(int n, vector<vector<int>> edges){
  int mem[n] = {INT_MAX};

  mem[0] = 0;

  for (int i = 0; i < n-1; ++i)
    for (auto& e : edges)
      if (mem[e[0]] != INT_MAX)
        mem[e[1]] = min(mem[e[1]], e[2]+mem[e[0]]);

  for (int i = 0; i < n-1; ++i)
    for (auto& e : edges)
      if (e[2]+mem[e[0]] < mem[e[1]])
        return true;

  return false;
}

int main(){
  return 0;
}
