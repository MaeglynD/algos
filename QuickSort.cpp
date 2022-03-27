#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& nums, int l, int r){
  int q = l-1;

  for (int i = l; i < r; ++i) {
    if (nums[i] <= nums[r]) {
      q++;
      swap(nums[q], nums[i]);
    }
  }

  q++;
  swap(nums[q], nums[r]);

  return q;
}

void quickSort(vector<int>& nums, int l, int r){
  if (l < r) {
    int p = partition(nums, l, r);

    quickSort(nums, l, p-1);
    quickSort(nums, p+1, r);
  }
}

int main() {
  vector<vector<int>>	testCases = {
    {10, 80, 30, 90, 40, 50, 70},
    {9, 7, 5, 11, 12, 2, 14, 3, 10, 4, 6}
  };

  for (auto& test : testCases) {
    quickSort(test, 0, test.size()-1);

    for (int& x : test) {
     cout << x << ", ";
    }
    cout << endl;
  }

  return 0;
}
