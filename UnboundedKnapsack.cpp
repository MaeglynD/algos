#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(vector<int>& values, vector<int>& weights, int c){
  int mem[c+1] = {0};

  for (int i = 1; i <= c; ++i)
    for (int j = 0; j < values.size(); ++j)
      if (i >= weights[j])
        mem[i] = max(mem[i], values[j]+mem[i-weights[j]]);

  return mem[c];
}

int main(){
  vector<pair<pair<vector<int>, vector<int>>, int>> testCases = {
    {{{10,40,50,70},{1,3,4,5}}, 8}
  };

  for (auto& [vw, capacity] : testCases){
    cout << unboundedKnapsack(vw.first, vw.second, capacity) << endl;
  }

  return 0;
}




