#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& values, vector<int>& weights, int capacity){
  int y = values.size()+1, x = capacity+1;
  vector<vector<int>> matrix(y, vector<int>(x, 0));

  for (int i = 1; i < y; ++i){
    for (int j = 1; j < x; ++j){
      matrix[i][j] = matrix[i-1][j];

      if (j-weights[i-1] >= 0)
        matrix[i][j] = max(matrix[i][j], matrix[i-1][j-weights[i-1]]+values[i-1]);
    }
  }
  
  return matrix[y-1][x-1];
}

vector<pair<int, int>> knapsackWithValues(vector<int>& values, vector<int>& weights, int capacity){
  vector<pair<int, int>> ans;
  int y = values.size()+1, x = capacity+1;
  vector<vector<int>> matrix(y, vector<int>(x, 0));

  for (int i = 1; i < y; ++i){
    for (int j = 1; j < x; ++j){
      matrix[i][j] = matrix[i-1][j];

      if (j-weights[i-1] >= 0)
        matrix[i][j] = max(matrix[i][j], matrix[i-1][j-weights[i-1]]+values[i-1]);
    }
  }
  
  y--;
  x--;

  while (y > 0 && x > 0){
    if (matrix[y][x] != matrix[y-1][x]) {
      ans.push_back({ values[y-1], weights[y-1] });
      x-=weights[y-1];
    }

    y--;
  }

  return ans;
}

int main(){
  vector<pair<pair<vector<int>, vector<int>>, int>> testCases = {
    {{{2, 2, 4, 5, 3}, {3, 1, 3, 4, 2}}, 7}
  };

  for (auto& [vw, capacity] : testCases){
    auto res = knapsackWithValues(vw.first, vw.second, capacity);

    cout << knapsack(vw.first, vw.second, capacity) << endl;
    cout << "["; 

    for (auto& [v, w] : res){
      cout << "[" << v << ", " << w << "], ";
    }
    
    cout << "]" << endl;
  }

  return 0;
}
