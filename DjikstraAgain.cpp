#include <bits/stdc++.h>
using namespace std;


// longest path in matrix[0][0] -> matrix[n][n]
int longestPath(vector<vector<int>>& matrix){
  int y = matrix.size(), x = matrix[0].size();
  vector<vector<int>> mem(y, vector<int>(x, INT_MAX));
  vector<vector<bool>> visited(y, vector<bool>(x, false));
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
  vector<pair<int, int>> points = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1} 
  };

  mem[0][0] = 0;

  pq.push({0, {0, 0}});
  
  while(!pq.empty()){
    auto [dist, yx] = pq.top();
    auto [py, px] = yx;
    
    pq.pop();
    
    if (py < 0 || py >= y || px < 0 || px >= x)
      continue;
    
    visited[py][px] = true;

    for (auto& a : points){
      int ay = a.first+py, ax = a.second+px; 

      if (ay < 0 || ay >= y || ax < 0 || ax >= x || visited[ay][ax])
        continue;

      mem[ay][ax] = min(mem[ay][ax], matrix[ay][ax]+mem[py][px]);
      pq.push({mem[ay][ax], {ay, ax}});
    }
  }
  
  for (auto y : mem){
    cout << "["; 

    for (auto x : y){
      cout << x <<", ";
    }

    cout << "]" <<endl;
  }

  return mem[y-1][x-1];
}

int main(){
  vector<vector<vector<int>>> testCases = {
    {
      {-1, -3, -2},
      {-4, -2, -8},
      {-4, -5, -2}
    }
  };

  for (auto& test : testCases){
    cout << longestPath(test) << endl;
  }
  
  return 0;
}

